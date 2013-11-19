# Copyright © 2012 Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

AM_CPPFLAGS = \
	$(DEFINES) \
	$(SELINUX_CFLAGS) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/src/mapi \
	-DMAPI_ABI_HEADER=\"vxapi_tmp.h\"

AM_CFLAGS = $(VISIBILITY_CFLAGS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = vx.pc

VX_includedir = $(includedir)/VX
VX_include_HEADERS = \
	$(top_srcdir)/include/VX/vx.h \
	$(top_srcdir)/include/VX/vx_api.h \
	$(top_srcdir)/include/VX/vx_kernels.h \
	$(top_srcdir)/include/VX/vx_nodes.h \
	$(top_srcdir)/include/VX/vx_types.h \
	$(top_srcdir)/include/VX/vx_vendors.h

lib_LTLIBRARIES = libOpenVX.la

TOP=$(top_srcdir)
include ../Makefile.sources
libOpenVX_la_SOURCES = $(MAPI_FILES) vxapi_tmp.h
libOpenVX_la_LIBADD = $(VX_LIB_DEPS)
libOpenVX_la_LDFLAGS = \
	-no-undefined \
	-version-number 1 \
	$(GC_SECTIONS) \
	$(LD_NO_UNDEFINED)

vxapi_tmp.h: $(srcdir)/vxapi.csv $(top_srcdir)/src/mapi/mapi_abi.py
	$(AM_V_GEN) $(PYTHON2) $(PYTHON_FLAGS) $(top_srcdir)/src/mapi/mapi_abi.py \
		--printer vxapi --mode lib $< > $@

BUILT_SOURCES = vxapi_tmp.h
CLEANFILES = $(BUILT_SOURCES)

include $(top_srcdir)/install-lib-links.mk
