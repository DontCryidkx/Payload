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

// Storage
NativeArg_s nativeArg;
u64 args[30];

// Base Implementations
void callHash(u64 hash) { /* existing impl */ }
void resetArgs() { /* existing impl */ }
void setVectors() { /* existing impl */ }

// Push Argument (all types)
template<typename T>
void pushArg(T value) {
    *(T*)&nativeArg.argValues[nativeArg.argCount++] = value;
}

// Non-void Invoke
template<typename Ret, typename... Args>
Ret invoke(u64 hash, Args... args) {
    resetArgs();
    u64 dummy[] = { (pushArg(args), 0)... };
    (void)dummy;
    callHash(hash);
    setVectors();
    return *(Ret*)nativeArg.returnValue;
}

// Void Invoke
template<typename... Args>
void invokeVoid(u64 hash, Args... args) {
    resetArgs();
    u64 dummy[] = { (pushArg(args), 0)... };
    (void)dummy;
    callHash(hash);
    setVectors();
}

// Explicit Instantiations
template void pushArg<int>(int);
template void pushArg<float>(float);
template void pushArg<const char*>(const char*);

template int invoke<int, int>(u64, int);
template void invokeVoid<int>(u64, int);