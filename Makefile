CPPFLAGS=-I src/lib -std=c++11
COMPILER=g++

reporter: src/design_reporter.cpp
	mkdir -p bin && $(COMPILER) src/design_reporter.cpp $(CPPFLAGS) -o bin/reporter.o

STA: src/*.cpp
	mkdir -p bin && $(COMPILER) src/DAG.cpp src/parser.cpp src/STA.cpp $(CPPFLAGS) -o bin/STA

clean:
	rm bin/*
