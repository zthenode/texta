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
# Os specific QtCreator .pri file for evx
########################################################################

UNAME = $$system(uname)

contains(UNAME,Darwin) {
EVX_OS = macosx
} else {
contains(UNAME,Linux) {
EVX_OS = linux
} else {
EVX_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,EVX_OS) {
EVX_BUILD = $${EVX_OS}
} else {
EVX_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,EVX_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(EVX_OS,macosx) {
} else {
contains(EVX_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(EVX_OS,windows) {
} else {
} # contains(EVX_OS,windows)
} # contains(EVX_OS,linux)
} # contains(EVX_OS,macosx)

########################################################################
# evx

# evx INCLUDEPATH
#
evx_INCLUDEPATH += \

# evx DEFINES
#
evx_DEFINES += \

# evx LIBS
#
evx_LIBS += \
$${build_evx_LIBS} \

contains(EVX_OS,macosx|linux) {
evx_LIBS += \
-lpthread \
-ldl
} else {
} # contains(EVX_OS,macosx|linux)

contains(EVX_OS,linux) {
evx_LIBS += \
-lrt
} else {
} # contains(EVX_OS,linux)


