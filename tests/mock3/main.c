
#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK_1ARG(int, another, uint32_t)

int main(void) {
	another_return_value = 10;
	int value = another(1);

	if (value != 10) {
		printf("Return Value not as expected: %d is not 10", value);
		return -1;
	}

	if (another_arg1 != 1) {
		printf("Arg1 not saved as expected: %d is not 1", another_arg1);
		return -2;
	}

	printf(".");
	return 0;
}
