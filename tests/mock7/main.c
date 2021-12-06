
#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK_3ARG(int, threey, int, int, int);

int main(void) {
	threey_return_value = 123;
	int value = threey(1, 2, 3);

	if (value != 123) {
		printf("Return Value not as expected: %d is not 123", value);
		return -1;
	}

	if (threey_arg1 != 1) {
		printf("Arg1 not saved as expected: %d is not 1", threey_arg1);
		return -2;
	}

	if (threey_arg2 != 2) {
		printf("Arg2 not saved as expected: %d is not 2", threey_arg2);
		return -2;
	}

	if (threey_arg3 != 3) {
		printf("Arg3 not saved as expected: %d is not 3", threey_arg3);
		return -2;
	}

	printf(".");
	return 0;
}
