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
#   File: libtxtdebug.pri
#
# Author: $author$
#   Date: 9/6/2021
#
# QtCreator .pri file for texta library libtxtdebug
########################################################################

########################################################################
# libtxtdebug

# libtxtdebug TARGET
#
libtxtdebug_TARGET = txtdebug
libtxtdebug_TEMPLATE = lib
libtxtdebug_CONFIG += staticlib

# libtxtdebug INCLUDEPATH
#
libtxtdebug_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# libtxtdebug DEFINES
#
libtxtdebug_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libtxtdebug OBJECTIVE_HEADERS
#
#libtxtdebug_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/txtdebug/main.hh \

# libtxtdebug OBJECTIVE_SOURCES
#
#libtxtdebug_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/txtdebug/main.mm \

########################################################################
# libtxtdebug HEADERS
#
libtxtdebug_HEADERS += \
$${XDE_SRC}/clib/cos/cdebug_printf.h \

# libtxtdebug SOURCES
#
libtxtdebug_SOURCES += \
$${XDE_SRC}/clib/cos/cdebug_printf.c \

########################################################################



