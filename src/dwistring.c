/**
 */


#include "dwistring.h"

char* concatAll(const uint32_t num, ...){
	va_list argp;
	char* result = NULL;
	char *temp = NULL;
	char *temp2 = NULL;
	unsigned int i = 0;
	va_start(argp, num);
	for(i=0;i<num;i++){
		temp = va_arg(argp, char *);
		temp2 = result;
		result = concat(result,temp);
		free(temp2);
	}
	va_end(argp);
	return result;
}

char* concat(const char* first, const char* second){
	int targetLen =  getStringLength(first) + getStringLength(second) + 1;
	char *target = calloc(targetLen,sizeof(char));
	if(target != NULL){
		if(first != NULL)
			strcat(target,first);
		if(second != NULL)
			strcat(target,second);
	}
	return target;
}


size_t getStringLength(const char* string){
	return string != NULL ? strlen(string) : 0;
}
