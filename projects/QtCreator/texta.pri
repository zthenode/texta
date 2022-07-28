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
#   File: texta.pri
#
# Author: $author$
#   Date: 9/6/2021, 7/27/2022
#
# QtCreator .pri file for texta
########################################################################
# depends xde;medusade;rostra;nadir;fila;crono;cifra;rete;stara

OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}

########################################################################
# xde
XDE_VERSION_MAJOR = 0
XDE_VERSION_MINOR = 0
XDE_VERSION_RELEASE = 0
XDE_VERSION = $${XDE_VERSION_MAJOR}.$${XDE_VERSION_MINOR}.$${XDE_VERSION_RELEASE}
XDE_NAME = xde
XDE_GROUP = $${XDE_NAME}
XDE_SOURCE = source/$${XDE_NAME}
XDE_DIR = $${XDE_GROUP}/$${XDE_NAME}-$${XDE_VERSION}
XDE_PKG_DIR = $${XDE_NAME}
XDE_HOME_BUILD = $${HOME}/build/$${XDE_NAME}
XDE_HOME_BUILD_INCLUDE = $${XDE_HOME_BUILD}/include
XDE_HOME_BUILD_LIB = $${XDE_HOME_BUILD}/lib
XDE_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${XDE_DIR}
XDE_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${XDE_DIR}
XDE_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${XDE_PKG_DIR}
XDE_THIRDPARTY_SRC_GROUP = $${XDE_NAME}
XDE_THIRDPARTY_SRC_NAME = $${XDE_NAME}
XDE_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${XDE_THIRDPARTY_SRC_GROUP}/$${XDE_THIRDPARTY_SRC_NAME} 
XDE_PKG = $${OTHER_PKG}/$${XDE_PKG_DIR}
XDE_PRJ = $${OTHER_PRJ}/$${XDE_PKG_DIR}
#XDE_SRC = $${XDE_THIRDPARTY_SRC_DIR}
#XDE_SRC = $${XDE_THIRDPARTY_PKG}/$${XDE_SOURCE}
#XDE_SRC = $${XDE_THIRDPARTY_PRJ}/$${XDE_SOURCE}
#XDE_SRC = $${XDE_PKG}/$${XDE_SOURCE}
#XDE_SRC = $${XDE_PRJ}/$${XDE_SOURCE}
XDE_SRC = $${OTHER_PRJ}/$${XDE_SOURCE}
XDE_BLD = ../..
XDE_LIB = $${XDE_BLD}/lib
XDE_LIBRARY_NAME = txt

# xde INCLUDEPATH
#
xde_INCLUDEPATH += \
$${XDE_SRC}/clib/ccgi \
$${XDE_SRC}/clib/cxttp \
$${XDE_SRC}/clib/cyy \
$${XDE_SRC}/clib/cxsl \
$${XDE_SRC}/clib/ct \
$${XDE_SRC}/clib/ccrypto \
$${XDE_SRC}/clib/ct/ctcrypto \
\
$${XDE_SRC}/clib/csocket \
$${XDE_SRC}/clib/cfs \
$${XDE_SRC}/clib/cos/cwin \
$${XDE_SRC}/clib/cos/cunix \
$${XDE_SRC}/clib/cos/cplatform \
$${XDE_SRC}/clib/cos \
\
$${XDE_SRC}/clib/cbase \
$${XDE_SRC}/clib \
$${XDE_SRC} \
$${build_xde_INCLUDEPATH} \

# xde DEFINES
#
xde_DEFINES += \
DB_PRINTF=platform_db_printf \
DB_VPRINTF=platform_db_vprintf \
$${build_xde_DEFINES} \

# xde LIBS
#
xde_LIBS += \
-L$${XDE_LIB}/lib$${XDE_LIBRARY_NAME} \
-l$${XDE_LIBRARY_NAME} \

# xdedebug LIBS
#
xdedebug_LIBS += \
-L$${XDE_LIB}/lib$${XDE_LIBRARY_NAME}debug \
-l$${XDE_LIBRARY_NAME}debug \

# xde t function HEADERS
#
xde_t_function_HEADERS += \

# xde t function SOURCES
#
xde_t_function_SOURCES += \
$${XDE_SRC}/clib/ct/ctfunctions.cxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
$${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
$${XDE_SRC}/clib/ct/ctconditionalfunctions.cxx \
$${XDE_SRC}/clib/ct/ctstringfunctions.cxx \
$${XDE_SRC}/clib/ct/ctcrypto/ctuuidfunction.cxx \

########################################################################
# medusade
MEDUSADE_VERSION_MAJOR = 0
MEDUSADE_VERSION_MINOR = 0
MEDUSADE_VERSION_RELEASE = 0
MEDUSADE_VERSION = $${MEDUSADE_VERSION_MAJOR}.$${MEDUSADE_VERSION_MINOR}.$${MEDUSADE_VERSION_RELEASE}
MEDUSADE_NAME = medusade
MEDUSADE_GROUP = $${MEDUSADE_NAME}
MEDUSADE_SOURCE = source
MEDUSADE_DIR = $${MEDUSADE_GROUP}/$${MEDUSADE_NAME}-$${MEDUSADE_VERSION}
MEDUSADE_PKG_DIR = $${MEDUSADE_NAME}
MEDUSADE_BUILD_HOME = $${HOME}
MEDUSADE_HOME_BUILD = $${MEDUSADE_BUILD_HOME}/build/$${MEDUSADE_NAME}
MEDUSADE_HOME_BUILD_INCLUDE = $${MEDUSADE_HOME_BUILD}/include
MEDUSADE_HOME_BUILD_LIB = $${MEDUSADE_HOME_BUILD}/lib
MEDUSADE_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${MEDUSADE_DIR}
MEDUSADE_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${MEDUSADE_DIR}
MEDUSADE_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${MEDUSADE_PKG_DIR}
MEDUSADE_THIRDPARTY_SRC_GROUP = $${MEDUSADE_GROUP}
MEDUSADE_THIRDPARTY_SRC_NAME = $${MEDUSADE_NAME}
MEDUSADE_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${MEDUSADE_THIRDPARTY_SRC_GROUP}/$${MEDUSADE_THIRDPARTY_SRC_NAME} 
MEDUSADE_THIRDPARTY_SOURCE = $${MEDUSADE_SOURCE}/thirdparty
MEDUSADE_PKG = $${OTHER_PKG}/$${MEDUSADE_PKG_DIR}
MEDUSADE_PRJ = $${OTHER_PRJ}/$${MEDUSADE_PKG_DIR}
#MEDUSADE_SRC = $${MEDUSADE_THIRDPARTY_SRC_DIR}
#MEDUSADE_SRC = $${MEDUSADE_THIRDPARTY_PKG}/$${MEDUSADE_SOURCE}
#MEDUSADE_SRC = $${MEDUSADE_THIRDPARTY_PRJ}/$${MEDUSADE_SOURCE}
#MEDUSADE_SRC = $${MEDUSADE_PKG}/$${MEDUSADE_SOURCE}
#MEDUSADE_SRC = $${MEDUSADE_PRJ}/$${MEDUSADE_SOURCE}
MEDUSADE_SRC = $${OTHER_PRJ}/source/$${MEDUSADE_NAME}
MEDUSADE_BLD = ../..
MEDUSADE_LIB = $${MEDUSADE_BLD}/lib
MEDUSADE_LIBRARY_NAME = $${MEDUSADE_NAME}

MEDUSADE_NADIR_SRC += $${MEDUSADE_SRC}/nadir
medusade_nadir_INCLUDEPATH += $${MEDUSADE_NADIR_SRC}
medusade_nadir_DEFINES += NO_USE_NADIR_BASE NO_USE_XOS_LOGGER_INTERFACE 

MEDUSADE_ROSTRA_SRC += $${MEDUSADE_SRC}/rostra
medusade_rostra_INCLUDEPATH += $${MEDUSADE_ROSTRA_SRC} 
medusade_rostra_DEFINES += 

MEDUSADE_MEDUSA_SRC += $${MEDUSADE_SRC}/medusa
medusade_medusa_INCLUDEPATH += $${MEDUSADE_MEDUSA_SRC} 
medusade_medusa_DEFINES += 

MEDUSADE_CORAL_SRC += $${MEDUSADE_SRC}/coral
medusade_coral_INCLUDEPATH += $${MEDUSADE_CORAL_SRC} 
medusade_coral_DEFINES += 

MEDUSADE_TALAS_SRC += $${MEDUSADE_SRC}/talas
medusade_talas_INCLUDEPATH += $${MEDUSADE_TALAS_SRC} 
medusade_talas_DEFINES += 

MEDUSADE_TEXTA_SRC += $${MEDUSADE_SRC}/texta
medusade_texta_INCLUDEPATH += $${MEDUSADE_TEXTA_SRC} 
medusade_texta_DEFINES += 

# medusade INCLUDEPATH
#
medusade_INCLUDEPATH += \
$${medusade_texta_INCLUDEPATH} \
$${medusade_coral_INCLUDEPATH} \
$${medusade_medusa_INCLUDEPATH} \
$${medusade_talas_INCLUDEPATH} \
$${medusade_rostra_INCLUDEPATH} \
$${medusade_nadir_INCLUDEPATH} \

# medusade DEFINES
#
medusade_DEFINES += \
$${medusade_nadir_DEFINES} \
$${medusade_rostra_DEFINES} \
$${medusade_talas_DEFINES} \
$${medusade_medusa_DEFINES} \
$${medusade_coral_DEFINES} \
$${medusade_texta_DEFINES} \

# medusade HEADERS
#
medusade_HEADERS += \
$${MEDUSADE_NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.h \
$${MEDUSADE_NADIR_SRC}/xos/io/main/logger.hpp \
$${MEDUSADE_NADIR_SRC}/xos/base/getopt/main_opt.hpp \

# medusade SOURCES
#
medusade_SOURCES += \
$${MEDUSADE_NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \
$${MEDUSADE_NADIR_SRC}/xos/io/main/logger.cpp \
$${MEDUSADE_NADIR_SRC}/xos/base/getopt/main_opt.cpp \

# medusade talas hash HEADERS
#
medusade_talas_hash_HEADERS += \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha512.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/sha512.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha256.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/sha256.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha1.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/sha1.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/md5.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/md5.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/mac.hpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/base.hpp \

# medusade talas hash SOURCES
#
medusade_talas_hash_SOURCES += \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha512.cpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha256.cpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/sha1.cpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/openssl/md5.cpp \
$${MEDUSADE_TALAS_SRC}/talas/crypto/hash/mac.cpp \

# medusade texta function HEADERS
#
medusade_texta_function_HEADERS += \
$${MEDUSADE_TEXTA_SRC}/texta/t/network_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/hash_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/file_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/string_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/time_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/logical_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/conditional_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/block_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/base_functions.hpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/functions.hpp \

# medusade texta function SOURCES
#
medusade_texta_function_SOURCES += \
$${MEDUSADE_TEXTA_SRC}/texta/t/network_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/hash_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/file_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/string_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/time_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/logical_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/conditional_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/block_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/base_functions.cpp \
$${MEDUSADE_TEXTA_SRC}/texta/t/functions.cpp \

# medusade texta HEADERS
#
medusade_texta_HEADERS += \
$${medusade_HEADERS} \
$${medusade_talas_hash_HEADERS} \
$${medusade_texta_function_HEADERS} \

# medusade texta SOURCES
#
medusade_texta_SOURCES += \
$${medusade_SOURCES} \
$${medusade_talas_hash_SOURCES} \
$${medusade_texta_function_SOURCES} \

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = source
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_HOME_BUILD = $${HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = $${NADIR_VERSION_MAJOR}.$${NADIR_VERSION_MINOR}.$${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = $${NADIR_NAME}
NADIR_SOURCE = source
NADIR_DIR = $${NADIR_GROUP}/$${NADIR_NAME}-$${NADIR_VERSION}
NADIR_PKG_DIR = $${NADIR_NAME}
NADIR_HOME_BUILD = $${HOME}/build/$${NADIR_NAME}
NADIR_HOME_BUILD_INCLUDE = $${NADIR_HOME_BUILD}/include
NADIR_HOME_BUILD_LIB = $${NADIR_HOME_BUILD}/lib
NADIR_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${NADIR_DIR}
NADIR_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${NADIR_DIR}
NADIR_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${NADIR_PKG_DIR}
NADIR_THIRDPARTY_SRC_GROUP = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_NAME = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${NADIR_THIRDPARTY_SRC_GROUP}/$${NADIR_THIRDPARTY_SRC_NAME} 
NADIR_PKG = $${OTHER_PKG}/$${NADIR_PKG_DIR}
NADIR_PRJ = $${OTHER_PRJ}/$${NADIR_PKG_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_SRC_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_PKG}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_THIRDPARTY_PRJ}/$${NADIR_SOURCE}
NADIR_SRC = $${NADIR_PKG}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_PRJ}/$${NADIR_SOURCE}

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \
$${NADIR_SRC} \

# nadir DEFINES
#
nadir_DEFINES += \

########################################################################
# fila
FILA_VERSION_MAJOR = 0
FILA_VERSION_MINOR = 0
FILA_VERSION_RELEASE = 0
FILA_VERSION = $${FILA_VERSION_MAJOR}.$${FILA_VERSION_MINOR}.$${FILA_VERSION_RELEASE}
FILA_NAME = fila
FILA_GROUP = $${FILA_NAME}
FILA_SOURCE = source
FILA_DIR = $${FILA_GROUP}/$${FILA_NAME}-$${FILA_VERSION}
FILA_PKG_DIR = $${FILA_NAME}
FILA_HOME_BUILD = $${HOME}/build/$${FILA_NAME}
FILA_HOME_BUILD_INCLUDE = $${FILA_HOME_BUILD}/include
FILA_HOME_BUILD_LIB = $${FILA_HOME_BUILD}/lib
FILA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${FILA_DIR}
FILA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${FILA_DIR}
FILA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${FILA_PKG_DIR}
FILA_THIRDPARTY_SRC_GROUP = $${FILA_NAME}
FILA_THIRDPARTY_SRC_NAME = $${FILA_NAME}
FILA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${FILA_THIRDPARTY_SRC_GROUP}/$${FILA_THIRDPARTY_SRC_NAME} 
FILA_PKG = $${OTHER_PKG}/$${FILA_PKG_DIR}
FILA_PRJ = $${OTHER_PRJ}/$${FILA_PKG_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_SRC_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_PKG}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_THIRDPARTY_PRJ}/$${FILA_SOURCE}
FILA_SRC = $${FILA_PKG}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_PRJ}/$${FILA_SOURCE}

# fila INCLUDEPATH
#
fila_INCLUDEPATH += \
$${FILA_SRC} \

# fila DEFINES
#
fila_DEFINES += \

########################################################################
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = $${CRONO_VERSION_MAJOR}.$${CRONO_VERSION_MINOR}.$${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = $${CRONO_NAME}
CRONO_SOURCE = source
CRONO_DIR = $${CRONO_GROUP}/$${CRONO_NAME}-$${CRONO_VERSION}
CRONO_PKG_DIR = $${CRONO_NAME}
CRONO_HOME_BUILD = $${HOME}/build/$${CRONO_NAME}
CRONO_HOME_BUILD_INCLUDE = $${CRONO_HOME_BUILD}/include
CRONO_HOME_BUILD_LIB = $${CRONO_HOME_BUILD}/lib
CRONO_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${CRONO_DIR}
CRONO_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${CRONO_DIR}
CRONO_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${CRONO_PKG_DIR}
CRONO_THIRDPARTY_SRC_GROUP = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_NAME = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${CRONO_THIRDPARTY_SRC_GROUP}/$${CRONO_THIRDPARTY_SRC_NAME} 
CRONO_PKG = $${OTHER_PKG}/$${CRONO_PKG_DIR}
CRONO_PRJ = $${OTHER_PRJ}/$${CRONO_PKG_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_SRC_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_PKG}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_THIRDPARTY_PRJ}/$${CRONO_SOURCE}
CRONO_SRC = $${CRONO_PKG}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_PRJ}/$${CRONO_SOURCE}

# crono INCLUDEPATH
#
crono_INCLUDEPATH += \
$${CRONO_SRC} \

# crono DEFINES
#
crono_DEFINES += \

########################################################################
# cifra
CIFRA_VERSION_MAJOR = 0
CIFRA_VERSION_MINOR = 0
CIFRA_VERSION_RELEASE = 0
CIFRA_VERSION = $${CIFRA_VERSION_MAJOR}.$${CIFRA_VERSION_MINOR}.$${CIFRA_VERSION_RELEASE}
CIFRA_NAME = cifra
CIFRA_GROUP = $${CIFRA_NAME}
CIFRA_SOURCE = source
CIFRA_DIR = $${CIFRA_GROUP}/$${CIFRA_NAME}-$${CIFRA_VERSION}
CIFRA_PKG_DIR = $${CIFRA_NAME}
CIFRA_HOME_BUILD = $${HOME}/build/$${CIFRA_NAME}
CIFRA_HOME_BUILD_INCLUDE = $${CIFRA_HOME_BUILD}/include
CIFRA_HOME_BUILD_LIB = $${CIFRA_HOME_BUILD}/lib
CIFRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${CIFRA_DIR}
CIFRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${CIFRA_DIR}
CIFRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${CIFRA_PKG_DIR}
CIFRA_THIRDPARTY_SRC_GROUP = $${CIFRA_NAME}
CIFRA_THIRDPARTY_SRC_NAME = $${CIFRA_NAME}
CIFRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${CIFRA_THIRDPARTY_SRC_GROUP}/$${CIFRA_THIRDPARTY_SRC_NAME} 
CIFRA_PKG = $${OTHER_PKG}/$${CIFRA_PKG_DIR}
CIFRA_PRJ = $${OTHER_PRJ}/$${CIFRA_PKG_DIR}
#CIFRA_SRC = $${CIFRA_THIRDPARTY_SRC_DIR}
#CIFRA_SRC = $${CIFRA_THIRDPARTY_PKG}/$${CIFRA_SOURCE}
#CIFRA_SRC = $${CIFRA_THIRDPARTY_PRJ}/$${CIFRA_SOURCE}
CIFRA_SRC = $${CIFRA_PKG}/$${CIFRA_SOURCE}
#CIFRA_SRC = $${CIFRA_PRJ}/$${CIFRA_SOURCE}

# cifra INCLUDEPATH
#
cifra_INCLUDEPATH += \
$${CIFRA_SRC} \

# cifra DEFINES
#
cifra_DEFINES += \

########################################################################
# rete
RETE_VERSION_MAJOR = 0
RETE_VERSION_MINOR = 0
RETE_VERSION_RELEASE = 0
RETE_VERSION = $${RETE_VERSION_MAJOR}.$${RETE_VERSION_MINOR}.$${RETE_VERSION_RELEASE}
RETE_NAME = rete
RETE_GROUP = $${RETE_NAME}
RETE_SOURCE = source
RETE_DIR = $${RETE_GROUP}/$${RETE_NAME}-$${RETE_VERSION}
RETE_PKG_DIR = $${RETE_NAME}
RETE_HOME_BUILD = $${HOME}/build/$${RETE_NAME}
RETE_HOME_BUILD_INCLUDE = $${RETE_HOME_BUILD}/include
RETE_HOME_BUILD_LIB = $${RETE_HOME_BUILD}/lib
RETE_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${RETE_DIR}
RETE_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${RETE_DIR}
RETE_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${RETE_PKG_DIR}
RETE_THIRDPARTY_SRC_GROUP = $${RETE_NAME}
RETE_THIRDPARTY_SRC_NAME = $${RETE_NAME}
RETE_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${RETE_THIRDPARTY_SRC_GROUP}/$${RETE_THIRDPARTY_SRC_NAME} 
RETE_PKG = $${OTHER_PKG}/$${RETE_PKG_DIR}
RETE_PRJ = $${OTHER_PRJ}/$${RETE_PKG_DIR}
#RETE_SRC = $${RETE_THIRDPARTY_SRC_DIR}
#RETE_SRC = $${RETE_THIRDPARTY_PKG}/$${RETE_SOURCE}
#RETE_SRC = $${RETE_THIRDPARTY_PRJ}/$${RETE_SOURCE}
RETE_SRC = $${RETE_PKG}/$${RETE_SOURCE}
#RETE_SRC = $${RETE_PRJ}/$${RETE_SOURCE}

# rete INCLUDEPATH
#
rete_INCLUDEPATH += \
$${RETE_SRC} \

# rete DEFINES
#
rete_DEFINES += \

########################################################################
# stara
STARA_VERSION_MAJOR = 0
STARA_VERSION_MINOR = 0
STARA_VERSION_RELEASE = 0
STARA_VERSION = $${STARA_VERSION_MAJOR}.$${STARA_VERSION_MINOR}.$${STARA_VERSION_RELEASE}
STARA_NAME = stara
STARA_GROUP = $${STARA_NAME}
STARA_SOURCE = source
STARA_DIR = $${STARA_GROUP}/$${STARA_NAME}-$${STARA_VERSION}
STARA_PKG_DIR = $${STARA_NAME}
STARA_HOME_BUILD = $${HOME}/build/$${STARA_NAME}
STARA_HOME_BUILD_INCLUDE = $${STARA_HOME_BUILD}/include
STARA_HOME_BUILD_LIB = $${STARA_HOME_BUILD}/lib
STARA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${STARA_DIR}
STARA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${STARA_DIR}
STARA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${STARA_PKG_DIR}
STARA_THIRDPARTY_SRC_GROUP = $${STARA_NAME}
STARA_THIRDPARTY_SRC_NAME = $${STARA_NAME}
STARA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${STARA_THIRDPARTY_SRC_GROUP}/$${STARA_THIRDPARTY_SRC_NAME} 
STARA_PKG = $${OTHER_PKG}/$${STARA_PKG_DIR}
STARA_PRJ = $${OTHER_PRJ}/$${STARA_PKG_DIR}
#STARA_SRC = $${STARA_THIRDPARTY_SRC_DIR}
#STARA_SRC = $${STARA_THIRDPARTY_PKG}/$${STARA_SOURCE}
#STARA_SRC = $${STARA_THIRDPARTY_PRJ}/$${STARA_SOURCE}
STARA_SRC = $${STARA_PKG}/$${STARA_SOURCE}
#STARA_SRC = $${STARA_PRJ}/$${STARA_SOURCE}

# stara INCLUDEPATH
#
stara_INCLUDEPATH += \
$${STARA_SRC} \

# stara DEFINES
#
stara_DEFINES += \

########################################################################
# texta
TEXTA_NAME = texta
TEXTA_SOURCE = source

TEXTA_PKG = ../../../../..
TEXTA_BLD = ../..

TEXTA_PRJ = $${TEXTA_PKG}
TEXTA_BIN = $${TEXTA_BLD}/bin
TEXTA_LIB = $${TEXTA_BLD}/lib
TEXTA_SRC = $${TEXTA_PKG}/$${TEXTA_SOURCE}

# texta BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
texta_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
texta_DEFINES += RELEASE_BUILD
}

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \
$${TEXTA_SRC} \
$${stara_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${cifra_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${fila_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_texta_INCLUDEPATH} \

# texta DEFINES
#
texta_DEFINES += \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${fila_DEFINES} \
$${crono_DEFINES} \
$${cifra_DEFINES} \
$${rete_DEFINES} \
$${stara_DEFINES} \
$${build_texta_DEFINES} \

# texta LIBS
#
texta_LIBS += \
-L$${TEXTA_LIB}/lib$${TEXTA_NAME} \
-l$${TEXTA_NAME} \

# textadebug LIBS
#
textadebug_LIBS += \
-L$${TEXTA_LIB}/lib$${TEXTA_NAME}debug \
-l$${TEXTA_NAME}debug \

########################################################################
# texta xde INCLUDEPATH
#
texta_xde_INCLUDEPATH += \
$${xde_INCLUDEPATH} \
$${texta_INCLUDEPATH} \

# texta xde DEFINES
#
texta_xde_DEFINES += \
$${texta_DEFINES} \
$${xde_DEFINES} \

########################################################################
# texta medusade INCLUDEPATH
#
texta_medusade_INCLUDEPATH += \
$${medusade_INCLUDEPATH} \
$${texta_INCLUDEPATH} \

# texta medusade DEFINES
#
texta_medusade_DEFINES += \
$${texta_DEFINES} \
$${medusade_DEFINES} \

########################################################################
# texta xde implemented HEADERS
#
texta_xde_implemented_HEADERS += \
$${xde_t_function_HEADERS} \
$${NADIR_SRC}/xos/console/main_main.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/exception.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.hpp \

#$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.hpp \

# texta xde implemented SOURCES
#
texta_xde_implemented_SOURCES += \
$${xde_t_function_SOURCES} \
$${NADIR_SRC}/xos/console/main_main.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/exception.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.cpp \

#$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.cpp \

# texta xde implemented LIBS
#
texta_xde_implemented_LIBS += \

########################################################################
# texta implemented HEADERS
#
texta_implemented_HEADERS += \
$${NADIR_SRC}/xos/console/main_main.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/exception.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.hpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.hpp \

# texta implemented SOURCES
#
texta_implemented_SOURCES += \
$${NADIR_SRC}/xos/console/main_main.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/exception.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.cpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.cpp \

# texta implemented LIBS
#
texta_implemented_LIBS += \
