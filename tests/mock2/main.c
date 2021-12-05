#include <stdio.h>
#include <stdint.h>

#include "mockmacro.h"

MOCK(uint32_t, test)

int main(void)
{
	uint32_t value = test();
	printf(".");
}
