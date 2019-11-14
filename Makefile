default: example
.PHONY: example lib clean

lib: ldplnoise.cpp example.ldpl
	c++ -std=gnu++11 -c ldplnoise.cpp -o ldplnoise.o

example: ldplnoise.cpp example.ldpl
	ldpl -o=ldplnoise-example example.ldpl
	./ldplnoise-example

clean:
	rm -f {line,ldpl}noise.{o,a}
