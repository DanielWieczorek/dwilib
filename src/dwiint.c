

#include "dwiint.h"

/**
 * @brief reads 32 bit from /dev/random and converts them to an int
 *
 * @return returns the int that was read from /dev/random
 */
uint32_t getRandomUint32(void){
    uint32_t result = 0;
    
    result = (uint32_t)readBytesFromFile("/dev/random",sizeof(uint32_t));
    return result;
}

