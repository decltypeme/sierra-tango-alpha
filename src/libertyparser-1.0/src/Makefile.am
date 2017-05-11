#docdir = $(prefix)/doc/html
AM_YFLAGS = -d
AM_CXXFLAGS = $(BOOST_CPPFLAGS)
BUILT_SOURCES = parser.h
lib_LTLIBRARIES = libLibertyParser.la
include_HEADERS = liberty.h utils.h
#doc_DATA = doc/html/doxygen.png
EXTRA_DIST = doc/html
libLibertyParser_la_SOURCES = parser.yy tokenizer.l utils.cpp liberty.cpp parserFunctions.h
install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(prefix)/doc
	-for file in $(srcdir)/doc/html/*; do \
	basefile=`basename $$file`; \
	$(INSTALL_DATA) $(srcdir)/$$file $(DESTDIR)$(prefix)/doc/$$basefile; \
	done
uninstall-local:
	-rm -rf $(DESTDIR)$(prefix)/doc

