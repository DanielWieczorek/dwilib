/*
 * File:   test_dwiarray.c
 * Author: Daniel Wieczorek
 *
 * Created on Dec 16, 2014, 3:12:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/dwiarray.h"
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

void test1() {
    char foo [2];
    CU_ASSERT_EQUAL(GET_NUMBER_OF_ELEMENTS(foo),2);
}

void test2() {
    CU_ASSERT(2 * 2 == 4);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("test_dwiarray", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test1", test1)) ||
            (NULL == CU_add_test(pSuite, "test2", test2))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
