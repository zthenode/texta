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
#   File: libevcrypto.pro
#
# Author: $author$
#   Date: 10/6/2021
#
# QtCreator .pro file for evx library libevcrypto
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/lib/libevcrypto/libevcrypto.pri)

TARGET = $${libevcrypto_TARGET}
TEMPLATE = $${libevcrypto_TEMPLATE}
CONFIG += $${libevcrypto_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libevcrypto_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libevcrypto_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libevcrypto_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libevcrypto_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libevcrypto_HEADERS} \
$${libevcrypto_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libevcrypto_SOURCES} \

########################################################################


