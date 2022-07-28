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
#   File: evuuid.pri
#
# Author: $author$
#   Date: 10/6/2021
#
# QtCreator .pri file for evx executable evuuid
########################################################################

########################################################################
# evuuid

# evuuid TARGET
#
evuuid_TARGET = evuuid

# evuuid INCLUDEPATH
#
evuuid_INCLUDEPATH += \
$${evx_INCLUDEPATH} \

# evuuid DEFINES
#
evuuid_DEFINES += \
$${evx_DEFINES} \

#DEFAULT_LOGGING_LEVELS_ERROR \
#EVCRYPTO_MAIN_INSTANCE \

########################################################################
# evuuid OBJECTIVE_HEADERS
#
#evuuid_OBJECTIVE_HEADERS += \
#$${EVX_SRC}/evcrypto/main.hh \

# evuuid OBJECTIVE_SOURCES
#
#evuuid_OBJECTIVE_SOURCES += \
#$${EVX_SRC}/evcrypto/main.mm \

########################################################################
# evuuid HEADERS
#
#evuuid_HEADERS += \
#$${EVX_SRC}/evcrypto/main.hpp \

# evuuid SOURCES
#
#evuuid_SOURCES += \
#$${EVX_SRC}/evcrypto/main.cpp \

########################################################################
# evuuid FRAMEWORKS
#
evuuid_FRAMEWORKS += \
$${evx_FRAMEWORKS} \

# evuuid LIBS
#
evuuid_LIBS += \
$${evx_LIBS} \

########################################################################
# NO Qt
#QT -= gui core


