
OD := $(shell mkdir -p output)
HDR := src/mockmacro.h

.PHONY: all clean

all: output/mock1.out \
     output/mock2.out \
     output/mock3.out \
     output/mock4.out \
     output/mock5.out \
     output/mock6.out \
     output/mock7.out \
     output/mock8.out \
     output/mock9.out

output/mock9.out: tests/mock9/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock8.out: tests/mock8/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock7.out: tests/mock7/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock6.out: tests/mock6/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock5.out: tests/mock5/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock4.out: tests/mock4/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock3.out: tests/mock3/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock2.out: tests/mock2/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock1.out: tests/mock1/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

clean:
	rm -rf output
