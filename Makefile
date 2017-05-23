CPPFLAGS=-std=c++11
COMPILER=g++
LIBERTYFLAGS=-I libertyparser-1.0/src
LIBERTYLIB= libertyparser-1.0/src/*.o

reporter: src/design_reporter.cpp
	mkdir -p bin && $(COMPILER) src/design_reporter.cpp $(CPPFLAGS) -o bin/reporter.o

path-lister: src/path-lister.cpp src/DAG.cpp src/parser.cpp src/netlist.cpp src/path_finding.cpp
	mkdir -p bin && $(COMPILER) src/DAG.cpp src/parser.cpp src/path-lister.cpp src/netlist.cpp src/path_finding.cpp $(CPPFLAGS) -o bin/path-lister

gen-constraints: src/gen-constraints.cpp
		mkdir -p bin && $(COMPILER) src/gen-constraints.cpp $(CPPFLAGS) -o bin/gen-net-cap

sta: src/netlist.cpp src/cpm.cpp src/parser.cpp src/sta.cpp src/DAG.cpp src/path_finding.cpp
	mkdir -p bin && $(COMPILER) src/netlist.cpp src/cpm.cpp src/parser.cpp src/sta.cpp src/DAG.cpp src/path_finding.cpp $(CPPFLAGS) $(LIBERTYFLAGS) -o bin/sta $(LIBERTYLIB)

clean:
	rm bin/*
