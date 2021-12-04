// 2021 R

#ifndef MOCKMACRO_H_
#define MOCKMACRO_H_

#define MOCK(name) \
	void name(void) {printf(#name);};

#endif  // MOCKMACRO_H_
