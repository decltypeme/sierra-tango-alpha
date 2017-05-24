# sierra-tango-alpha
Static Timing Analyzer

## Module: Path-Lister

To build the module
```
make path-lister
```

To test the tests in the folder tests/netlist

```
./tests/path-lister
```

## Module: STA

To  build the module
```
make sta
```

Path arguments
```
./bin/sta [LIBERTY_FILE_PATH] [NET_LIST] [CAPACITANCE_FILE] [CONSTRAINT_FILE] [CLK_SKEW_FILE] [PATH_REPORT_OUTPUT_FILE]
```

## Module: Violations Checker

To  build the module
```
make violations
```

## Dependecies
Liberty Parser: http://vlsicad.ucsd.edu/~sharma/Research/software/liberty_parser/
