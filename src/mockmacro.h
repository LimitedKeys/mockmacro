// 2021 R

#ifndef MOCKMACRO_H_
#define MOCKMACRO_H_

#define MOCK(rt, name) \
	rt name ## _return_value = (rt)0; \
	rt name(void) { \
		return name ## _return_value; \
	};

#define MOCK_1ARG(rt, name, arg1_type) \
	rt name ## _return_value = (rt)0; \
	rt name ## _arg1; \
	rt name(arg1_type arg1) { \
		name ## _arg1 = arg1; \
		return name ## _return_value; \
	};

#endif  // MOCKMACRO_H_
