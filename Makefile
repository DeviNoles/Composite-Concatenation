all: concat_compos.cpp
	g++ -g -Wall -std=c++11 concat_compos.cpp -o compos

test:
	nosetests

doc:
	doxygen doxyfile

clean:
	rm -rf compos doc
