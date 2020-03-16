#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* myBitCopy(void* toLocation, const void* fromLocation, int len_of_mem_to_copy) {
    size_t numOfBytes = len_of_mem_to_copy / 8; 
    int paddingRequired = len_of_mem_to_copy % 8;
    
    //I need to think about how we handle not just strings and if there any cases that need to be handled for my implementation of memcpy
    
}

int main() {
    char* characterString = "Th1s 1s 4 Ch4r STRING";
    char* toLoc = (char* ) malloc(sizeof(characterString));
    memcpy(toLoc, characterString, strlen(characterString));
    printf("%s : %d characters : %d bytes\n", toLoc, strlen(characterString), sizeof(characterString));
    free(toLoc);
    return (0);
}