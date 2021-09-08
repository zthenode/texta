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
#   File: libevx.pri
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pri file for evx library libevx
########################################################################

########################################################################
# libevx

# libevx TARGET
#
libevx_TARGET = ev
libevx_TEMPLATE = lib
libevx_CONFIG += staticlib

# libevx INCLUDEPATH
#
libevx_INCLUDEPATH += \
$${evx_INCLUDEPATH} \

# libevx DEFINES
#
libevx_DEFINES += \
$${evx_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libevx OBJECTIVE_HEADERS
#
#libevx_OBJECTIVE_HEADERS += \
#$${EVX_SRC}/evx/app/console/evx/main.hh \

# libevx OBJECTIVE_SOURCES
#
#libevx_OBJECTIVE_SOURCES += \
#$${EVX_SRC}/evx/app/console/evx/main.mm \

########################################################################
# libevx HEADERS
#
libevx_HEADERS += \
$${EVX_SRC}/base/cevbase.hpp \
$${EVX_SRC}/os/cevmutex.hpp \
$${EVX_SRC}/os/cevsemaphore.hpp \
$${EVX_SRC}/os/cevdatetime.hpp \
$${EVX_SRC}/os/cevsystemtime.hpp \
$${EVX_SRC}/os/cevsystemdate.hpp \
$${EVX_SRC}/os/cevcharfile.hpp \
$${EVX_SRC}/os/evfiletime.hpp \
$${EVX_SRC}/os/cevfiletime.hpp \
$${EVX_SRC}/os/cevfilepath.hpp \
$${EVX_SRC}/os/cevfilepathwriter.hpp \
$${EVX_SRC}/os/cevfilepathstring.hpp \
$${EVX_SRC}/os/cevfilesystementry.hpp \
$${EVX_SRC}/os/cevfilesystementryfound.hpp \
$${EVX_SRC}/os/cevfiledirectoryentry.hpp \
$${EVX_SRC}/os/cevfiledirectory.hpp \
$${EVX_SRC}/os/cevuid.hpp \
$${EVX_SRC}/os/cevgid.hpp \
$${EVX_SRC}/os/cevpid.hpp \
$${EVX_SRC}/os/cevpasswd.hpp \
$${EVX_SRC}/os/cevmainarg.hpp \
$${EVX_SRC}/os/cevmain.hpp \
$${EVX_SRC}/os/cevsocket.hpp \

contains(EVX_OS,macosx|linux) {
libevx_HEADERS += \
$${EVX_SRC}/os/unix/cevunixsystemtime.hpp \
$${EVX_SRC}/os/unix/cevunixfiletime.hpp \
$${EVX_SRC}/os/unix/cevunixfilesystem.hpp 
} else {
} # contains(EVX_OS,macosx|linux)

# libevx SOURCES
#
libevx_SOURCES += \
$${EVX_SRC}/base/cevbase.cpp \
$${EVX_SRC}/os/cevmutex.cpp \
$${EVX_SRC}/os/cevsemaphore.cpp \
$${EVX_SRC}/os/cevdatetime.cpp \
$${EVX_SRC}/os/cevsystemtime.cpp \
$${EVX_SRC}/os/cevsystemdate.cpp \
$${EVX_SRC}/os/cevcharfile.cpp \
$${EVX_SRC}/os/evfiletime.cpp \
$${EVX_SRC}/os/cevfiletime.cpp \
$${EVX_SRC}/os/cevfilepath.cpp \
$${EVX_SRC}/os/cevfilepathwriter.cpp \
$${EVX_SRC}/os/cevfilepathstring.cpp \
$${EVX_SRC}/os/cevfilesystementry.cpp \
$${EVX_SRC}/os/cevfilesystementryfound.cpp \
$${EVX_SRC}/os/cevfiledirectoryentry.cpp \
$${EVX_SRC}/os/cevfiledirectory.cpp \
$${EVX_SRC}/os/cevuid.cpp \
$${EVX_SRC}/os/cevgid.cpp \
$${EVX_SRC}/os/cevpid.cpp \
$${EVX_SRC}/os/cevpasswd.cpp \
$${EVX_SRC}/os/cevmainarg.cpp \
$${EVX_SRC}/os/cevmain.cpp \
$${EVX_SRC}/os/cevsocket.cpp \

contains(EVX_OS,macosx|linux) {
libevx_SOURCES += \
$${EVX_SRC}/os/unix/cevunixsystemtime.cpp \
$${EVX_SRC}/os/unix/cevunixfiletime.cpp \
$${EVX_SRC}/os/unix/cevunixfilesystem.cpp 
} else {
} # contains(EVX_OS,macosx|linux)

########################################################################
