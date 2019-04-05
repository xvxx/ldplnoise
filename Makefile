default: lib

lib: ldplnoise.cpp
	make clean
	c++ -c linenoise.hpp -std=gnu++11 -o linenoise.o
	c++ -c ldplnoise.cpp -std=gnu++11 -o ldplnoise.o
	ar -cvq ldplnoise.a ldplnoise.o linenoise.o

test: lib
	ldpl -i=ldplnoise.h -o=ldplnoise-test test.lsc
	./ldplnoise-test

clean:
	rm -f {line,ldpl}noise.{o,a}
