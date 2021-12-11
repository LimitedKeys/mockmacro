
#include <stdio.h>

#include "mockmacro.h"

int sideeffect(char, int, char, int);

MOCK_4ARG_SE(int, se_test, char, int, char, int, sideeffect);

int main(void) {
	int value = se_test('r', -12, 's', 34);

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

	if (se_test_arg3 != 's') 
	{
		printf("arg3 not s");
		return -1;
	}

	if (se_test_arg4 != 34) 
	{
		printf("arg4 not 34");
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

int sideeffect(char in1, int in2, char in3, int in4)
{
	return 123;
}
