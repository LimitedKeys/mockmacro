#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK_1ARG(int32_t, xxx, uint32_t)

int main(void) {
	if (xxx_call_count != 0) {
		printf("call count not 0");
		return -1;
	}

	xxx(1);

	if (xxx_call_count != 1) {
		printf("call count not 1");
		return -2;
	}

	xxx(2);

	if (xxx_call_count != 2) {
		printf("call count not 2");
		return -3;
	}

	printf(".");
	return 0;
}
