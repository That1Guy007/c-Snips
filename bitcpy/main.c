#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> // For # of bits in CHAR_BIT Macro
#include <stdint.h> // SIZE_MAX for max size of size_t .. minimum is 16 bits

void* myBitCopy(void* toLocation, const void* fromLocation, int len_of_mem_to_copy) {
    size_t numOfBytes = len_of_mem_to_copy / 8; 
    int paddingRequired = len_of_mem_to_copy % 8;
    
// We need to perform bitwise operations inorder to copy at the bit level.
//abcd
//0110:0001-0110:0010-0110:0011-0110:0100 -> 0110:0001-0110:0010-0110:0011-0110:0000 Copied 28 bits with a 4 bit 0000 padding
//Is the padding the best way to handle the ending information?
}

int main() {
    char* characterString = "Th1s 1s 4 Ch4r STRING";
    char* toLoc = (char* ) malloc(sizeof(characterString));
    memcpy(toLoc, characterString, strlen(characterString));
    printf("%s : %d characters : %d bytes : %d Char_bit Size\n", toLoc, strlen(characterString), sizeof(characterString), CHAR_BIT);
    free(toLoc);
    return (0);
}