QT += core
QT -= gui

CONFIG += c++11

TARGET = reporter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/main.cpp

DISTFILES += \
    lib/osu350.json \
    LICENSE \
    README.md

HEADERS += \
    src/DAG.h \
    src/path_finding.h \
    src/netlist.h
