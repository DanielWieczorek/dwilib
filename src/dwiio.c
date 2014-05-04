/*
 * dwiio.c
 *
 *  Created on: 03.05.2014
 *      Author: Daniel Wieczorek
 */

#include "dwiio.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "dwistring.h"
#include <unistd.h>

static const char* bannerName = "/src/dwilib.banner";

char* getBannerData();

void printBanner(void){
	char *banner = getBannerData();
	printf("%s",banner);
	free(banner);
}

char* getBannerData(){
	return readFileAsStringFully(bannerName);
}


int getFileSize(const char *filename){
	struct stat info;
	stat(filename, &info);
	return info.st_size;
}


char* getAbsolutePath(const char* relativePath){
	char basePath[1024];
	char *separator = "/";
	getcwd(basePath, sizeof(basePath));
	char *result = concatAll(3,basePath, separator, relativePath);
	return result;
}


char* readFileAsStringFully(const char *filename){
	char *data = NULL;
	if(filename != NULL){
		char *fullPath = getAbsolutePath(filename);
		int charNum = getFileSize(fullPath)+1;
		int size = sizeof(char) * charNum;
		data = calloc(charNum, sizeof(char));
		FILE *file = fopen(fullPath, "r");
		if(file != NULL)
			fread(data, size, 1, file);

		fclose(file);
		free(fullPath);
	}
	return data;
}

