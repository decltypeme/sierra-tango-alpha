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
    src/critical-path-finder.cpp \
    src/libertyparser-1.0/src/liberty.cpp \
    src/libertyparser-1.0/src/parser.cc \
    src/libertyparser-1.0/src/utils.cpp \
    src/cpm.cpp \
    src/libertyparser-1.0/src/tokenizer.c

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
    tests/path-lister.sh \
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
    src/libertyparser-1.0/m4/ax_boost_base.m4 \
    src/libertyparser-1.0/aclocal.m4 \
    src/libertyparser-1.0/config.guess \
    src/libertyparser-1.0/config.status \
    src/libertyparser-1.0/config.sub \
    src/libertyparser-1.0/configure \
    src/libertyparser-1.0/depcomp \
    src/libertyparser-1.0/install-sh \
    src/libertyparser-1.0/libtool \
    src/libertyparser-1.0/ltmain.sh \
    src/libertyparser-1.0/missing \
    src/libertyparser-1.0/ylwrap \
    src/libertyparser-1.0/src/doc/html/doxygen.png \
    src/libertyparser-1.0/src/doc/html/doxygen.css \
    src/libertyparser-1.0/src/doc/html/annotated.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Cell-members.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Cell.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Leakage.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Library-members.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Library.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1not__found-members.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1not__found.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Pin-members.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Pin.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Timing-members.html \
    src/libertyparser-1.0/src/doc/html/classliberty_1_1Timing.html \
    src/libertyparser-1.0/src/doc/html/classutils_1_1Table-members.html \
    src/libertyparser-1.0/src/doc/html/classutils_1_1Table.html \
    src/libertyparser-1.0/src/doc/html/files.html \
    src/libertyparser-1.0/src/doc/html/functions.html \
    src/libertyparser-1.0/src/doc/html/functions_func.html \
    src/libertyparser-1.0/src/doc/html/functions_rela.html \
    src/libertyparser-1.0/src/doc/html/functions_vars.html \
    src/libertyparser-1.0/src/doc/html/globals.html \
    src/libertyparser-1.0/src/doc/html/globals_defs.html \
    src/libertyparser-1.0/src/doc/html/globals_enum.html \
    src/libertyparser-1.0/src/doc/html/globals_eval.html \
    src/libertyparser-1.0/src/doc/html/globals_func.html \
    src/libertyparser-1.0/src/doc/html/globals_type.html \
    src/libertyparser-1.0/src/doc/html/globals_vars.html \
    src/libertyparser-1.0/src/doc/html/index.html \
    src/libertyparser-1.0/src/doc/html/liberty_8cpp.html \
    src/libertyparser-1.0/src/doc/html/liberty_8h-source.html \
    src/libertyparser-1.0/src/doc/html/liberty_8h.html \
    src/libertyparser-1.0/src/doc/html/namespaceliberty.html \
    src/libertyparser-1.0/src/doc/html/namespacemembers.html \
    src/libertyparser-1.0/src/doc/html/namespacemembers_enum.html \
    src/libertyparser-1.0/src/doc/html/namespacemembers_eval.html \
    src/libertyparser-1.0/src/doc/html/namespacemembers_func.html \
    src/libertyparser-1.0/src/doc/html/namespaces.html \
    src/libertyparser-1.0/src/doc/html/namespacestd.html \
    src/libertyparser-1.0/src/doc/html/namespaceutils.html \
    src/libertyparser-1.0/src/doc/html/parser_8cc.html \
    src/libertyparser-1.0/src/doc/html/parser_8h-source.html \
    src/libertyparser-1.0/src/doc/html/parser_8hh-source.html \
    src/libertyparser-1.0/src/doc/html/parserFunctions_8h-source.html \
    src/libertyparser-1.0/src/doc/html/test_8cpp.html \
    src/libertyparser-1.0/src/doc/html/unionyyalloc-members.html \
    src/libertyparser-1.0/src/doc/html/unionyyalloc.html \
    src/libertyparser-1.0/src/doc/html/unionYYSTYPE-members.html \
    src/libertyparser-1.0/src/doc/html/unionYYSTYPE.html \
    src/libertyparser-1.0/src/doc/html/utils_8cpp.html \
    src/libertyparser-1.0/src/doc/html/utils_8h-source.html \
    src/libertyparser-1.0/src/doc/html/utils_8h.html \
    lib/osu035.lib \
    src/libertyparser-1.0/config.h.in \
    src/libertyparser-1.0/configure.ac \
    src/libertyparser-1.0/stamp-h1 \
    tests/netlist/RtoR.netlist.v.path \
    src/libertyparser-1.0/config.log \
    src/libertyparser-1.0/src/Makefile \
    src/libertyparser-1.0/src/Makefile.am \
    src/libertyparser-1.0/src/Makefile.in \
    src/libertyparser-1.0/Makefile \
    src/libertyparser-1.0/Makefile.am \
    src/libertyparser-1.0/Makefile.in

HEADERS += \
    src/DAG.h \
    src/path_finding.h \
    src/netlist.h \
    src/parser.h \
    src/libertyparser-1.0/src/liberty.h \
    src/libertyparser-1.0/src/parser.h \
    src/libertyparser-1.0/src/parser.yy \
    src/libertyparser-1.0/src/parserFunctions.h \
    src/libertyparser-1.0/src/tokenizer.l \
    src/libertyparser-1.0/src/utils.h \
    src/libertyparser-1.0/config.h \
    src/cpm.h \
    src/std_lib.h

OBJECTS += \
    src/libertyparser-1.0/src/liberty.o \
    src/libertyparser-1.0/src/parser.o \
    src/libertyparser-1.0/src/tokenizer.o \
    src/libertyparser-1.0/src/utils.o
