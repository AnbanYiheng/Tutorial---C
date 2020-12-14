ifeq ($(OS),Windows_NT)
	CLEANCMD=del fuzz, fuzz.exp, fuzz.lib, fuzz.pdb, fuzz-abc, abc-rt.o.o, fuzz.o, main.o
else
	CLEANCMD=rm -rf fuzz fuzz.exp fuzz.lib fuzz.pdb fuzz-abc abc-rt.o.o fuzz.o main.o
endif


OBJS=fuzz.c api.c
CFLAGS=-O3 -funroll-loops -Wall -D_FORTIFY_SOURCE=2 -g -Wno-pointer-sign

all: fuzz

fuzz: $(OBJS)
	$(CC) -g3 $(CFLAGS) $(OBJS) -o $@

.PHONY: clean

clean:
	$(CLEANCMD)
