
OD := $(shell mkdir -p output)
HDR := src/mockmacro.h

.PHONY: all clean

all: output/mock1.out

output/mock1.out: tests/mock1/main.c $(HDR)
	$(CC) $< -o $@ -Isrc
	./$@

clean:
	rm -rf output
