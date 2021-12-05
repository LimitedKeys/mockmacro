
#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK_2ARG(int, another, uint32_t *, int32_t);

int main(void) {
	uint32_t x = 123;
	another_return_value = 10;
	int value = another(&x, 1);

	if (value != 10) {
		printf("Return Value not as expected: %d is not 10", value);
		return -1;
	}

	if (*another_arg1 != 123) {
		printf("Arg1 not saved as expected: %d is not 123", *another_arg1);
		return -2;
	}

	if (another_arg2 != 1) {
		printf("Arg2 not saved as expected: %d is not 1", another_arg2);
		return -3;
	}

	printf(".");
	return 0;
}
