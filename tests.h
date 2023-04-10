#ifndef TESTS_H
#define TESTS_H
#include "cipher.h"

/// DO NOT CHANGE ANYTHING IN THIS FILE.



/**
 * Tests non-cyclic encode with lower case string and positive k=3.
 * @return 0 upon success.
 */
int test_encode_non_cyclic_lower_case_positive_k ();

/**
 * Tests cyclic encode with lower case string that include special character
 * and positive k=2.
 * @return 0 upon success.
 */
int test_encode_cyclic_lower_case_special_char_positive_k ();

/**
 * Tests non-cyclic encode with lower case string that include
 * special character and negative k=-1.
 * @return 0 upon success.
 */
int test_encode_non_cyclic_lower_case_special_char_negative_k ();

/**
 * Tests cyclic encode with lower case string and negative k=-3.
 * @return 0 upon success
 */
int test_encode_cyclic_lower_case_negative_k ();

/**
 * Tests cyclic encode with upper case string and positive k=29.
 * @return 0 upon success.
 */
int test_encode_cyclic_upper_case_positive_k ();

/**
 * Tests non-cyclic decode with lower case string and positive k=3.
 * @return 0 upon success.
 */
int test_decode_non_cyclic_lower_case_positive_k ();

/**
 * Tests cyclic decode with lower case string that include special character
 * and positive k=2.
 * @return 0 upon success.
 */
int test_decode_cyclic_lower_case_special_char_positive_k ();

/**
 * Tests non-cyclic decode with lower case string that include
 * special character and negative k=-1.
 * @return 0 upon success.
 */
int test_decode_non_cyclic_lower_case_special_char_negative_k ();

/**
 * Tests cyclic decode with lower case string and negative k=-3.
 * @return 0 upon success
 */
int test_decode_cyclic_lower_case_negative_k ();

/**
 * Tests cyclic decode with upper case string and positive k=29.
 * @return 0 upon success.
 */
int test_decode_cyclic_upper_case_positive_k ();

#endif //TESTS_H
