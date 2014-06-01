

#include "dwistring.h"

/**
 * @brief concatenates the first num strings (char *) that are given via the parameter list.
 *
 * A string at a new address will be returned. So an assignment will be necessary.
 * the given number is expected to be correct. Errors or crashes may occur otherwise.
 * If strings are NULL they are ignored
 *
 * @param num number of strings to concatenate
 * @param ... the list of strings
 *
 * @return a new pointer to the concatenation of the first num strings.
 */
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


/**
 * @brief concatenates two strings (char *) that are given via the parameter list.
 *
 * A string at a new address will be returned. So an assignment will be necessary.
 * If one of the string is NULL it will be ignored.
 *
 * @param first string the result starts with
 * @param second string that is appended to first
 *
 * @return a new pointer to the concatenation of the first num strings. If parameters are null an empty string is returned. If the allocation of the memory fails NULL is returned.
 */
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

/**
 * @brief Wrapper for strlen that does not crash on NULL
 *
 * returns the result of strlen(string) if the input string is not null. 0 is returned otherwise.
 *
 * @param string the string the length is calculated of.
 * @returns 0 if the input is NULL, strlen(string) otherwise.
 *
 */
size_t getStringLength(const char* string){
	return string != NULL ? strlen(string) : 0;
}


/**
 * @brief Checks if the given string contains the given character
 *
 * returns the result of strlen(string) if the input string is not null. 0 is returned otherwise.
 *
 * @param string string to search in.
 * @param searched character to search in the string
 * @returns true if the character was found in the string. False is returned otherwise.
 *
 */
bool containsChar(const char* string, const char searched){
    int i=0;
    size_t characterNum = getStringLength(string); 
    bool result = false;
    for(i=0;characterNum;i++)
        if(string[i] == searched){
            result = true;
            break;
        }
    
    return result;
            
}