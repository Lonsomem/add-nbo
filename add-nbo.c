#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t read_bin(char* filename) {
FILE* file;
uint32_t file_read;
uint32_t buffer[1];

file = fopen(filename, "rb");
file_read = fread(buffer, sizeof(uint32_t), sizeof(buffer), file);
uint32_t result = htonl(*buffer);
return result;
}

int main(int argc, char *argv[]) {
	uint32_t res1 = read_bin(argv[1]);
	uint32_t res2 = read_bin(argv[2]); 
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", res1, res1, res2, res2, (res1+res2), (res1+res2));

}
