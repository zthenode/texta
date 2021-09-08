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
#   File: evx.pri
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pri file for evx
########################################################################

OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}


########################################################################
# evx
EVX_NAME = evx
EVX_SOURCE = source/$${EVX_NAME}
EVX_LIBRARY_NAME = ev

EVX_PKG = ../../../../..
EVX_BLD = ../..

EVX_PRJ = $${EVX_PKG}
EVX_BIN = $${EVX_BLD}/bin
EVX_LIB = $${EVX_BLD}/lib
EVX_SRC = $${EVX_PKG}/$${EVX_SOURCE}

# evx BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
evx_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
evx_DEFINES += RELEASE_BUILD
}

# evx INCLUDEPATH
#
evx_INCLUDEPATH += \
$${EVX_SRC}/ev2c/ev2crypto \
$${EVX_SRC}/ev2c/crypto \
$${EVX_SRC}/ev2c \
$${EVX_SRC}/evc \
$${EVX_SRC}/ev2c/mpint/bn \
$${EVX_SRC}/evcrypto \
$${EVX_SRC}/os/evdebug \
$${EVX_SRC}/os/evx \
$${EVX_SRC}/os \
$${EVX_SRC}/base \
$${EVX_SRC} \
$${build_evx_INCLUDEPATH} \

# evx DEFINES
#
evx_DEFINES += \
$${build_evx_DEFINES} \

# evx LIBS
#
evx_LIBS += \
-L$${EVX_LIB}/lib$${EVX_LIBRARY_NAME} \
-l$${EVX_LIBRARY_NAME} \

# evx debug LIBS
#
evx_debug_LIBS += \
-L$${EVX_LIB}/lib$${EVX_LIBRARY_NAME}debug \
-l$${EVX_LIBRARY_NAME}debug \

# evx crypto LIBS
#
evx_crypto_LIBS += \
-L$${EVX_LIB}/lib$${EVX_LIBRARY_NAME}crypto \
-l$${EVX_LIBRARY_NAME}crypto \
-L$${EVX_LIB}/lib$${EVX_LIBRARY_NAME}2crypto \
-l$${EVX_LIBRARY_NAME}2crypto \

# evx rsa LIBS
#
evx_rsa_LIBS += \
-L$${EVX_LIB}/lib$${EVX_LIBRARY_NAME}bn \
-l$${EVX_LIBRARY_NAME}bn \
