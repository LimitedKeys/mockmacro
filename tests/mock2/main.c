#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK(uint32_t, test);

int main(void)
{
	test_return_value = 3;
	uint32_t value = test();

	if (3 == value) {
		printf(".");
		return 0;
	} else {
		printf("return value not 3: %d", value);
		return -1;
	}
}
