
#include <stdio.h>

#include "mockmacro.h"

int sideeffect(char, int);

MOCK_2ARG_SE(int, se_test, char, int, sideeffect);

int main(void) {
	int value = se_test('r', -12);

	if (se_test_call_count != 1)
	{
		printf("call count not 1");
		return -1;
	}

	if (se_test_arg1 != 'r') 
	{
		printf("arg1 not r");
		return -1;
	}

	if (se_test_arg2 != -12) 
	{
		printf("arg2 not -12");
		return -1;
	}
	
	if (value != 123)
	{
		printf("Returned value not 123");
		return -1;
	}

	printf(".");
	return 0;
}

int sideeffect(char in1, int in2)
{
	return 123;
}
