
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
     output/mock9.out \
     output/mockA.out \
     output/mockB.out \
     output/mockC.out \
     output/mockD.out \
     output/mockE.out \
     output/mockF.out \
     output/mockG.out \
     output/mockH.out

output/mockH.out: tests/mockH/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockG.out: tests/mockG/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockF.out: tests/mockF/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockE.out: tests/mockE/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockD.out: tests/mockD/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockC.out: tests/mockC/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockB.out: tests/mockB/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

output/mockA.out: tests/mockA/main.c $(HDR)
	@$(CC) $< -o $@ -Isrc
	@./$@

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
