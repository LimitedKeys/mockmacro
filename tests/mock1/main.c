#include <stdio.h>

#include "mockmacro.h"

MOCK(void, test)

int main(void)
{
	test();
	printf(".");
}
