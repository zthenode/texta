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
#   File: medusaxde.pri
#
# Author: $author$
#   Date: 9/9/2021
#
# Os specific QtCreator .pri file for medusaxde
########################################################################

UNAME = $$system(uname)

contains(UNAME,Darwin) {
MEDUSAXDE_OS = macosx
} else {
contains(UNAME,Linux) {
MEDUSAXDE_OS = linux
} else {
MEDUSAXDE_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,MEDUSAXDE_OS) {
MEDUSAXDE_BUILD = $${MEDUSAXDE_OS}
} else {
MEDUSAXDE_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,MEDUSAXDE_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(MEDUSAXDE_OS,macosx) {
} else {
contains(MEDUSAXDE_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(MEDUSAXDE_OS,windows) {
} else {
} # contains(MEDUSAXDE_OS,windows)
} # contains(MEDUSAXDE_OS,linux)
} # contains(MEDUSAXDE_OS,macosx)

########################################################################
# medusaxde

# medusaxde INCLUDEPATH
#
medusaxde_INCLUDEPATH += \

# medusaxde DEFINES
#
medusaxde_DEFINES += \

# medusaxde LIBS
#
medusaxde_LIBS += \
$${build_medusaxde_LIBS} \

contains(MEDUSAXDE_OS,macosx|linux) {
medusaxde_LIBS += \
-lpthread \
-ldl
} else {
} # contains(MEDUSAXDE_OS,macosx|linux)

contains(MEDUSAXDE_OS,linux) {
medusaxde_LIBS += \
-lrt
} else {
} # contains(MEDUSAXDE_OS,linux)


