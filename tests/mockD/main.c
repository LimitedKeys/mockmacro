
#include <stdio.h>

#include "mockmacro.h"

int sideeffect();

MOCK_SE(int, se_test, sideeffect);

int main(void) {
	int value = se_test();

	if (se_test_call_count != 1)
	{
		printf("call count not 1");
		return -1;
	}
	
	if (value != 123)
	{
		printf("Returned value not 123");
	}

	return 0;
}

int sideeffect(void)
{
	return 123;
}
