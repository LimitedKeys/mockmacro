#include <stdio.h>

#include "mockmacro.h"

MOCK(int, test)

int main(void)
{
	test();
	printf(".");
}
