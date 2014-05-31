/*
 * File:   newcunittest.c
 * Author: Daniel Wieczorek
 *
 * Created on 30.05.2014, 21:32:55
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/dwilib.h"
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void test_dwiio_read_file_as_string_relative(void);
void test_dwiio_read_file_as_string_relative(void){
	char* result = readFileAsStringFully("testdata/readfile.test");
	CU_ASSERT_STRING_EQUAL(result,"foobar");
	free(result);
}

void test_dwiio_read_file_as_string_null(void);
void test_dwiio_read_file_as_string_null(void){
	char* result = readFileAsStringFully(NULL);
	CU_ASSERT_EQUAL(result, NULL);
	free(result);
}

void test_dwiio_read_file_as_string_wrong_path(void);
void test_dwiio_read_file_as_string_wrong_path(void){
	char* result = readFileAsStringFully(NULL);
	CU_ASSERT_EQUAL(result, NULL);
	free(result);
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_dwiio_read_file_as_string_relative", test_dwiio_read_file_as_string_relative)) ||
            (NULL == CU_add_test(pSuite, "test_dwiio_read_file_as_string_null", test_dwiio_read_file_as_string_null))||
            (NULL == CU_add_test(pSuite, "test_dwiio_read_file_as_string_wrong_path", test_dwiio_read_file_as_string_wrong_path))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
