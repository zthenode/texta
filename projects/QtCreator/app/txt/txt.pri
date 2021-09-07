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
#   File: txt.pri
#
# Author: $author$
#   Date: 9/6/2021
#
# QtCreator .pri file for texta executable txt
########################################################################

########################################################################
# txt

# txt TARGET
#
txt_TARGET = txt

# txt INCLUDEPATH
#
txt_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# txt DEFINES
#
txt_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# txt OBJECTIVE_HEADERS
#
#txt_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/txt/main.hh \

# txt OBJECTIVE_SOURCES
#
#txt_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/txt/main.mm \

########################################################################
# txt HEADERS
#
txt_HEADERS += \
$${XDE_SRC}/clib/ct/ctmain.hxx \
$${XDE_SRC}/clib/cos/argmain.hxx \

# txt SOURCES
#
txt_SOURCES += \
$${XDE_SRC}/clib/ct/ctmain.cxx \
$${XDE_SRC}/clib/cos/argmain.cxx \
$${xde_t_function_SOURCES} \

########################################################################
# txt FRAMEWORKS
#
txt_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# txt LIBS
#
txt_LIBS += \
$${texta_LIBS} \
$${xde_LIBS} \
$${xdedebug_LIBS} \


