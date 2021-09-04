#include <defs.h>

/*  The banner used here should be replaced with an #ident directive    */
/*  if the target C compiler supports #ident directives.        */
/*                                    */
/*  If the skeleton is changed, the banner should be changed so that    */
/*  the altered version can easily be distinguished from the original.    */

char *version = "1.8++ (Berkeley) 01/20/90, ($author$) 1998";

char *classname[] = {"","yyIsParser::"};

char *linkage[] = {"static ",""};

char *banner[] =
{
    "#ifndef lint",
    "%%static char yysccsid[] = \"@(#)yaccpar %v\";",
    "#endif",
    "#define YYBYACC 1",
	"%+",
	"#define YYCPLUSPLUS 1",
    0
};


char *tables[] =
{
    "%-",
    "extern short yylhs[];",
    "extern short yylen[];",
    "extern short yydefred[];",
    "extern short yydgoto[];",
    "extern short yysindex[];",
    "extern short yyrindex[];",
    "extern short yygindex[];",
    "extern short yytable[];",
    "extern short yycheck[];",
    "#if YYDEBUG",
    "extern char *yyname[];",
    "extern char *yyrule[];",
    "#endif",
    0
};


char *header[] =
{
    "#define yyclearin (yychar=(-1))",
    "#define yyerrok (yyerrflag=0)",
    "#ifdef YYSTACKSIZE",
    "#ifndef YYMAXDEPTH",
    "#define YYMAXDEPTH YYSTACKSIZE",
    "#endif",
    "#else",
    "#ifdef YYMAXDEPTH",
    "#define YYSTACKSIZE YYMAXDEPTH",
    "#else",
    "#define YYSTACKSIZE 500",
    "#define YYMAXDEPTH 500",
    "#endif",
    "#endif",
    "%-",
    "static int yydebug;",
    "static int yynerrs;",
    "static int yyerrflag;",
    "static int yychar;",
    "static short *yyssp;",
    "static YYSTYPE *yyvsp;",
    "static YYSTYPE yyval;",
    "static YYSTYPE yylval;",
    "static short yyss[YYSTACKSIZE];",
    "static YYSTYPE yyvs[YYSTACKSIZE];",
    "%*",
    "#define yystacksize YYSTACKSIZE",
    0
};


char *body[] =
{
    "#define YYABORT goto yyabort",
    "#define YYACCEPT goto yyaccept",
    "#define YYERROR goto yyerrlab",
	"",
    "%+",
    "yyIsParser::yyIsParser()",
    "{",
    "    yyss = 0;",
    "    yyvs = 0;",
    "}",
    "",
    "yyIsParser::~yyIsParser()",
    "{",
    "    yyfinish();",
    "}",
    "",
    "int yyIsParser::yyinit()",
    "{",
    "    while (!yyss)",
    "        if ((yyss = new short[YYSTACKSIZE]) == 0)",
    "        if (yyoutofmemory())",
    "            return 0;",
    "",
    "    while (!yyvs)",
    "        if ((yyvs= new YYSTYPE[YYSTACKSIZE]) == 0)",
    "        if (yyoutofmemory())",
    "            return 0;",
    "",
    "    return 1;",
    "}",
	"",
    "void yyIsParser::yyfinish()",
    "{",
    "    if (yyvs)",
    "    {",
    "        delete yyvs;",
    "        yyvs = 0;",
    "    }",
    "    if (yyss)",
    "    {",
    "        delete yyss;",
    "        yyss = 0;",
    "    }",
    "}",
	"",
    "int yyIsParser::yyoutofmemory()",
    "{",
    "    yyerror(\"out of memory\");",
    "    return 1;",
    "}",
	"",
    "void yyIsParser::yyerror(const char *msg)",
    "{",
    "   yyprintf(\"%s\\n\",msg);",
    "}",
    "",
    "int yyIsParser::yyprintf( const char* format, ... )",
    "{",
    "   va_list arg;",
    "   int result;",
    "",
    "   va_start(arg,format);",
    "   result=vprintf(format,arg);",
    "   va_end(arg);",
    "   return result;",
    "}",
    "",
    "int yyParser::yyparse()",
    "%-",
    "#ifdef YYDEBUG",
    "extern int yyprintf(const char *format,...);",
    "#endif",
    "",
    "int yyparse()",
    "%*",
    "{",
    "    register int yym, yyn, yystate;",
    "#if YYDEBUG",
    "    register char *yys;",
    "#endif",
    "",
    "    yynerrs = 0;",
    "    yyerrflag = 0;",
    "    yychar = (-1);",
    "",
	"%+",
    "    if (!yyinit())",
	"        goto yyabort;",
	"%*",
    "    yyssp = yyss;",
    "    yyvsp = yyvs;",
    "    *yyssp = yystate = 0;",
    "",
    "yyloop:",
    "    if (yyn = yydefred[yystate]) goto yyreduce;",
    "    if (yychar < 0)",
    "    {",
    "        if ((yychar = yylex()) < 0) yychar = 0;",
    "#if YYDEBUG",
    "        if (yydebug)",
    "        {",
    "            yys = 0;",
    "            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "            if (!yys) yys = \"illegal-symbol\";",
    "            yyprintf(\"yydebug: state %d, reading %d (%s)\\n\", yystate,",
    "                    yychar, yys);",
    "        }",
    "#endif",
    "    }",
    "    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "    {",
    "#if YYDEBUG",
    "        if (yydebug)",
    "            yyprintf(\"yydebug: state %d, shifting to state %d\\n\",",
    "                    yystate, yytable[yyn]);",
    "#endif",
    "        if (yyssp >= yyss + yystacksize - 1)",
    "        {",
    "            goto yyoverflow;",
    "        }",
    "        *++yyssp = yystate = yytable[yyn];",
    "        *++yyvsp = yylval;",
    "        yychar = (-1);",
    "        if (yyerrflag > 0)  --yyerrflag;",
    "        goto yyloop;",
    "    }",
    "    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)",
    "    {",
    "        yyn = yytable[yyn];",
    "        goto yyreduce;",
    "    }",
    "    if (yyerrflag) goto yyinrecovery;",
    "#ifdef lint",
    "    goto yynewerror;",
    "#endif",
    "yynewerror:",
    "    yyerror(\"syntax error\");",
    "#ifdef lint",
    "    goto yyerrlab;",
    "#endif",
    "yyerrlab:",
    "    ++yynerrs;",
    "yyinrecovery:",
    "    if (yyerrflag < 3)",
    "    {",
    "        yyerrflag = 3;",
    "        for (;;)",
    "        {",
    "            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&",
    "                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)",
    "            {",
    "#if YYDEBUG",
    "                if (yydebug)",
    "                    yyprintf(\"yydebug: state %d, error recovery shifting\\",
    " to state %d\\n\", *yyssp, yytable[yyn]);",
    "#endif",
    "                if (yyssp >= yyss + yystacksize - 1)",
    "                {",
    "                    goto yyoverflow;",
    "                }",
    "                *++yyssp = yystate = yytable[yyn];",
    "                *++yyvsp = yylval;",
    "                goto yyloop;",
    "            }",
    "            else",
    "            {",
    "#if YYDEBUG",
    "                if (yydebug)",
    "                    yyprintf(\"yydebug: error recovery discarding state %d\\\n\",",
    "                            *yyssp);",
    "#endif",
    "                if (yyssp <= yyss) goto yyabort;",
    "                --yyssp;",
    "                --yyvsp;",
    "            }",
    "        }",
    "    }",
    "    else",
    "    {",
    "        if (yychar == 0) goto yyabort;",
    "#if YYDEBUG",
    "        if (yydebug)",
    "        {",
    "            yys = 0;",
    "            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "            if (!yys) yys = \"illegal-symbol\";",
    "            yyprintf(\"yydebug: state %d, error recovery discards token %d (%s)\\n\",",
    "                    yystate, yychar, yys);",
    "        }",
    "#endif",
    "        yychar = (-1);",
    "        goto yyloop;",
    "    }",
    "yyreduce:",
    "#if YYDEBUG",
    "    if (yydebug)",
    "        yyprintf(\"yydebug: state %d, reducing by rule %d (%s)\\n\",",
    "                yystate, yyn, yyrule[yyn]);",
    "#endif",
    "    yym = yylen[yyn];",
    "    yyval = yyvsp[1-yym];",
    "    switch (yyn)",
    "    {",
    0
};


char *trailer[] =
{
    "    }",
    "    yyssp -= yym;",
    "    yystate = *yyssp;",
    "    yyvsp -= yym;",
    "    yym = yylhs[yyn];",
    "    if (yystate == 0 && yym == 0)",
    "    {",
    "#if YYDEBUG",
    "        if (yydebug)",
    "            yyprintf(\"yydebug: after reduction, shifting from state 0 to\\",
    " state %d\\n\", YYFINAL);",
    "#endif",
    "        yystate = YYFINAL;",
    "        *++yyssp = YYFINAL;",
    "        *++yyvsp = yyval;",
    "        if (yychar < 0)",
    "        {",
    "            if ((yychar = yylex()) < 0) yychar = 0;",
    "#if YYDEBUG",
    "            if (yydebug)",
    "            {",
    "                yys = 0;",
    "                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];",
    "                if (!yys) yys = \"illegal-symbol\";",
    "                yyprintf(\"yydebug: state %d, reading %d (%s)\\n\",",
    "                        YYFINAL, yychar, yys);",
    "            }",
    "#endif",
    "        }",
    "        if (yychar == 0) goto yyaccept;",
    "        goto yyloop;",
    "    }",
    "    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&",
    "            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)",
    "        yystate = yytable[yyn];",
    "    else",
    "        yystate = yydgoto[yym];",
    "#if YYDEBUG",
    "    if (yydebug)",
    "        yyprintf(\"yydebug: after reduction, shifting from state %d \\",
    "to state %d\\n\", *yyssp, yystate);",
    "#endif",
    "    if (yyssp >= yyss + yystacksize - 1)",
    "    {",
    "        goto yyoverflow;",
    "    }",
    "    *++yyssp = yystate;",
    "    *++yyvsp = yyval;",
    "    goto yyloop;",
    "yyoverflow:",
    "    yyerror(\"yacc stack overflow\");",
    "yyabort:",
    "    return (1);",
    "yyaccept:",
    "    return (0);",
    "}",
    0
};


write_section(section)
char *section[];
{
    register int i,j;
    register int out;
    register FILE *fp;
    register char c;

    out = 1;
    fp = code_file;
    for (i = 0; section[i]; ++i)
    {
    if (section[i][0] == '%')
    switch(section[i][1])
    {
    case '-':
        out = !cppflag;
        break;
    case '+':
        out = cppflag;
        break;
    case '*':
        out = 1;
        break;
    case '%':
        if (out)
        {
            for (j=0; (c=section[i][j])!=0; j++)
            switch(c)
            {
            case '%':
                switch(section[i][j+1])
                {
                case 'v':
                    fprintf(fp, "%s", version);
                    j++;
                    break;
                }
                break;
            default:
                fprintf(fp, "%c", c);
            }
        ++outline;
        fprintf(fp, "\n");
        }
        break;
    }
    else 
    if (out)
    {
    ++outline;
    fprintf(fp, "%s\n", section[i]);
    }
    }
	return 1;
}
