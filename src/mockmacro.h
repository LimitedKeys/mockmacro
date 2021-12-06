// 2021 R
/**
 * Mock Macros
 * -----------
 *
 * Create mock funtions quickly for testing.
 *
 * Say we have the line in our code:
 *
 *     #include "test.h"
 *     uint32_t value = test(1, 2, 3);
 *
 * but we can't use the test function in unit
 * tests. So we'll write unit test version of
 * 'test.h' and include:
 *
 *     MOCK_3ARG(uint32_t, test, int, int, int);
 *
 * The retutn value can be set at runtime using:
 *
 *     test_return_value
 *
 * The value of the input args can be retrieved 
 * too:
 *
 *     test_arg1
 *     test_arg2
 *     test_arg3
 *
 * The number of times the function has been
 * called is tracked as well:
 *
 *     test_call_count
 *
 * MOCK
 * ----
 *
 * Define a test function with no arguments:
 *
 *     MOCK(int, x); -> int x(void)
 *                      x_return_value
 *                      x_call_count
 *
 * MOCK_1ARG
 * ---------
 *
 * Define a mock function with one argument
 *
 *     MOCK_1ARG(int, x); -> int x(void)
 *                           x_arg1
 *                           x_return_value
 *                           x_call_count
 *
 * MOCK_2ARG See MOCK_1ARG
 * MOCK_3ARG See MOCK_1ARG
 */

#ifndef MOCKMACRO_H_
#define MOCKMACRO_H_

#define MOCK(rt, name) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	rt name(void) { \
		name ## _call_count += 1; \
		return name ## _return_value; \
	}

#define MOCK_1ARG(rt, name, arg1_type) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	arg1_type name ## _arg1; \
	rt name(arg1_type arg1) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		return name ## _return_value; \
	}

#define MOCK_2ARG(rt, name, arg1_type, \
                            arg2_type) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	arg1_type name ## _arg1; \
	arg2_type name ## _arg2; \
	rt name(arg1_type arg1, arg2_type arg2) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		return name ## _return_value; \
	}

#define MOCK_3ARG(rt, name, arg1_type, \
                            arg2_type, \
                            arg3_type) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	arg1_type name ## _arg1; \
	arg2_type name ## _arg2; \
	arg3_type name ## _arg3; \
	rt name(arg1_type arg1, arg2_type arg2, arg3_type arg3) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		name ## _arg3 = arg3; \
		return name ## _return_value; \
	}

#define MOCK_4ARG(rt, name, arg1_type, \
                            arg2_type, \
                            arg3_type, \
                            arg4_type) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	arg1_type name ## _arg1; \
	arg2_type name ## _arg2; \
	arg3_type name ## _arg3; \
	arg4_type name ## _arg4; \
	rt name(arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		name ## _arg3 = arg3; \
		name ## _arg4 = arg4; \
		return name ## _return_value; \
	}

#endif  // MOCKMACRO_H_
