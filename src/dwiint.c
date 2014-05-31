

#include "dwiint.h"

uint32_t getRandomUint32(void){
    uint32_t result = 0;
    
    result = (uint32_t)readBytesFromFile("/dev/random",sizeof(uint32_t));
    return result;
}

