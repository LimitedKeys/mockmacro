
OD := $(shell mkdir -p output)
HDR := src/mockmacro.h

.PHONY: all clean

all: output/mock1.out output/mock2.out

output/mock2.out: tests/mock2/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mock1.out: tests/mock1/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

clean:
	rm -rf output
