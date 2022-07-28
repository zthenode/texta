///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: version.cpp
///
/// Author: $author$
///   Date: 12/19/2018, 2/13/2021
///////////////////////////////////////////////////////////////////////
#include "coral/lib/coral/version.hpp"

#if !defined(CORAL_LIB_CORAL_VERSION_NAME)
#if !defined(NO_USE_NADIR_BASE)
#define CORAL_LIB_CORAL_VERSION_NAME "libncoral"
#else // !defined(NO_USE_NADIR_BASE)
#define CORAL_LIB_CORAL_VERSION_NAME "libcoral"
#endif // !defined(NO_USE_NADIR_BASE)
#endif // !defined(CORAL_LIB_CORAL_VERSION_NAME)

#if !defined(CORAL_LIB_CORAL_VERSION_MAJOR)
#define CORAL_LIB_CORAL_VERSION_MAJOR 0
#endif // !defined(CORAL_LIB_CORAL_VERSION_MAJOR)

#if !defined(CORAL_LIB_CORAL_VERSION_MINOR)
#define CORAL_LIB_CORAL_VERSION_MINOR 0
#endif // !defined(CORAL_LIB_CORAL_VERSION_MINOR)

#if !defined(CORAL_LIB_CORAL_VERSION_RELEASE)
#define CORAL_LIB_CORAL_VERSION_RELEASE 0
#endif // !defined(CORAL_LIB_CORAL_VERSION_RELEASE)

namespace coral {
namespace lib {
namespace coral {

namespace which {
typedef lib::version version_implements;
///////////////////////////////////////////////////////////////////////
///  Class: version
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS version: virtual public version_implements {
public:
    typedef version_implements implements;
    version() {
    }
    virtual const char_t* name() const {
        return CORAL_LIB_CORAL_VERSION_NAME;
    }
    virtual unsigned major() const {
        return CORAL_LIB_CORAL_VERSION_MAJOR;
    }
    virtual unsigned minor() const {
        return CORAL_LIB_CORAL_VERSION_MINOR;
    }
    virtual unsigned release() const {
        return CORAL_LIB_CORAL_VERSION_RELEASE;
    }
};
} // namespace which

///////////////////////////////////////////////////////////////////////
///  Class: version
///////////////////////////////////////////////////////////////////////
const lib::version& version::which() {
    static const which::version version;
    return version;
}

} /// namespace coral
} /// namespace lib
} /// namespace coral
