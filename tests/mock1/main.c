#include <stdio.h>

#include "mockmacro.h"

MOCK(test)

int main(void)
{
	printf("Hi");
	test();
}
