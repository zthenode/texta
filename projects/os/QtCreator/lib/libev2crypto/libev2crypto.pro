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
#   File: libev2crypto.pro
#
# Author: $author$
#   Date: 10/6/2021
#
# QtCreator .pro file for evx library libev2crypto
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/lib/libev2crypto/libev2crypto.pri)

TARGET = $${libev2crypto_TARGET}
TEMPLATE = $${libev2crypto_TEMPLATE}
CONFIG += $${libev2crypto_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libev2crypto_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libev2crypto_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libev2crypto_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libev2crypto_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libev2crypto_HEADERS} \
$${libev2crypto_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libev2crypto_SOURCES} \

########################################################################


