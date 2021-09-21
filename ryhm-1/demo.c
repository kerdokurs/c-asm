#include <stdio.h>
#include <stdint.h>

// #include "libra.h"
// #include "libra.h"

// 1. Structid
// 2. Enumid
// 3. Unionid

#define UUS_TEHE(nimi, tehe)   \
	int nimi(int a, int b) \
	{		       \
		return a tehe b;  \
	}

UUS_TEHE(liida, +)
UUS_TEHE(lahuta, -)
UUS_TEHE(korruta, *)
UUS_TEHE(jaga, /)

typedef struct
{
	char nimi[50];
	int vanus;
} inimene_t;

typedef enum
{
	NORTH,
	EAST,
	SOUTH,
	WEST
} Direction;

typedef enum
{
	OK = 0,
	FILE_ERROR,
	INVALID_ERROR = 127
} Error;

typedef struct
{
	inimene_t value;
} node_t;

typedef union
{
	int x;
	char c[4];
} packet_u;

typedef union
{
	uint32_t code;
	uint8_t os_error;
	uint8_t app_error;
} error_t;

#define ENNIK \
	X(a)  \
	X(b)  \
	X(c)

#ifdef WIN32
  #define NIMI "Windows"
#elif defined(__linux__)
  #define NIMI "Linux"
#elif defined (__OSX__)
  #define NIMI "OSX"
#else
  #error Platform not supported
#endif

#define DEBUG_LEVEL 1

#ifdef DEBUG
# define DEBUG_LOG(X) printf("DEBUG: %s\n", X)
#else
# define DEBUG_LOG
#endif

int main() {
	inimene_t joonas = {
		.nimi = "Joonas",
		.vanus = 17
	};
	printf("%s on %d aastat vana\n", joonas.nimi, joonas.vanus);
	joonas.vanus = 24;
	printf("%s on %d aastat vana\n", joonas.nimi, joonas.vanus);

	printf("%d %d %d %d\n", NORTH, EAST, SOUTH, WEST);

	Direction dir = SOUTH;
	switch (dir) {
		case NORTH:
			printf("north\n");
			break;
		case SOUTH:
			printf("south\n");
			break;
	}

	packet_u packet;
	packet.x = 65;

	// 0 0 0 65 <- x
	// 0 0 0  A <- c

	packet.x = 0x4142;

	// 0 0 64 65 <- x
	// 0 0  B  A <- c

	printf("%d %s\n", packet.x, packet.c);

	printf("%d\n", liida(1, 2));
	printf("%d\n", lahuta(1, 2));
	printf("%d\n", korruta(1, 2));
	printf("%d\n", jaga(1, 2));

#if (DEBUG_LEVEL > 6)
	printf("DEBUG LEVEL > 6\n");
#elif (DEBUG_LEVEL > 4)
	printf("DEBUG LEVEL IN (4, 6]\n");
#else
	printf("DEBUG LEVEL INVALID\n");
#endif

#define X(var) int var;

	ENNIK;

	a = 5;
	b = 6;
	c = -1;

	printf("%d %d %d\n", a, b, c);
	
#undef X

	DEBUG_LOG("test");
}
