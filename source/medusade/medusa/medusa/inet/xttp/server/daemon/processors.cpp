///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: processors.cpp
///
/// Author: $author$
///   Date: 2/19/2016
///////////////////////////////////////////////////////////////////////
#include "medusa/inet/xttp/server/daemon/processors.hpp"
#include "medusa/inet/xttp/server/daemon/hello/processors.hpp"
#include "medusa/inet/xttp/server/daemon/http/processor.hpp"

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

///////////////////////////////////////////////////////////////////////
///  Class: processorst
///////////////////////////////////////////////////////////////////////

} // namespace daemon
} // namespace server 
} // namespace xttp 
} // namespace inet 
} // namespace medusa 

namespace medusa {
namespace inet {
namespace xttp {
namespace server {
namespace daemon {

namespace http {
static processor the_processor;

namespace path {
namespace servlet {
static processor the_processor;
} // namespace servlet
} // namespace path

namespace method {
namespace get {
static processor the_processor;
} // namespace get
} // namespace method
} // namespace http

namespace hello {
namespace hello {
static processor the_processor;
} // namespace hello
namespace bye {
static processor the_processor;
} // namespace bye
} // namespace hello

} // namespace daemon
} // namespace server
} // namespace xttp
} // namespace inet
} // namespace medusa
