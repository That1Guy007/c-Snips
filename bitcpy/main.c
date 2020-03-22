#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> // For # of bits in CHAR_BIT Macro
#include <stdint.h> // SIZE_MAX for max size of size_t .. minimum is 16 bits

void* myBitCopy(void* toLocation, const void* fromLocation, int len_of_mem_to_copy) {
    size_t numOfBytes = len_of_mem_to_copy / 8; 
    int paddingRequired = len_of_mem_to_copy % 8;
    int shift = 8 - paddingRequired;
    char* startingBlock = (char * ) fromLocation;
    char* newBlock = (char * ) toLocation;
    for( int i =0; i < numOfBytes ; i ++){
        newBlock[i] = startingBlock[i];
    }
    if( paddingRequired ){
        printf("Padding needed -- %d num of bytes -- %d padding required \n", numOfBytes , paddingRequired);
        newBlock[numOfBytes] = (startingBlock[numOfBytes] >> shift) << shift;
    }
    // We need to perform bitwise operations inorder to copy at the bit level.
    //abcd
    //0110:0001-0110:0010-0110:0011-0110:0100 -> 0110:0001-0110:0010-0110:0011-0110:0000 Copied 28 bits with a 4 bit 0000 padding
    // double shift to get rid of excess information
}

int main() {
    char* characterString = "abcc";
    char* toLoc1 = (char* ) malloc(strlen(characterString) * sizeof(char));
    char* toLoc2 = (char* ) malloc(strlen(characterString) * sizeof(char));
    memcpy(toLoc1, characterString, strlen(characterString));
    printf("%s : %d characters : %d bytes : %d Char_bit Size\n", toLoc1, strlen(toLoc1), sizeof(toLoc1), CHAR_BIT);
    free(toLoc1);
    myBitCopy(toLoc2, characterString, 8);
    printf("%s : My memcopy()  -- %d : string length -- %d : bytes of X\n", toLoc2, strlen(toLoc2), sizeof(toLoc2));
    free(toLoc2);
    
    return (0);
}