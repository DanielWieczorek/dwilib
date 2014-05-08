/*
 * dwiio.h
 *
 *  Created on: 03.05.2014
 *      Author: Daniel Wieczorek
 */

#ifndef DWIIO_H_
#define DWIIO_H_
#include "dwilib.h"

void printBanner(void);
off_t getFileSize(const char *filename);
char* getAbsolutePath(const char* relativePath);
char* readFileAsStringFully(const char *filename);
#endif /* DWIIO_H_ */
