/*#include "invoker.h"

NativeArg_s nativeArg;
u64 args[30];

void setVectors() {
	while (nativeArg.vectorCount) {
		nativeArg.vectorCount--;

		vector3* argVector = nativeArg.argVectors[nativeArg.vectorCount];
		vector4 tempVector = nativeArg.tempVectors[nativeArg.vectorCount];
		argVector->x = tempVector.x;
		argVector->y = tempVector.y;
		argVector->z = tempVector.z;
	}
}

void callHash(u64 hash) {
	((void(*)(NativeArg_s*))(hash + 0x400000))(&nativeArg);
}

void resetArgs() {
	nativeArg.argCount = 0;
	nativeArg.vectorCount = 0;
	nativeArg.argValues = nativeArg.returnValue = args;
}*/

#include "invoker.h"

// Define the nativeArg and args storage
NativeArg_s nativeArg;
u64 args[30];

// Implement pushArg templates
template<typename T>
void pushArg(T value) {
    *(T*)&nativeArg.argValues[nativeArg.argCount++] = value;
}

// Implement invoke templates
template<typename N, typename... A>
N invoke(u64 hash, A... args) {
    resetArgs();
    u64 dummy[] = { (pushArg(args), 0)... };
    (void)dummy;
    callHash(hash);
    setVectors();
    if constexpr (!__is_void(N)) {
        return *(N*)nativeArg.returnValue;
    }
}

// Explicit instantiations
template void pushArg<int>(int);
template void pushArg<float>(float);
template void pushArg<u64>(u64);
template void pushArg<const char*>(const char*);

template int invoke<int, int>(u64, int);
template void invoke<void, int>(u64, int);
// Add other needed instantiations