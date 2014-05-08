

#include "dwiio.h"

static const char* bannerName = "src/dwilib.banner";

char* getBannerData();

/**
 * @brief Prints a fancy ANSI banner with the name of this lib.
 *
 * Not the most useful function but I was in the mood to do some ANSI art.
 * And it was a good way to test file io. :)
 *
 */
void printBanner(void){
	char *banner = getBannerData();
	printf("%s",banner);
	free(banner);
}

/**
 * @brief reads the banner from the file that whose location is specified by the global constant bannerName.
 *
 * @return the text of the fancy banner
 */
char* getBannerData(){
	return readFileAsStringFully(bannerName);
}


/**
 * @brief retrieves the size of the given file in bytes.
 *
 * Not the most useful function but I was in the mood to do some ANSI art.
 * And it was a good way to test file io. :)
 *
 * @param filename name of the file to retrieve the size of.
 *
 * @return size of the given file in bytes, or 0 if the filename is NULL
 */
off_t getFileSize(const char *filename){
	off_t result = 0;
	if(filename != NULL){
		struct stat info;
		stat(filename, &info);
		result = info.st_size;
	}
	return result;
}

/**
 * @brief converts the relative path into an absolute path using getcwd()
 *
 * It is assumed that the input path is absolute, if it starts with a slash and is relative without it.
 * The operation that is done ist essentially:
 * 		getcwd + / + relativePath
 *
 * @param relativePath name of the file to retrieve the size of.
 * @return returns the absoulute path, NULL if the given path is NULL or a new instance of the relativePath if it stats with a slash
 */
char* getAbsolutePath(const char* relativePath){
	char *result = NULL;
	if(relativePath != NULL){
		if(relativePath[0] != '/'){
			char basePath[1024];
			char *separator = "/";
			getcwd(basePath, sizeof(basePath));
			result = concatAll(3,basePath, separator, relativePath);
		}
		else
			result = concat(relativePath,NULL);
	}
	return result;
}

/**
 * @brief reads the file completely and returns it's content.
 *
 * @param filename name of to read from. The path can be relative or absolute.
 * @return returns the contents of the given file NULL if the given filename is NULL or an empty string if the file was not found.
 */
char* readFileAsStringFully(const char *filename){
	char *data = NULL;
	if(filename != NULL){
		char *fullPath = getAbsolutePath(filename);
		off_t charNum = getFileSize(fullPath)+1;
		off_t size = sizeof(char) * charNum;
		data = calloc(charNum, sizeof(char));
		FILE *file = fopen(fullPath, "r");
		if(file != NULL)
			fread(data, size, 1, file);

		fclose(file);
		free(fullPath);
	}
	return data;
}

