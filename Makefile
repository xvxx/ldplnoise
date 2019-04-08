default: lib


test: 
	ldpl -i=ldplnoise.cpp -o=ldplnoise-test test.lsc
	./ldplnoise-test

clean:
	rm -f {line,ldpl}noise.{o,a}
