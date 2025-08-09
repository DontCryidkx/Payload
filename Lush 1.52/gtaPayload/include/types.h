#define NULL 0
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned long int size_t;
typedef void *PVOID;
typedef unsigned long DWORD;
typedef char CHAR;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef int BOOL;
typedef float FLOAT;
typedef CHAR *PCHAR;
typedef unsigned short WORD;
typedef DWORD *PDWORD;
typedef void* Void;
typedef int Any;
typedef unsigned int uint;
typedef int Hash;
typedef int BOOL;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

typedef struct {
	float x, y;
} vector2;

typedef struct {
	float x, _padX, y, _padY, z, _padZ;
} vector3;

typedef struct {
	float x, y, z, w;
} vector4;


#define Vector2(x, y) (vector2){x, y}
#define Vector3(x,y,z) (vector3){x,0,y,0,z,0}


typedef struct {
	int r, g, b, a;
} Color;