default: test
.PHONY: test clean

test: ldplnoise.cpp test.ldpl
	ldpl -i=ldplnoise.cpp -o=ldplnoise-test test.ldpl
	./ldplnoise-test

clean:
	rm -f {line,ldpl}noise.{o,a}
