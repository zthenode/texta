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
#   File: evls.pri
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pri file for evx executable evls
########################################################################

########################################################################
# evls

# evls TARGET
#
evls_TARGET = evls

# evls INCLUDEPATH
#
evls_INCLUDEPATH += \
$${evx_INCLUDEPATH} \

# evls DEFINES
#
evls_DEFINES += \
$${evx_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# evls OBJECTIVE_HEADERS
#
#evls_OBJECTIVE_HEADERS += \
#$${EVX_SRC}/evx/app/console/evls/main.hh \

# evls OBJECTIVE_SOURCES
#
#evls_OBJECTIVE_SOURCES += \
#$${EVX_SRC}/evx/app/console/evls/main.mm \

########################################################################
# evls HEADERS
#
evls_HEADERS += \
$${EVX_SRC}/app/evls/evls.hpp \
$${EVX_SRC}/os/evmain.hpp \

# evls SOURCES
#
evls_SOURCES += \
$${EVX_SRC}/app/evls/evls.cpp \
$${EVX_SRC}/os/evmain.cpp \

########################################################################
# evls FRAMEWORKS
#
evls_FRAMEWORKS += \
$${evx_FRAMEWORKS} \

# evls LIBS
#
evls_LIBS += \
$${evx_LIBS} \
$${evx_debug_LIBS} \

########################################################################
# NO Qt
QT -= gui core


