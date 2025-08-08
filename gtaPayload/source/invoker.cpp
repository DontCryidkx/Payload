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

// Explizite Instanziierungen für alle verwendeten Typkombinationen
template void pushArg<int>(int);
template void pushArg<float>(float);
template void pushArg<u64>(u64);
template void pushArg<const char*>(const char*);
template void pushArg<vector3>(vector3);
template void pushArg<vector4>(vector4);

// Instanziierungen für invoke()
template int invoke<int>(u64);
template int invoke<int, int>(u64, int);
template int invoke<int, int, int>(u64, int, int);
template float invoke<float, int>(u64, int);
template vector3 invoke<vector3, int, int>(u64, int, int);
template bool invoke<bool, int>(u64, int);

// Instanziierungen für invokeVoid()
template void invokeVoid<>(u64);
template void invokeVoid<int>(u64, int);
template void invokeVoid<int, int>(u64, int, int);
template void invokeVoid<const char*, const char*>(u64, const char*, const char*);
template void invokeVoid<int, float, float, float>(u64, int, float, float, float);