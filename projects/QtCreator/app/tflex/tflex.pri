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
#   File: tflex.pri
#
# Author: $author$
#   Date: 9/5/2021
#
# QtCreator .pri file for xde executable tflex
########################################################################

########################################################################
# tflex
TFLEX_SRC = $${XDE_SRC}/capp/tflex

# tflex TARGET
#
tflex_TARGET = tflex

# tflex INCLUDEPATH
#
tflex_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# tflex DEFINES
#
tflex_DEFINES += \
$${xde_DEFINES} \

########################################################################
# tflex OBJECTIVE_HEADERS
#
#tflex_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/app/console/tflex/main.hh \

# tflex OBJECTIVE_SOURCES
#
#tflex_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/app/console/tflex/main.mm \

########################################################################
# tflex HEADERS
#
tflex_HEADERS += \

# tflex SOURCES
#
tflex_SOURCES += \
$${TFLEX_SRC}/ccl.c \
$${TFLEX_SRC}/dfa.c \
$${TFLEX_SRC}/ecs.c \
$${TFLEX_SRC}/gen.c \
$${TFLEX_SRC}/misc.c \
$${TFLEX_SRC}/nfa.c \
$${TFLEX_SRC}/parse.c \
$${TFLEX_SRC}/scan.c \
$${TFLEX_SRC}/skel.c \
$${TFLEX_SRC}/sym.c \
$${TFLEX_SRC}/tblcmp.c \
$${TFLEX_SRC}/yylex.c \
$${TFLEX_SRC}/main.c \

########################################################################
# tflex FRAMEWORKS
#
#tflex_FRAMEWORKS += \
#$${xde_FRAMEWORKS} \

# tflex LIBS
#
#tflex_LIBS += \
#$${xde_LIBS} \


