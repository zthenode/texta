########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libxde.pri
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pri file for xde library libxde
########################################################################

########################################################################
# libxde

# libxde TARGET
#
libxde_TARGET = xde
libxde_TEMPLATE = lib
libxde_CONFIG += staticlib

# libxde INCLUDEPATH
#
libxde_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# libxde DEFINES
#
libxde_DEFINES += \
$${xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libxde OBJECTIVE_HEADERS
#
#libxde_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/app/console/xde/main.hh \

# libxde OBJECTIVE_SOURCES
#
#libxde_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/app/console/xde/main.mm \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cbase/cbase.hxx \
$${XDE_SRC}/clib/cbase/ccomparer.hxx \
$${XDE_SRC}/clib/cbase/ccounter.hxx \
$${XDE_SRC}/clib/cbase/cdigitizer.hxx \
$${XDE_SRC}/clib/cbase/cerror.hxx \
$${XDE_SRC}/clib/cbase/cinstance.hxx \
$${XDE_SRC}/clib/cbase/cinstanceinterface.hxx \
$${XDE_SRC}/clib/cbase/cinterface.hxx \
$${XDE_SRC}/clib/cbase/cinterfacebase.hxx \
$${XDE_SRC}/clib/cbase/cnamevalueeventinterface.hxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriter.hxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.hxx \
$${XDE_SRC}/clib/cbase/creference.hxx \
$${XDE_SRC}/clib/cbase/creferenced.hxx \
$${XDE_SRC}/clib/cbase/csingleinstance.hxx \
$${XDE_SRC}/clib/cbase/cvector.hxx \
$${XDE_SRC}/clib/cbase/cvectorinterface.hxx \
$${XDE_SRC}/clib/cbase/cattached.hxx \
$${XDE_SRC}/clib/cbase/cattachedinterface.hxx \
$${XDE_SRC}/clib/cbase/cattachinterface.hxx \
$${XDE_SRC}/clib/cbase/cbuffer.hxx \
$${XDE_SRC}/clib/cbase/cbufferinterface.hxx \
$${XDE_SRC}/clib/cbase/cccharstring.hxx \
$${XDE_SRC}/clib/cbase/cchar.hxx \
$${XDE_SRC}/clib/cbase/ccharinterface.hxx \
$${XDE_SRC}/clib/cbase/ccreatedattached.hxx \
$${XDE_SRC}/clib/cbase/ccreatedinterface.hxx \
$${XDE_SRC}/clib/cbase/cdestroyinterface.hxx \
$${XDE_SRC}/clib/cbase/clist.hxx \
$${XDE_SRC}/clib/cbase/ccloseinterface.hxx \
$${XDE_SRC}/clib/cbase/copened.hxx \
$${XDE_SRC}/clib/cbase/copenedinterface.hxx \
$${XDE_SRC}/clib/cbase/copeninterface.hxx \
$${XDE_SRC}/clib/cbase/cbytestreaminterface.hxx \
$${XDE_SRC}/clib/cbase/clookstream.hxx \
$${XDE_SRC}/clib/cbase/creader.hxx \
$${XDE_SRC}/clib/cbase/creaderinterface.hxx \
$${XDE_SRC}/clib/cbase/cstream.hxx \
$${XDE_SRC}/clib/cbase/cstreaminterface.hxx \
$${XDE_SRC}/clib/cbase/cwriter.hxx \
$${XDE_SRC}/clib/cbase/cwriterinterface.hxx \
$${XDE_SRC}/clib/cbase/cstring.hxx \
$${XDE_SRC}/clib/cbase/cstringbase.hxx \
$${XDE_SRC}/clib/cbase/cstringinterface.hxx \
$${XDE_SRC}/clib/cbase/cavltree.hxx \
$${XDE_SRC}/clib/cbase/cbinarytree.hxx \
$${XDE_SRC}/clib/cbase/credblacktree.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cbase/cbase.cxx \
$${XDE_SRC}/clib/cbase/ccomparer.cxx \
$${XDE_SRC}/clib/cbase/ccounter.cxx \
$${XDE_SRC}/clib/cbase/cdigitizer.cxx \
$${XDE_SRC}/clib/cbase/cerror.cxx \
$${XDE_SRC}/clib/cbase/cinstance.cxx \
$${XDE_SRC}/clib/cbase/cinstanceinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterfacebase.cxx \
$${XDE_SRC}/clib/cbase/cnamevalueeventinterface.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriter.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.cxx \
$${XDE_SRC}/clib/cbase/creference.cxx \
$${XDE_SRC}/clib/cbase/creferenced.cxx \
$${XDE_SRC}/clib/cbase/csingleinstance.cxx \
$${XDE_SRC}/clib/cbase/cvector.cxx \
$${XDE_SRC}/clib/cbase/cvectorinterface.cxx \
$${XDE_SRC}/clib/cbase/cattached.cxx \
$${XDE_SRC}/clib/cbase/cattachedinterface.cxx \
$${XDE_SRC}/clib/cbase/cattachinterface.cxx \
$${XDE_SRC}/clib/cbase/cbuffer.cxx \
$${XDE_SRC}/clib/cbase/cbufferinterface.cxx \
$${XDE_SRC}/clib/cbase/cccharstring.cxx \
$${XDE_SRC}/clib/cbase/cchar.cxx \
$${XDE_SRC}/clib/cbase/ccharinterface.cxx \
$${XDE_SRC}/clib/cbase/ccreatedattached.cxx \
$${XDE_SRC}/clib/cbase/ccreatedinterface.cxx \
$${XDE_SRC}/clib/cbase/cdestroyinterface.cxx \
$${XDE_SRC}/clib/cbase/clist.cxx \
$${XDE_SRC}/clib/cbase/ccloseinterface.cxx \
$${XDE_SRC}/clib/cbase/copened.cxx \
$${XDE_SRC}/clib/cbase/copenedinterface.cxx \
$${XDE_SRC}/clib/cbase/copeninterface.cxx \
$${XDE_SRC}/clib/cbase/cbytestreaminterface.cxx \
$${XDE_SRC}/clib/cbase/clookstream.cxx \
$${XDE_SRC}/clib/cbase/creader.cxx \
$${XDE_SRC}/clib/cbase/creaderinterface.cxx \
$${XDE_SRC}/clib/cbase/cstream.cxx \
$${XDE_SRC}/clib/cbase/cstreaminterface.cxx \
$${XDE_SRC}/clib/cbase/cwriter.cxx \
$${XDE_SRC}/clib/cbase/cwriterinterface.cxx \
$${XDE_SRC}/clib/cbase/cstring.cxx \
$${XDE_SRC}/clib/cbase/cstringbase.cxx \
$${XDE_SRC}/clib/cbase/cstringinterface.cxx \
$${XDE_SRC}/clib/cbase/cavltree.cxx \
$${XDE_SRC}/clib/cbase/cbinarytree.cxx \
$${XDE_SRC}/clib/cbase/credblacktree.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.hxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.hxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.hxx \
$${XDE_SRC}/clib/cfs/cfilepath.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.cxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.cxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.cxx \
$${XDE_SRC}/clib/cfs/cfilepath.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cxttp/chttp.h \
$${XDE_SRC}/clib/cxttp/cxttp.h \
$${XDE_SRC}/clib/cxttp/chttpformfield.hxx \
$${XDE_SRC}/clib/cxttp/chttpformfieldinterface.hxx \
$${XDE_SRC}/clib/cxttp/chttpurlencodedformfieldwriter.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cxttp/http.c \
$${XDE_SRC}/clib/cxttp/xttp.c \
$${XDE_SRC}/clib/cxttp/chttpformfield.cxx \
$${XDE_SRC}/clib/cxttp/chttpformfieldinterface.cxx \
$${XDE_SRC}/clib/cxttp/chttpurlencodedformfieldwriter.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/ccgi/ccgiinterface.hxx \
$${XDE_SRC}/clib/ccgi/ccgienv.hxx \
$${XDE_SRC}/clib/ccgi/ccgi.hxx \
$${XDE_SRC}/clib/ccgi/ccgistream.hxx \
$${XDE_SRC}/clib/ccgi/cfilenamecgi.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatecgi.hxx \
$${XDE_SRC}/clib/ccgi/cdocumenttemplatecgi.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.hxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/ccgi/ccgiinterface.cxx \
$${XDE_SRC}/clib/ccgi/ccgienv.cxx \
$${XDE_SRC}/clib/ccgi/ccgi.cxx \
$${XDE_SRC}/clib/ccgi/ccgistream.cxx \
$${XDE_SRC}/clib/ccgi/cfilenamecgi.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatecgi.cxx \
$${XDE_SRC}/clib/ccgi/cdocumenttemplatecgi.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/ct/ctvariableinterface.hxx \
$${XDE_SRC}/clib/ct/ctvariable.hxx \
$${XDE_SRC}/clib/ct/ctvalueinterface.hxx \
$${XDE_SRC}/clib/ct/ctvalue.hxx \
$${XDE_SRC}/clib/ct/ctfunctioninterface.hxx \
$${XDE_SRC}/clib/ct/ctfunctionlist.hxx \
$${XDE_SRC}/clib/ct/ctfunctiontree.hxx \
$${XDE_SRC}/clib/ct/ctfunction.hxx \
$${XDE_SRC}/clib/ct/ctfunctionparameter.hxx \
$${XDE_SRC}/clib/ct/ctfunctionargument.hxx \
$${XDE_SRC}/clib/ct/ctinterface.hxx \
$${XDE_SRC}/clib/ct/ct.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/ct/ctvariableinterface.cxx \
$${XDE_SRC}/clib/ct/ctvariable.cxx \
$${XDE_SRC}/clib/ct/ctvalueinterface.cxx \
$${XDE_SRC}/clib/ct/ctvalue.cxx \
$${XDE_SRC}/clib/ct/ctfunctioninterface.cxx \
$${XDE_SRC}/clib/ct/ctfunctionlist.cxx \
$${XDE_SRC}/clib/ct/ctfunctiontree.cxx \
$${XDE_SRC}/clib/ct/ctfunction.cxx \
$${XDE_SRC}/clib/ct/ctfunctionparameter.cxx \
$${XDE_SRC}/clib/ct/ctfunctionargument.cxx \
$${XDE_SRC}/clib/ct/ctinterface.cxx \
$${XDE_SRC}/clib/ct/ct.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cyy/clexercgi.hxx \
$${XDE_SRC}/clib/cyy/clexercgilex.hxx \
$${XDE_SRC}/clib/cyy/clexersource.hxx \
$${XDE_SRC}/clib/cyy/clexertoken.hxx \
$${XDE_SRC}/clib/cyy/cyylexer.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cyy/clexercgi.cxx \
$${XDE_SRC}/clib/cyy/clexercgilex.cxx \
$${XDE_SRC}/clib/cyy/clexersource.cxx \
$${XDE_SRC}/clib/cyy/clexertoken.cxx \
$${XDE_SRC}/clib/cyy/cyylexer.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_string.h \
$${XDE_SRC}/clib/cos/cdebug_printf.h \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_string.c \
$${XDE_SRC}/clib/cos/cdebug_printf.c \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.hxx \
$${XDE_SRC}/clib/cos/cmessagequeue.hxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.hxx \
$${XDE_SRC}/clib/cos/csemaphore.hxx \
$${XDE_SRC}/clib/cos/cthreadinterface.hxx \
$${XDE_SRC}/clib/cos/cthread.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.cxx \
$${XDE_SRC}/clib/cos/cmessagequeue.cxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.cxx \
$${XDE_SRC}/clib/cos/csemaphore.cxx \
$${XDE_SRC}/clib/cos/cthreadinterface.cxx \
$${XDE_SRC}/clib/cos/cthread.cxx \

########################################################################
# libxde HEADERS
#
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cfileinterface.hxx \
$${XDE_SRC}/clib/cos/cfile.hxx \
$${XDE_SRC}/clib/cos/cdebug.hxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.hxx \
$${XDE_SRC}/clib/cos/cdevice.hxx \
$${XDE_SRC}/clib/cos/cmaininterface.hxx \
$${XDE_SRC}/clib/cos/cmain.hxx \
$${XDE_SRC}/clib/cos/cmainarginterface.hxx \
$${XDE_SRC}/clib/cos/cmainarg.hxx \
$${XDE_SRC}/clib/cos/cargmain.hxx \

# libxde SOURCES
#
libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cfileinterface.cxx \
$${XDE_SRC}/clib/cos/cfile.cxx \
$${XDE_SRC}/clib/cos/cdebug.cxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.cxx \
$${XDE_SRC}/clib/cos/cdevice.cxx \
$${XDE_SRC}/clib/cos/cmaininterface.cxx \
$${XDE_SRC}/clib/cos/cmain.cxx \
$${XDE_SRC}/clib/cos/cmainarginterface.cxx \
$${XDE_SRC}/clib/cos/cmainarg.cxx \
$${XDE_SRC}/clib/cos/cargmain.cxx \

########################################################################
