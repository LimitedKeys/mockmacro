
#include <stdio.h>

#include "mockcheck.h"

int main(void) {
    MOCK_ASSERT(1 == 1);
    printf(".");
}
