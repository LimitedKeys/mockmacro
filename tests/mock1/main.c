#include <stdio.h>

#include "mockmacro.h"

MOCK(int, test);

int main(void)
{
	if (test_call_count != 0) {
		return -1;
	}

	test();

	if (test_call_count != 1) {
		return -1;
	}

	printf(".");
	return 0;
}
