// 2021 R

#ifndef MOCKMACRO_H_
#define MOCKMACRO_H_

#define MOCK(rt, name) \
	rt name(void) { \
		printf(#name); \
		return (rt)0; \
	};

#endif  // MOCKMACRO_H_
