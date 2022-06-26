/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cuuid.hxx
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
#ifndef CUUID_HXX
#define CUUID_HXX

#include "ccryptobase.hxx"
#if defined(WINDOWS)
#include "cuuidentifier.hxx"
#else /// defined(WINDOWS)
#include "xos/network/universal/unique/os/identifier.hpp"
#endif /// defined(WINDOWS)

/**
 **********************************************************************
 *  Class: cUuid
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
class cUuid: public cCryptoBase {
protected:
#if defined(WINDOWS)
    cUUIdentifier  m_identifier;
#else /// defined(WINDOWS)
    xos::network::universal::unique::os::identifier m_identifier;
#endif ///defined(WINDOWS)
public:
    typedef cCryptoBase cExtends;
    typedef cUuid cDerives;
    /**
     **********************************************************************
     * Constructor: cUuid / Destructor: ~cUuid
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    cUuid() {
    }
    virtual ~cUuid() {
    }
    /**
     **********************************************************************
     * Function: Generate
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    virtual BOOL Generate(cString& id) {
#if defined(WINDOWS)
        if ((m_identifier.Generate(id))) {
            return TRUE;
        } else {
        }
#else /// defined(WINDOWS)
        if ((m_identifier.generate())) {
            const char* chars = 0; size_t length = 0;
            if ((chars = m_identifier.string().chars(length))) {
                id.Assign(chars, length);
                return TRUE;
            }
        }
#endif /// defined(WINDOWS)
        return FALSE;
    }
}; /* class cUuid */

#endif /* ndef CUUID_HXX */
