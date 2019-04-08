default: test
.PHONY: test lib clean

lib: ldplnoise.cpp test.ldpl
	c++ -std=gnu++11 -c ldplnoise.cpp -o ldplnoise.o

test: ldplnoise.cpp test.ldpl
	ldpl -i=ldplnoise.cpp -o=ldplnoise-test test.ldpl
	./ldplnoise-test

clean:
	rm -f {line,ldpl}noise.{o,a}
