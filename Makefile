CPPFLAGS=-I src/lib -std=c++11
COMPILER=g++

reporter: src/design_reporter.cpp
	mkdir -p bin && $(COMPILER) src/design_reporter.cpp $(CPPFLAGS) -o bin/reporter.o

path-lister: src/*.cpp
	mkdir -p bin && $(COMPILER) src/DAG.cpp src/parser.cpp src/path-lister.cpp $(CPPFLAGS) -o bin/path-lister

clean:
	rm bin/*
