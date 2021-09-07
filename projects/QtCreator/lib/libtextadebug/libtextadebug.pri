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
#   File: libtextadebug.pri
#
# Author: $author$
#   Date: 9/6/2021
#
# QtCreator .pri file for texta library libtextadebug
########################################################################

########################################################################
# libtextadebug

# libtextadebug TARGET
#
libtextadebug_TARGET = textadebug
libtextadebug_TEMPLATE = lib
libtextadebug_CONFIG += staticlib

# libtextadebug INCLUDEPATH
#
libtextadebug_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# libtextadebug DEFINES
#
libtextadebug_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libtextadebug OBJECTIVE_HEADERS
#
#libtextadebug_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/textadebug/main.hh \

# libtextadebug OBJECTIVE_SOURCES
#
#libtextadebug_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/textadebug/main.mm \

########################################################################
# libtextadebug HEADERS
#
libtextadebug_HEADERS += \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cDebug.hpp \

# libtextadebug SOURCES
#
libtextadebug_SOURCES += \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cDebug.cpp \

########################################################################



