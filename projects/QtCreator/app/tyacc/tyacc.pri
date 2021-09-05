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
#   File: tyacc.pri
#
# Author: $author$
#   Date: 9/5/2021
#
# QtCreator .pri file for xde executable tyacc
########################################################################

########################################################################
# tyacc
TYACC_SRC = $${XDE_SRC}/capp/tyacc

# tyacc TARGET
#
tyacc_TARGET = tyacc

# tyacc INCLUDEPATH
#
tyacc_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# tyacc DEFINES
#
tyacc_DEFINES += \
$${xde_DEFINES} \

########################################################################
# tyacc OBJECTIVE_HEADERS
#
#tyacc_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/app/console/tyacc/main.hh \

# tyacc OBJECTIVE_SOURCES
#
#tyacc_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/app/console/tyacc/main.mm \

########################################################################
# tyacc HEADERS
#
tyacc_HEADERS += \
$${TYACC_SRC}/function_defs.h \

# tyacc SOURCES
#
tyacc_SOURCES += \
$${TYACC_SRC}/closure.c \
$${TYACC_SRC}/error.c \
$${TYACC_SRC}/lalr.c \
$${TYACC_SRC}/lr0.c \
$${TYACC_SRC}/main.c \
$${TYACC_SRC}/mkpar.c \
$${TYACC_SRC}/output.c \
$${TYACC_SRC}/reader.c \
$${TYACC_SRC}/skeleton.c \
$${TYACC_SRC}/symtab.c \
$${TYACC_SRC}/verbose.c \
$${TYACC_SRC}/warshall.c \

########################################################################
# tyacc FRAMEWORKS
#
#tyacc_FRAMEWORKS += \
#$${xde_FRAMEWORKS} \

# tyacc LIBS
#
#tyacc_LIBS += \
#$${xde_LIBS} \


