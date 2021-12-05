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

The return value can be set at runtime using:

    test_return_value

The value of the input args can be retrieved 
too:

    test_arg1
    test_arg2
    test_arg3

The number of times the function has been
called is tracked as well:

    test_call_count

Macros:

- MOCK
- MOCK_1ARG
- MOCK_2ARG
- MOCK_3ARG

## Example MOCK

    MOCK(int, x);

produces:

- int x(void)
- int x_return_value
- int x_call_count

## Example MOCK_2ARG

    MOCK_2ARG(int, x, int, char); 

produces:

- int x(void)
- int x_arg1
- char x_arg2
- int x_return_value
- int x_call_count

