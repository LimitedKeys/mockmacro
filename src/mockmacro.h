// 2021 R

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

#endif  // MOCKMACRO_H_
