QT += core
QT -= gui

CONFIG += c++11

TARGET = reporter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/parser.cpp \
    src/DAG.cpp

DISTFILES += \
    lib/osu350.json \
    LICENSE \
    README.md \
    netlists/full_adder_1bit.netlist.v \
    netlists/mux2_1.netlist.v \
    netlists/muxFollowedBy2DFFs.v \
    netlists/RtoR.netlist.v

HEADERS += \
    src/DAG.h \
    src/path_finding.h \
    src/netlist.h \
    src/parser.h
