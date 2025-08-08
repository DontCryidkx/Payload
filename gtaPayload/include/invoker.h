/*#pragma once
#include "types.h"
#include <utility>

struct NativeArg_s {
	u64* returnValue;
	u32 argCount;
	u8 padding1[4];
	u64* argValues;
	u32 vectorCount;
	u8 padding2[4];
	vector3* argVectors[4];
	vector4 tempVectors[4];
};

extern NativeArg_s nativeArg;

void callHash(u64 hash);
void resetArgs();
void setVectors();

template<typename T>
inline void pushArg(T value) {
	*(T*)&nativeArg.argValues[nativeArg.argCount] = value;
	nativeArg.argCount++;
}

template<typename R>
inline R getReturn() {
	return *(R*)&nativeArg.returnValue[0];
}

template<typename N, typename... A>
N invoke(u64 hash, A &&... args)
{
	resetArgs();
	int dummy[] = { 0, ((void)pushArg(std::forward<A>(args)), 0) ... };
	callHash(hash);
	setVectors();
	return getReturn<N>();
}*/

#pragma once
#include "types.h"

// Native Argument Structure
struct NativeArg_s {
    u64* returnValue;
    u32 argCount;
    u64* argValues;
    // ... (rest of your existing struct)
};

extern NativeArg_s nativeArg;

// Base Functions
void callHash(u64 hash);
void resetArgs();
void setVectors();

// Template Declarations
template<typename T> void pushArg(T value);

// Non-void Invoke
template<typename Ret, typename... Args>
Ret invoke(u64 hash, Args... args);

// Void Invoke (specialized)
template<typename... Args>
void invokeVoid(u64 hash, Args... args);