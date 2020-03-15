#include <stdio.h>

void* myBitCopy(void* toLocation, const void* fromLocation, size_t numOfBits) {
    size_t numOfBytes = numOfBits / 8; // what is size_t
    int paddingRequired = numOfBits % 8;
}

int main() {
    printf("wtfd\n");
}