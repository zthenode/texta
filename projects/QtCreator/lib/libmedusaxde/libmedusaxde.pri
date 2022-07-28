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
#   File: libmedusaxde.pri
#
# Author: $author$
#   Date: 9/9/2021
#
# QtCreator .pri file for medusaxde library libmedusaxde
########################################################################

########################################################################
# libmedusaxde

# libmedusaxde TARGET
#
libmedusaxde_TARGET = medusaxde
libmedusaxde_TEMPLATE = lib
libmedusaxde_CONFIG += staticlib

# libmedusaxde INCLUDEPATH
#
libmedusaxde_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# libmedusaxde DEFINES
#
libmedusaxde_DEFINES += \
$${medusaxde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libmedusaxde OBJECTIVE_HEADERS
#
#libmedusaxde_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/medusaxde/app/console/medusaxde/main.hh \

# libmedusaxde OBJECTIVE_SOURCES
#
#libmedusaxde_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/medusaxde/app/console/medusaxde/main.mm \

########################################################################
# libmedusaxde HEADERS
#
libmedusaxde_HEADERS += \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorImplemented.hpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessor.hpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorInterface.hpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltParams.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXslTransformer.hxx \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltProcessorImplemented.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltProcessor.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltProcessorInterface.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParams.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParamsInterface.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParam.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParamInterface.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cXmlAttributeEncoder.hpp \
$${MEDUSAXDE_SRC}/clib/cxml/cXmlTextEncoder.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebugInstance.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebug.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebugInterface.hpp \
$${MEDUSAXDE_SRC}/clib/cbase/cBase.hpp \
$${MEDUSAXDE_SRC}/clib/cbase/cError.hpp \

# libmedusaxde SOURCES
#
libmedusaxde_SOURCES += \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorImplemented.cpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessor.cpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorInterface.cpp \
$${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltParams.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXslTransformer.cxx \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltProcessor.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltProcessorInterface.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParams.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParamsInterface.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParam.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cxslt/cXsltParamInterface.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cXmlAttributeEncoder.cpp \
$${MEDUSAXDE_SRC}/clib/cxml/cXmlTextEncoder.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebugInstance.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebug.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cDebugInterface.cpp \
$${MEDUSAXDE_SRC}/clib/cbase/cBase.cpp \

########################################################################
# libmedusaxde HEADERS
#
libmedusaxde_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform.hpp \
$${XDE_SRC}/clib/cos/cplatform/cnamespace.hpp \
$${XDE_SRC}/clib/cos/cplatform/cplatform_types.h \

# libmedusaxde SOURCES
#
libmedusaxde_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform.cpp \
$${XDE_SRC}/clib/cos/cplatform/cnamespace.cpp \

########################################################################
# libmedusaxde HEADERS
#
libmedusaxde_HEADERS += \
$${XDE_SRC}/clib/cxsl/cxsltransformerinstance.hxx \
$${XDE_SRC}/clib/cxsl/cxsltransformerinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlreaderinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlnodeinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlnodetype.hxx \

# libmedusaxde SOURCES
#
libmedusaxde_SOURCES += \
$${XDE_SRC}/clib/cxsl/cxsltransformerinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlreaderinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlnodeinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlnodetype.cxx \

########################################################################
