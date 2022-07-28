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
#   File: libev2crypto.pri
#
# Author: $author$
#   Date: 10/6/2021
#
# QtCreator .pri file for evx library libev2crypto
########################################################################

########################################################################
# libev2crypto

# libev2crypto TARGET
#
libev2crypto_TARGET = ev2crypto
libev2crypto_TEMPLATE = lib
libev2crypto_CONFIG += staticlib

# libev2crypto INCLUDEPATH
#
libev2crypto_INCLUDEPATH += \
$${evx_INCLUDEPATH} \

# libev2crypto DEFINES
#
libev2crypto_DEFINES += \
$${evx_DEFINES} \

#DEFAULT_LOGGING_LEVELS_ERROR \
#EVCRYPTO_MAIN_INSTANCE \

########################################################################
# libev2crypto OBJECTIVE_HEADERS
#
#libev2crypto_OBJECTIVE_HEADERS += \
#$${EVX_SRC}/evcrypto/main.hh \

# libev2crypto OBJECTIVE_SOURCES
#
#libev2crypto_OBJECTIVE_SOURCES += \
#$${EVX_SRC}/evcrypto/main.mm \

########################################################################
# libev2crypto HEADERS
#
#libev2crypto_HEADERS += \
#$${EVX_SRC}/evcrypto/main.hpp \

# libev2crypto SOURCES
#
#libev2crypto_SOURCES += \
#$${EVX_SRC}/evcrypto/main.cpp \

########################################################################



