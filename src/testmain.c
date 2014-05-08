/*
 * testmain.c
 *
 *  Created on: 03.05.2014
 *      Author: Daniel Wieczorek
 */
#include "dwilib.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_dwistring_concat(void);
void test_dwistring_concat(void){
	char* first = "foo";
	char* second = "bar";
	char* desiredResult = "foobar";
	char* result = concat(first, second);
	assert(strcmp(result, desiredResult) == 0);
	free(result);
}


void test_dwistring_concat_null(void);
void test_dwistring_concat_null(void){
	char* first = "foo";
	char* result = concat(first, NULL);
	assert(strcmp(result, first) == 0);
	free(result);
}

void test_dwistring_concat_both_null(void);
void test_dwistring_concat_both_null(void){
	char* result = concat(NULL, NULL);
	assert(strcmp(result, "") == 0);
	free(result);
}

void test_dwistring_concatall_three_values(void);
void test_dwistring_concatall_three_values(void){
	char* first = "foo";
	char* second = "bar";
	char* third = "42";
	char* result = concatAll(3,first, second, third);
	assert(strcmp(result, "foobar42") == 0);
	free(result);
}


void test_dwistring_concatall_first_null(void);
void test_dwistring_concatall_first_null(void){
	char* first = NULL;
	char* second = "bar";
	char* third = "42";
	char* result = concatAll(3,first, second, third);
	assert(strcmp(result, "bar42") == 0);
	free(result);
}

void test_dwiio_read_file_as_string_relative(void);
void test_dwiio_read_file_as_string_relative(void){
	char* result = readFileAsStringFully("testdata/readfile.test");
	assert(strcmp(result,"foobar") == 0);
	free(result);
}

void test_dwiio_read_file_as_string_null(void);
void test_dwiio_read_file_as_string_null(void){
	char* result = readFileAsStringFully(NULL);
	assert(result == NULL);
	free(result);
}

void test_dwiio_read_file_as_string_wrong_path(void);
void test_dwiio_read_file_as_string_wrong_path(void){
	char* result = readFileAsStringFully(NULL);
	assert(result == NULL);
	free(result);
}


int main(void){
	printBanner();
	test_dwistring_concat();
	test_dwistring_concat_null();
	test_dwistring_concat_both_null();
	test_dwistring_concatall_first_null();
	test_dwistring_concatall_three_values();
	test_dwiio_read_file_as_string_relative();
	test_dwiio_read_file_as_string_null();
	test_dwiio_read_file_as_string_wrong_path();
}
