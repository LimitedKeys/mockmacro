# Mock Macro

quickly mock C functions with macros:

``` cpp
#include "mockmacro.h"

MOCK(some_function)

int main(void) {
    some_function(1, 2, "three");
    return 0;
}
```

## Details

- build / compile tests (C)
