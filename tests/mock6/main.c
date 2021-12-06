
#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK_4ARG(int, fourx, int, int, int, int);

int main(void) {
	fourx_return_value = 123;
	int value = fourx(1, 2, 3, 4);

	if (value != 123) {
		printf("Return Value not as expected: %d is not 123", value);
		return -1;
	}

	if (fourx_arg1 != 1) {
		printf("Arg1 not saved as expected: %d is not 1", fourx_arg1);
		return -2;
	}

	if (fourx_arg2 != 2) {
		printf("Arg2 not saved as expected: %d is not 2", fourx_arg2);
		return -2;
	}

	if (fourx_arg3 != 3) {
		printf("Arg3 not saved as expected: %d is not 3", fourx_arg3);
		return -2;
	}

	if (fourx_arg4 != 4) {
		printf("Arg4 not saved as expected: %d is not 4", fourx_arg4);
		return -2;
	}

	printf(".");
	return 0;
}
