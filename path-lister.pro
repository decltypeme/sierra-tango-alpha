QT += core
QT -= gui

CONFIG += c++11

TARGET = path-lister
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/parser.cpp \
    src/DAG.cpp \
    src/path-lister.cpp \
    src/cpm.cpp \
    src/main.cpp \
    src/netlist.cpp

DISTFILES += \
    lib/osu350.lib \
    LICENSE \
    README.md \
    netlists/full_adder_1bit.netlist.v \
    netlists/mux2_1.netlist.v \
    netlists/muxFollowedBy2DFFs.v \
    netlists/RtoR.netlist.v \
    tests/andingoring.netlist.v \
    tests/bits.netlist.v \
    tests/fourbitmux2X1ToRegToReg.netlist.v \
    tests/full_adder_1bit.netlist.v \
    tests/mux2_1.netlist.v \
    tests/mux4_1.netlist.v \
    tests/muxFollowedBy2DFFs.v \
    tests/RtoR.netlist.v \
    tests/simpleI_R.netlist.v \
    tests/simpleR_O.netlist.v \
    tests/simpleR_R.netlist.v \
    tests/test.netlist.v \
    tests/paths/andingoring.netlist.v.path \
    tests/paths/bits.netlist.v.path \
    tests/paths/fourbitmux2X1ToRegToReg.netlist.v.path \
    tests/paths/full_adder_1bit.netlist.v.path \
    tests/paths/mux2_1.netlist.v.path \
    tests/paths/mux4_1.netlist.v.path \
    tests/paths/RtoR.netlist.v.path \
    tests/paths/simpleI_R.netlist.v.path \
    tests/paths/simpleR_O.netlist.v.path \
    tests/paths/simpleR_R.netlist.v.path \
    tests/paths/test.netlist.v.path \
    tests/netlist/andingoring.netlist.v \
    tests/netlist/bits.netlist.v \
    tests/netlist/fourbitmux2X1ToRegToReg.netlist.v \
    tests/netlist/full_adder_1bit.netlist.v \
    tests/netlist/mux2_1.netlist.v \
    tests/netlist/mux4_1.netlist.v \
    tests/netlist/muxFollowedBy2DFFs.v \
    tests/netlist/RtoR.netlist.v \
    tests/netlist/simpleI_R.netlist.v \
    tests/netlist/simpleR_O.netlist.v \
    tests/netlist/simpleR_R.netlist.v \
    tests/netlist/test.netlist.v \
    Makefile \
    lib/osu350.json \

HEADERS += \
    src/DAG.h \
    src/path_finding.h \
    src/netlist.h \
    src/parser.h \
    src/cpm.h

OBJECTS += \
    ../libertyparser-1.0/src/liberty.o \
    ../libertyparser-1.0/src/parser.o \
    ../libertyparser-1.0/src/tokenizer.o \
    ../libertyparser-1.0/src/utils.o
