/*
 * File:   dwistring_test.c
 * Author: Daniel Wieczorek
 *
 * Created on 30.05.2014, 21:02:30
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

void test_concat(void);
void test_concat(void){
	char* first = "foo";
	char* second = "bar";
	char* desiredResult = "foobar";
	char* result = concat(first, second);
	CU_ASSERT(strcmp(result, desiredResult) == 0);
	free(result);
}


void test_concat_null(void);
void test_concat_null(void){
	char* first = "foo";
	char* result = concat(first, NULL);
	CU_ASSERT_STRING_EQUAL(result, first);
	free(result);
}

void test_concat_both_null(void);
void test_concat_both_null(void){
	char* result = concat(NULL, NULL);
	CU_ASSERT(strcmp(result, "") == 0);
	free(result);
}

void test_concatall_three_values(void);
void test_concatall_three_values(void){
	char* first = "foo";
	char* second = "bar";
	char* third = "42";
	char* result = concatAll(3,first, second, third);
	CU_ASSERT(strcmp(result, "foobar42") == 0);
	free(result);
}


void test_concatall_first_null(void);
void test_concatall_first_null(void){
	char* first = NULL;
	char* second = "bar";
	char* third = "42";
	char* result = concatAll(3,first, second, third);
	CU_ASSERT(strcmp(result, "bar42") == 0);
	free(result);
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("dwistring_test", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_concat_null", test_concat_null)) ||
            (NULL == CU_add_test(pSuite, "test_concat_both_null", test_concat_both_null))||
            (NULL == CU_add_test(pSuite, "test_concat_both_null", test_concat_both_null))||
            (NULL == CU_add_test(pSuite, "test_concatall_three_values", test_concatall_three_values))||
            (NULL == CU_add_test(pSuite, "test_concatall_first_null", test_concatall_first_null))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
