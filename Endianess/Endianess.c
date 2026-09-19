#include <stdint.h>
#include <stdio.h>

uint8_t is_little_endian() {
	uint16_t variable = 0x001;
	return *(uint8_t*)&variable;
}

uint8_t is_big_endian() {
	uint16_t variable = 0x100;
	return *(uint8_t*)&variable;
}

int main() {
	printf(
		"Little endian: %d\nBig endian: %d\n",
		(int)is_little_endian(),
		(int)is_big_endian()
	);
}
