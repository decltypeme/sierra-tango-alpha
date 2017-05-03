QT += core
QT -= gui

CONFIG += c++11

TARGET = reporter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/DAG.cpp \
    src/design_reporter.cpp \
    src/main.cpp

DISTFILES += \
    lib/osu350.json \
    LICENSE \
    README.md \
    anding.json

HEADERS += \
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
    src/lib/rapidjson/writer.h \
    src/DAG.h
