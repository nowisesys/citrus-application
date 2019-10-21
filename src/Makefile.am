EXTRA_DIST = libcitrus-application.pc.in libcitrus-application.pc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libcitrus-application.pc

otherincludedir = $(includedir)/citrus
otherinclude_HEADERS = application.hpp

lib_LTLIBRARIES = libcitrus-application.la
libcitrus_application_la_SOURCES = \
    application.hpp application.cpp runtime.cpp

libcitrus_application_la_LDFLAGS  = -version-info 1:0:0 -lcitrus-options
libcitrus_application_la_CXXFLAGS = -DLIBCITRUS_EXPORTS=1
