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
#   File: libtexta.pri
#
# Author: $author$
#   Date: 9/6/2021
#
# QtCreator .pri file for texta library libtexta
########################################################################

########################################################################
# libtexta

# libtexta TARGET
#
libtexta_TARGET = texta
libtexta_TEMPLATE = lib
libtexta_CONFIG += staticlib

# libtexta INCLUDEPATH
#
libtexta_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# libtexta DEFINES
#
libtexta_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libtexta OBJECTIVE_HEADERS
#
#libtexta_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/texta/main.hh \

# libtexta OBJECTIVE_SOURCES
#
#libtexta_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/texta/main.mm \

########################################################################
# libtexta HEADERS
#
libtexta_HEADERS += \
$${TEXTA_SRC}/xos/lib/texta/version.hpp \

# libtexta SOURCES
#
libtexta_SOURCES += \
$${TEXTA_SRC}/xos/lib/texta/version.cpp \

########################################################################
