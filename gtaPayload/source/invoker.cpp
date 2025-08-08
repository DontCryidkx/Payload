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

NativeArg_s nativeArg;
u64 args[30];

// Basis-Implementierungen
void callHash(u64 hash) {
    ((void(*)(NativeArg_s*))(hash + 0x400000))(&nativeArg);
}

void resetArgs() {
    nativeArg.argCount = nativeArg.vectorCount = 0;
    nativeArg.argValues = nativeArg.returnValue = args;
}

void setVectors() {
    while (nativeArg.vectorCount) {
        nativeArg.vectorCount--;
        vector3* v = nativeArg.argVectors[nativeArg.vectorCount];
        vector4 t = nativeArg.tempVectors[nativeArg.vectorCount];
        v->x = t.x; v->y = t.y; v->z = t.z;
    }
}

// Template-Implementierungen
template<typename T>
void pushArg(T value) {
    *(T*)&nativeArg.argValues[nativeArg.argCount++] = value;
}

// Spezialisierte Implementierung
template<typename... A>
void invokeVoid(u64 hash, A... args) {
    resetArgs();
    u64 dummy[] = { (pushArg(args), 0)... };
    callHash(hash);
    setVectors();
}

// Allgemeine Implementierung
template<typename T>
T invokeAuto(u64 hash, ...) {
    va_list args;
    va_start(args, hash);
    resetArgs();
    
    // Manuelle Parameterverarbeitung
    while(...) { // Hier tatsächliche Parameterverarbeitung einfügen
        pushArg(va_arg(args, /* Typ */));
    }
    
    va_end(args);
    callHash(hash);
    setVectors();
    return *(T*)nativeArg.returnValue;
}

// Explizite Instanziierungen
template void pushArg<int>(int);
template void pushArg<float>(float);
template void pushArg<u64>(u64);
template void pushArg<const char*>(const char*);

template int invoke<int, int>(u64, int);
template void invokeVoid<int>(u64, int);