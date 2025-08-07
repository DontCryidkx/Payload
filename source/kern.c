#include "kern.h"

#define VM_PROT_READ 0x01/* read permission */
#define VM_PROT_WRITE 0x02/* write permission */
#define VM_PROT_EXECUTE 0x04/* execute permission */
#define VM_PROT_DEFAULT (VM_PROT_READ | VM_PROT_WRITE)
#define VM_PROT_ALL (VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE)

Inline uint8_t * getKernelBase()
{
    uint32_t lo, hi;

    __asm__ __volatile__ ("rdmsr" : "=a" (lo), "=d" (hi) : "c" (0xC0000082));
    return (uint8_t *) (((uint64_t) lo | ((uint64_t) hi << 32)) - KERN_XFAST_SYSCALL);
    //*(unsigned char *) (getKernelBase + 0x1BD800D) = 0x80;
}

int kernelPayload(struct thread *td, void* uap) {
	uint8_t* ptrKernel = getKernelBase();
	struct ucred* cred = td->td_proc->p_ucred;
	struct filedesc* fd = td->td_proc->p_fd;

	// Escalate privileges
	cred->cr_uid = 0;
	cred->cr_ruid = 0;
	cred->cr_rgid = 0;
	cred->cr_groups[0] = 0;

	// Escape sandbox
	void** prison0 = (void**)&ptrKernel[KERN_PRISON_0];
	void** rootvnode = (void**)&ptrKernel[KERN_ROOTVNODE];
	cred->cr_prison = *prison0;
	fd->fd_rdir = fd->fd_jdir = *rootvnode;

	void *td_ucred = *(void **)(((char *)td) + 304); // p_ucred == td_ucred

	// sceSblACMgrIsSystemUcred
	uint64_t *sonyCred = (uint64_t *)(((char *)td_ucred) + 96);
	*sonyCred = 0xffffffffffffffff;

	// sceSblACMgrGetDeviceAccessType
	uint64_t *sceProcType = (uint64_t *)(((char *)td_ucred) + 88);
	*sceProcType = 0x3801000000000013; // Max access

	// sceSblACMgrHasSceProcessCapability
	uint64_t *sceProcCap = (uint64_t *)(((char *)td_ucred) + 104);
	*sceProcCap = 0xffffffffffffffff; // Sce Process

	// Disable write protection
	uint64_t cr0 = readCr0();
	writeCr0(cr0 & ~X86_CR0_WP);

    //patch memcpy first 9.00
    *(uint8_t *)(ptrKernel + 0x2713FD) = 0xEB;//9

    // patch sceSblACMgrIsAllowedSystemLevelDebugging
    memcpy((void *)(ptrKernel + 0x8BC20), "\x48\xC7\xC0\x01\x00\x00\x00\xC3", 8);

    // patch sceSblACMgrHasMmapSelfCapability
    memcpy((void *)(ptrKernel + 0x8BC90), "\x48\xC7\xC0\x01\x00\x00\x00\xC3", 8);

    // patch sceSblACMgrIsAllowedToMmapSelf
    memcpy((void *)(ptrKernel + 0x8BCB0), "\x48\xC7\xC0\x01\x00\x00\x00\xC3", 8);

    // disable sysdump_perform_dump_on_fatal_trap
    // will continue execution and give more information on crash, such as rip
    *(uint8_t *)(ptrKernel + 0x00767E30) = 0xC3;

    // self patches
    memcpy((void *)(ptrKernel + 0x168051), "\x31\xC0\x90\x90\x90", 5);

    // patch ptrace
    ptrKernel[KERN_PTRACE_CHECK] = 0xEB;//9
    memcpy((void *)(ptrKernel + 0x41F9D1), "\xE9\x7C\x02\x00\x00", 5);//9

    // Disable process aslr
    *(uint16_t*)&ptrKernel[KERN_PROCESS_ASLR] = 0x9090;//9

    // patch kmem_alloc
    *(uint8_t *)(ptrKernel + 0x37BF3C) = VM_PROT_ALL;
    *(uint8_t *)(ptrKernel + 0x37BF44) = VM_PROT_ALL;

	// Enable write protection
	writeCr0(cr0);

	return 0;
}