CPPFLAGS=-std=c++11
COMPILER=g++
LIBERTYFLAGS=-I libertyparser-1.0/src 
LIBERTYLIB= libertyparser-1.0/src/*.o

reporter: src/design_reporter.cpp
	mkdir -p bin && $(COMPILER) src/design_reporter.cpp $(CPPFLAGS) -o bin/reporter.o

path-lister: src/path-lister.cpp src/DAG.cpp src/parser.cpp
	mkdir -p bin && $(COMPILER) src/DAG.cpp src/parser.cpp src/path-lister.cpp $(CPPFLAGS) -o bin/path-lister

cpm: src/cpm.cpp
	mkdir -p bin && $(COMPILER) src/cpm.cpp $(CPPFLAGS) $(LIBERTYFLAGS) -o bin/cpm $(LIBERTYLIB)
	
gen-constraints: src/gen-constraints.cpp
	mkdir -p bin && $(COMPILER) src/gen-constraints.cpp $(CPPFLAGS) -o bin/gen-net-cap

clean:
	rm bin/*
