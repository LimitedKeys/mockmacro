
#include <stdio.h>
#include <stdbool.h>

#include "mockmacro.h"

bool cb_called = false;
void cb1();

MOCK_ARG3_CB(int, test1, 
		int, 
		unsigned char,  
		char,
		cb1);

int main(void) {
	test1_return_value = 23;
	int value = test1(-45, 67, 'q');

	if (value != 23)
	{
		printf("Return value not 23");
		return -1;
	}

	if (test1_arg1 != -45)
	{
		printf("Arg1 not -45");
		return -1;
	}

	if (test1_arg2 != 67)
	{
		printf("Arg2 not 67");
		return -1;
	}

	if (test1_arg3 != 'q')
	{
		printf("Arg3 not q");
		return -1;
	}

	if (test1_call_count != 1)
	{
		printf("Call count not 1");
		return -1;
	}

	if (cb_called == false) {
		printf("CB not called");
		return -1;
	}

	printf(".");
	return 0;
}

void cb1() {
	cb_called = true;
}
