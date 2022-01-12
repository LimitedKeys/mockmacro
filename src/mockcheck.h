/* Macro to assert something at compile time
 *
 * Example:
 *
 *   MOCK_ASSERT(1 == 0);
 *   -> Build Error
 */
#ifndef MOCK_ASSERT_H_
#define MOCK_ASSERT_H_

#define MOCK_ASSERT(logic) ( \
        sizeof(struct { \
            int: -(!(logic)); \
            }) \
        )

#endif  // MOCK_ASSERT_H_
