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
 * The (XARG) versions if this Macro provide the
 * ability to mock functions with input
 * arguments. 
 *
 * To define a mock function with one argument
 *
 *     MOCK_1ARG(int, x); -> int x(void)
 *                           x_arg1
 *                           x_return_value
 *                           x_call_count
 *
 * See:
 *
 * - MOCK
 * - MOCK_1ARG
 * - MOCK_2ARG
 * - MOCK_3ARG
 * - MOCK_4ARG
 *
 * MOCK_CB
 * -------
 *
 * Define a mock function, which calls the 
 * provided callback when called. Call count and
 * return value globals are still available
 *
 * 	MOCK_CB(int, x, cb) -> x_call_count
 *                             x_return_value
 *                             call cb()
 *
 * Related:
 *
 * - MOCK_CB
 * - MOCK_ARG1_CB
 * - MOCK_ARG2_CB
 * - MOCK_ARG3_CB
 * - MOCK_ARG4_CB
 *
 * MOCK_SE
 * -------
 *
 * Define a mock function, which calls the 
 * provided side effect function with the 
 * function arguments.
 *
 * The value returned from the side effect will
 * be returned.
 *
 * The side effect function should have the same
 * function signiture of the mocked function.
 *
 * 	MOCK_SE(int, x, se) -> return se()
 *                             x_call_count
 *
 * Mocking with args and a side effect is 
 * available as well
 *
 * 	MOCK_1ARGS_SE(int, x, int, se) ->
 *                           return se(x_arg1)
 *                           x_call_count
 *                           x_arg1
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

#define MOCK_CB(rt, name, cb) \
	rt name ## _return_value = (rt)0; \
	unsigned int name ## _call_count = 0; \
	rt name() { \
		name ## _call_count += 1; \
		cb(); \
		return name ## _return_value; \
	}

#define MOCK_ARG1_CB(rt, name, \
		arg1_type, \
		cb) \
	rt name ## _return_value = (rt)0; \
 	arg1_type name ## _arg1; \
	unsigned int name ## _call_count = 0; \
	rt name(arg1_type arg1) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		cb(); \
		return name ## _return_value; \
	}
 
#define MOCK_ARG2_CB(rt, name, \
		arg1_type, \
		arg2_type, \
		cb) \
	rt name ## _return_value = (rt)0; \
 	arg1_type name ## _arg1; \
 	arg2_type name ## _arg2; \
	unsigned int name ## _call_count = 0; \
	rt name(arg1_type arg1, \
			arg2_type arg2) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		cb(); \
		return name ## _return_value; \
	}

#define MOCK_ARG3_CB(rt, name, \
		arg1_type, \
		arg2_type, \
		arg3_type, \
		cb) \
	rt name ## _return_value = (rt)0; \
 	arg1_type name ## _arg1; \
 	arg2_type name ## _arg2; \
 	arg3_type name ## _arg3; \
	unsigned int name ## _call_count = 0; \
	rt name(arg1_type arg1, \
			arg2_type arg2, \
			arg3_type arg3) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		name ## _arg3 = arg3; \
		cb(); \
		return name ## _return_value; \
	}

#define MOCK_ARG4_CB(rt, name, \
		arg1_type, \
		arg2_type, \
		arg3_type, \
		arg4_type, \
		cb) \
	rt name ## _return_value = (rt)0; \
 	arg1_type name ## _arg1; \
 	arg2_type name ## _arg2; \
 	arg3_type name ## _arg3; \
 	arg4_type name ## _arg4; \
	unsigned int name ## _call_count = 0; \
	rt name(arg1_type arg1, \
			arg2_type arg2, \
			arg3_type arg3, \
			arg4_type arg4) { \
		name ## _call_count += 1; \
		name ## _arg1 = arg1; \
		name ## _arg2 = arg2; \
		name ## _arg3 = arg3; \
		name ## _arg4 = arg4; \
		cb(); \
		return name ## _return_value; \
	}

#endif  // MOCKMACRO_H_
