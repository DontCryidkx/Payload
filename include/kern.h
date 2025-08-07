#pragma once

#include "type.h"
#include "ps4.h"

#define	KERN_XFAST_SYSCALL K900_XFAST_SYSCALL
#define KERN_PROCESS_ASLR  0x5F824//9
#define KERN_PRISON_0      K900_PRISON_0
#define KERN_ROOTVNODE     K900_ROOTVNODE
#define KERN_PTRACE_CHECK  0x41F4E5//9

#define X86_CR0_WP (1 << 16)

int kernelPayload(struct thread *td, void* uap);