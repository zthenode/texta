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
#   File: evcp.pri
#
# Author: $author$
#   Date: 9/27/2021
#
# QtCreator .pri file for evx executable evcp
########################################################################

########################################################################
# evcp

# evcp TARGET
#
evcp_TARGET = evcp

# evcp INCLUDEPATH
#
evcp_INCLUDEPATH += \
$${evx_INCLUDEPATH} \

# evcp DEFINES
#
evcp_DEFINES += \
$${evx_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# evcp OBJECTIVE_HEADERS
#
#evcp_OBJECTIVE_HEADERS += \
#$${EVX_SRC}/app/evcp/main.hh \

# evcp OBJECTIVE_SOURCES
#
#evcp_OBJECTIVE_SOURCES += \
#$${EVX_SRC}/app/evcp/main.mm \

########################################################################
# evcp HEADERS
#
evcp_HEADERS += \
$${EVX_SRC}/app/evcp/evcp.hpp \
$${EVX_SRC}/os/evmain.hpp \

# evcp SOURCES
#
evcp_SOURCES += \
$${EVX_SRC}/app/evcp/evcp.cpp \
$${EVX_SRC}/os/evmain.cpp \

########################################################################
# evcp FRAMEWORKS
#
evcp_FRAMEWORKS += \
$${evx_FRAMEWORKS} \

# evcp LIBS
#
evcp_LIBS += \
$${evx_LIBS} \
$${evx_debug_LIBS} \

########################################################################
# NO Qt
QT -= gui core
