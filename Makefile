CPPFLAGS=-I src/lib
COMPILER=g++

reporter: src/design_reporter.cpp
	$(COMPILER) src/design_reporter.cpp $(CPPFLAGS) -o bin/reporter.o

clean:
	rm bin/*