VERSION := 1.1.0
ARCHIVE := mockmacro-${VERSION}.zip

OD := $(shell mkdir -p output)
HDR := src/mockmacro.h src/mockcheck.h

OBJ:=$(addsuffix .out, \
	 $(addprefix output/, \
	 $(notdir $(wildcard tests/*))))

vpath % tests

.PHONY: all clean save

all: $(OBJ)
	@echo Done

output/%.out: %/main.c $(HDR)
	@mkdir -p $(@D)
	@$(CC) $< -o $@ -Isrc
	@./$@

clean:
	rm -rf output

save: archive/${ARCHIVE}

archive/$(ARCHIVE):
	git archive -o ./archive/$(ARCHIVE) HEAD
