# Mock Macro

quickly mock C functions with macros:

``` cpp
#include "mockmacro.h"

MOCK(int, some_function)

int main(void) {
    some_function();
    return 0;
}
```

## Details

Say we have the line in our code:

    #include "test.h"
    uint32_t value = test(1, 2, 3);

but we can't use the test function in unit
tests. So we'll write unit test version of
'test.h' and include:

    MOCK_3ARG(uint32_t, test, int, int, int);

The retutn value can be set at runtime using:

    test_return_value

The value of the input args can be retrieved 
too:

    test_arg1
    test_arg2
    test_arg3

The number of times the function has been
called is tracked as well:

    test_call_count

### MOCK

Define a test function with no arguments:

    MOCK(int, x); -> int x(void)
                     x_return_value
                     x_call_count

The (XARG) versions if this Macro provide the
ability to mock functions with input
arguments. 

To define a mock function with one argument

    MOCK_1ARG(int, x); -> int x(void)
                          x_arg1
                          x_return_value
                          x_call_count

See:

- MOCK
- MOCK_1ARG
- MOCK_2ARG
- MOCK_3ARG
- MOCK_4ARG

### MOCK_CB

Define a mock function, which calls the 
provided callback when called. Call count and
return value globals are still available

	MOCK_CB(int, x, cb) -> x_call_count
                               x_return_value
                               call cb()

Related:

- MOCK_CB
- MOCK_ARG1_CB
- MOCK_ARG2_CB
- MOCK_ARG3_CB
- MOCK_ARG4_CB

### MOCK_SE

Define a mock function, which calls the 
provided side effect function with the 
function arguments.

The value returned from the side effect will
be returned.

The side effect function should have the same
function signiture of the mocked function.

	MOCK_SE(int, x, se) -> return se()
                               x_call_count

Mocking with args and a side effect is 
available as well

	MOCK_1ARG_SE(int, x, int, se) ->
                        return se(x_arg1)
                        x_call_count
                        x_arg1

See:

- MOCK_SE
- MOCK_1ARG_SE
- MOCK_2ARG_SE
- MOCK_3ARG_SE
- MOCK_4ARG_SE
