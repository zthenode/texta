    /**
     **********************************************************************
     * Function: OnCGIBeforeIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    virtual eError OnCGIBeforeIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIAfter = &cDerives::OnCGIBetweenIncludeL;
        if ((chars = m_begin.HasChars(length)))
        if (0 < (length = m_beginIncludeL.Assign(chars)))
        if ((chars = m_beginIncludeL.HasChars(length)))
            m_beginIncludeLChars = chars;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIBetweenIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    eError OnCGIBetweenIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIAfter = &cDerives::OnCGIAfterIncludeL;
        if ((chars = m_end.HasChars(length)))
        if (0 < (length = m_middleL.Assign(chars)))
        if ((chars = m_middleL.HasChars(length)))
            m_middleLChars = chars;
        m_end.Clear();
        m_endChars = DEFAULT_END_CHARS;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCGIAfterIncludeL
     *
     *   Author: $author$
     *     Date: 9/4/2008
     **********************************************************************
     */
    eError OnCGIAfterIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        const char* chars;
        TLENGTH length;
        CDBF("(%s)\n", text);
        m_onCGIAfter = 0;
        if ((chars = m_end.HasChars(length)))
        if (0 < (length = m_endL.Assign(chars)))
        if ((chars = m_endL.HasChars(length)))
            m_endLChars = chars;
        return error;
    }
