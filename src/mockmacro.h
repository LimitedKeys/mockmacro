// 2021 R
/**
 * Mock Macros
 * -----------
 *
 * Create mock funtions quickly for testing.
 *
 * Marcos:
 *
 * - MOCK
 * - MOCK_1ARG
 * - MOCK_2ARG
 * - MOCK_3ARG
 * - MOCK_4ARG
 *
 * - MOCK_CB
 * - MOCK_ARG1_CB
 * - MOCK_ARG2_CB
 * - MOCK_ARG3_CB
 * - MOCK_ARG4_CB
 *
 * - MOCK_SE
 * - MOCK_ARG1_SE
 * - MOCK_ARG2_SE
 * - MOCK_ARG3_SE
 * - MOCK_ARG4_SE
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

#define MOCK_SE(rt, name, se) \
	 unsigned int name ## _call_count = 0; \
         rt name() { \
		 name ## _call_count += 1; \
		 return se(); \
	 }

#define MOCK_1ARG_SE(rt, name, arg1_type, se) \
	 arg1_type name ## _arg1; \
	 unsigned int name ## _call_count = 0; \
         rt name(arg1_type arg1) { \
		 name ## _arg1 = arg1; \
		 name ## _call_count += 1; \
		 return se(arg1); \
	 }

#define MOCK_2ARG_SE(rt, name, \
		arg1_type, \
		arg2_type, \
		se) \
	 arg1_type name ## _arg1; \
	 arg2_type name ## _arg2; \
	 unsigned int name ## _call_count = 0; \
         rt name(arg1_type arg1, \
		 arg2_type arg2) { \
		 name ## _arg1 = arg1; \
		 name ## _arg2 = arg2; \
		 name ## _call_count += 1; \
		 return se(arg1, arg2); \
	 }

#define MOCK_3ARG_SE(rt, name, \
		arg1_type, \
		arg2_type, \
		arg3_type, \
		se) \
	 arg1_type name ## _arg1; \
	 arg2_type name ## _arg2; \
	 arg3_type name ## _arg3; \
	 unsigned int name ## _call_count = 0; \
         rt name(arg1_type arg1, \
		 arg2_type arg2, \
		 arg3_type arg3) { \
		 name ## _arg1 = arg1; \
		 name ## _arg2 = arg2; \
		 name ## _arg3 = arg3; \
		 name ## _call_count += 1; \
		 return se(arg1, arg2, arg3); \
	 }

#endif  // MOCKMACRO_H_
