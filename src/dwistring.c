/**
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "dwistring.h"

char* concatAll(const int num, ...){
	va_list argp;
	char* result = NULL;
	char *temp;
	int i = 0;
	va_start(argp, num);
	for(i=0;i<num;i++){
		temp = va_arg(argp, char *);
		result = concat(result,temp);
	}
	va_end(argp);
	return result;
}

char* concat(const char* first, const char* second){
	int targetLen =  getStringLength(first) + getStringLength(second) + 1;
	char *target = createEmptyString(targetLen);
	if(target != NULL){
		if(first != NULL)
			strcat(target,first);
		if(second != NULL)
			strcat(target,second);
	}
	return target;
}


int getStringLength(const char* string){
	return string != NULL ? strlen(string) : 0;
}

char* createEmptyString(const int characterNum){
	int memoryLength = sizeof(char) * characterNum;
	char *target = malloc(memoryLength);
	memset(target,0,memoryLength);
	return target;
}
