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
#   File: xslcgi.pri
#
# Author: $author$
#   Date: 9/9/2021
#
# QtCreator .pri file for medusaxde executable xslcgi
########################################################################

########################################################################
# xslcgi

# xslcgi TARGET
#
xslcgi_TARGET = xslcgi

# xslcgi INCLUDEPATH
#
xslcgi_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# xslcgi DEFINES
#
xslcgi_DEFINES += \
$${medusaxde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# xslcgi OBJECTIVE_HEADERS
#
#xslcgi_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/medusaxde/app/console/xslcgi/main.hh \

# xslcgi OBJECTIVE_SOURCES
#
#xslcgi_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/medusaxde/app/console/xslcgi/main.mm \

########################################################################
# xslcgi HEADERS
#
xslcgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# xslcgi SOURCES
#
xslcgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${xde_t_function_SOURCES} \

########################################################################
# xslcgi FRAMEWORKS
#
xslcgi_FRAMEWORKS += \
$${medusaxde_FRAMEWORKS} \
$${xde_FRAMEWORKS} \

# xslcgi LIBS
#
xslcgi_LIBS += \
$${medusaxde_LIBS} \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core
