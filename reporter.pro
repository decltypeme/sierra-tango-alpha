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
    src/DAG.cpp \
    src/design_reporter.cpp

DISTFILES += \
    lib/osu350.json \
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
    tests/test.netlist.v

HEADERS += \
    src/DAG.h \
    src/path_finding.h \
    src/netlist.h \
    src/parser.h \
    src/lib/rapidjson/error/en.h \
    src/lib/rapidjson/error/error.h \
    src/lib/rapidjson/internal/biginteger.h \
    src/lib/rapidjson/internal/diyfp.h \
    src/lib/rapidjson/internal/dtoa.h \
    src/lib/rapidjson/internal/ieee754.h \
    src/lib/rapidjson/internal/itoa.h \
    src/lib/rapidjson/internal/meta.h \
    src/lib/rapidjson/internal/pow10.h \
    src/lib/rapidjson/internal/regex.h \
    src/lib/rapidjson/internal/stack.h \
    src/lib/rapidjson/internal/strfunc.h \
    src/lib/rapidjson/internal/strtod.h \
    src/lib/rapidjson/internal/swap.h \
    src/lib/rapidjson/msinttypes/inttypes.h \
    src/lib/rapidjson/msinttypes/stdint.h \
    src/lib/rapidjson/allocators.h \
    src/lib/rapidjson/document.h \
    src/lib/rapidjson/encodedstream.h \
    src/lib/rapidjson/encodings.h \
    src/lib/rapidjson/filereadstream.h \
    src/lib/rapidjson/filewritestream.h \
    src/lib/rapidjson/fwd.h \
    src/lib/rapidjson/istreamwrapper.h \
    src/lib/rapidjson/memorybuffer.h \
    src/lib/rapidjson/memorystream.h \
    src/lib/rapidjson/ostreamwrapper.h \
    src/lib/rapidjson/pointer.h \
    src/lib/rapidjson/prettywriter.h \
    src/lib/rapidjson/rapidjson.h \
    src/lib/rapidjson/reader.h \
    src/lib/rapidjson/schema.h \
    src/lib/rapidjson/stream.h \
    src/lib/rapidjson/stringbuffer.h \
    src/lib/rapidjson/writer.h
