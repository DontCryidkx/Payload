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

// Basis-Funktionen
void callHash(u64 hash);
void resetArgs();
void setVectors();

// Template-Deklarationen
template<typename T> void pushArg(T value);

// Makro für automatische Void-Erkennung
#define INVOKE(hash, ...) \
    sizeof(void) == sizeof(*(void(*)())hash) ? \
    invokeVoid(hash, ##__VA_ARGS__) : \
    invokeAuto(hash, ##__VA_ARGS__)

// Basis-Templates
template<typename T> T invokeAuto(u64 hash, ...);
template<typename... A> void invokeVoid(u64 hash, A... args);