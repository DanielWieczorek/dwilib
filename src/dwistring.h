/*
 * dwi_string.h
 *
 *  Created on: 03.05.2014
 *      Author: Daniel Wieczorek
 */

#ifndef DWI_STRING_H_
#define DWI_STRING_H_

char* concat(const char* first, const char* second);
int getStringLength(const char* string);
char* createEmptyString(const int characterNum);
char* concatAll(const int num, ...);
#endif /* DWI_STRING_H_ */
