#include <signal.h>
#include <string.h>
#include <defs.h>

extern char *banner[];

char dflag = 0;
char lflag = 0;
char rflag = 0;
char tflag = 0;
char vflag = 0;
char cppflag = 0;

char *file_prefix = FILE_PREFIX;
char *myname = "byacc";
char *temp_form = "y_XXXXXX";

int lineno;
int outline;

char *action_file_name = 0;
char *code_file_name = 0;
char *defines_file_name = 0;
char *input_file_name = "";
char *output_file_name = 0;
char *text_file_name = 0;
char *union_file_name = 0;
char *verbose_file_name = 0;

FILE *action_file;	/*  a temp file, used to save actions associated    */
			/*  with rules until the parser is written	    */
FILE *code_file;	/*  y.code.c (used when the -r option is specified) */
FILE *defines_file;	/*  y.tab.h					    */
FILE *input_file;	/*  the input file				    */
FILE *output_file;	/*  y.tab.c					    */
FILE *text_file;	/*  a temp file, used to save text until all	    */
			/*  symbols have been defined			    */
FILE *union_file;	/*  a temp file, used to save the union		    */
			/*  definition until all symbol have been	    */
			/*  defined					    */
FILE *verbose_file;	/*  y.output					    */

int nitems;
int nrules;
int nsyms;
int ntokens;
int nvars;

int   start_symbol;
char  **symbol_name;
short *symbol_value;
short *symbol_prec;
char  *symbol_assoc;

short *ritem;
short *rlhs;
short *rrhs;
short *rprec;
char  *rassoc;
short **derives;
char *nullable;

extern char *mktemp();
extern char *getenv();


done(k)
int k;
{
    if (action_file) { fclose(action_file); unlink(action_file_name); }
    if (text_file) { fclose(text_file); unlink(text_file_name); }
    if (union_file) { fclose(union_file); unlink(union_file_name); }
    exit(k);
}


void onintr()
{
    done(1);
}


set_signals()
{
#ifdef SIGINT
    if (signal(SIGINT, SIG_IGN) != SIG_IGN)
	signal(SIGINT, onintr);
#endif
#ifdef SIGTERM
    if (signal(SIGTERM, SIG_IGN) != SIG_IGN)
	signal(SIGTERM, onintr);
#endif
#ifdef SIGHUP
    if (signal(SIGHUP, SIG_IGN) != SIG_IGN)
	signal(SIGHUP, onintr);
#endif
}


usage()
{
    static char switches[]=
	   "\n\t-+\tgenerate C++ parser"
       "\n\t-d\twrite the header file \"%y%d\""
       "\n\t-l\texclude the #line directives in files"
       "\n\t-r\tseperate code and tables into \"%y%c\" and \"%y%o\""
       "\n\t-t\tinclude the debugging code in files"
       "\n\t-v\twrite the parser description file \"%y%v\"\n"
       "\n\t-b file_prefix\tchange the default file prefix \"%y\""
       "\n\t-D header_file\tchange the default header file \"%y%d\""
       "\n\t-o output_file\tchange the default output file \"%y%o\""
       "\n\t-R code_file\tchange the default code file \"%y%c\""
       "\n\t-V description_file\tchange the default description file \"%y%v\"\n"
	   "\n\tuse \"-\" as filename to set stdin as input file\n";

    char c;
    int i;
    
    fprintf(stderr, "\nYacc %s\n", version);
    fprintf(stderr, "\nUsage: %s [-+dlrtv] [-b file_prefix] [-o output_file] [-R code_file]"
       "\n\t[-D header_file] [-V description_file] filename\n",myname);

    for (i=0; (c=switches[i])!=0; i++)
        switch(c)
        {
        case '%':
            switch(switches[i+1])
            {
            case 'y':
                fprintf(stderr,"%s",FILE_PREFIX);
                i++;
                break;
            case 'c':
                fprintf(stderr,"%s",CODE_SUFFIX);
                i++;
                break;
            case 'd':
                fprintf(stderr,"%s",DEFINES_SUFFIX);
                i++;
                break;
            case 'o':
                fprintf(stderr,"%s",OUTPUT_SUFFIX);
                i++;
                break;
            case 'v':
                fprintf(stderr,"%s",VERBOSE_SUFFIX);
                i++;
                break;
            }
            break;
        default:
            fprintf(stderr,"%c",switches[i]);
        }

    exit(1);
}


getargs(argc, argv)
int argc;
char *argv[];
{
    register int i;
    register char *s;

    if (argc > 0) myname = argv[0];
    for (i = 1; i < argc; ++i)
    {
	s = argv[i];
	if (*s != '-') break;
	switch (*++s)
	{
	case '\0':
	    if (i + 1 < argc) usage();
	    input_file = stdin;
        return;

	case '-':
	    ++i;
	    goto no_more_options;

	case '+':
	    cppflag = 1;
	    break;

	case 'b':
	    if (*++s)
		 file_prefix = s;
	    else if (++i < argc)
		file_prefix = argv[i];
	    else
		usage();
	    continue;

	case 'D':
	    if (*++s)
		 defines_file_name = s;
	    else if (++i < argc)
		defines_file_name = argv[i];
	    else
		usage();
	    dflag = 1;
	    continue;

	case 'd':
	    dflag = 1;
	    break;

	case 'l':
	    lflag = 1;
	    break;

	case 'o':
	    if (*++s)
		 output_file_name = s;
	    else if (++i < argc)
		output_file_name = argv[i];
	    else
		usage();
	    continue;

	case 'R':
	    if (*++s)
		 code_file_name = s;
	    else if (++i < argc)
		code_file_name = argv[i];
	    else
		usage();
	    rflag = 1;
	    continue;

	case 'r':
	    rflag = 1;
	    break;

	case 't':
	    tflag = 1;
	    break;

	case 'V':
	    if (*++s)
		 verbose_file_name = s;
	    else if (++i < argc)
		verbose_file_name = argv[i];
	    else
		usage();
	    vflag = 1;
	    continue;

	case 'v':
	    vflag = 1;
	    break;

	default:
	    usage();
	}

	for (;;)
	{
	    switch (*++s)
	    {
	    case '\0':
		goto end_of_option;

	    case 'd':
		dflag = 1;
		break;

	    case 'l':
		lflag = 1;
		break;

	    case 'r':
		rflag = 1;
		break;

	    case 't':
		tflag = 1;
		break;

	    case 'v':
		vflag = 1;
		break;

	    default:
		usage();
	    }
	}
end_of_option:;
    }

no_more_options:;
    if (i + 1 != argc) usage();
    input_file_name = argv[i];
}


char *
allocate(n)
unsigned n;
{
    register char *p;

    p = NULL;
    if (n)
    {
	p = CALLOC(1, n);
	if (!p) no_space();
    }
    return (p);
}


create_file_names()
{
    int i, len;
    char *tmpdir;

    tmpdir = getenv("TMPDIR");
    if (tmpdir == 0) tmpdir = getenv("TMP");
    if (tmpdir == 0) tmpdir = "/";

    len = strlen(tmpdir);
    i = len + strlen(temp_form) + 1;
    if (len && tmpdir[len-1] != '/')
	++i;

    action_file_name = MALLOC(i);
    if (action_file_name == 0) no_space();
    text_file_name = MALLOC(i);
    if (text_file_name == 0) no_space();
    union_file_name = MALLOC(i);
    if (union_file_name == 0) no_space();

    strcpy(action_file_name, tmpdir);
    strcpy(text_file_name, tmpdir);
    strcpy(union_file_name, tmpdir);

    if (len && tmpdir[len - 1] != '/')
    {
	action_file_name[len] = '/';
	text_file_name[len] = '/';
	union_file_name[len] = '/';
	++len;
    }

    strcpy(action_file_name + len, temp_form);
    strcpy(text_file_name + len, temp_form);
    strcpy(union_file_name + len, temp_form);

    action_file_name[len + 1] = 'a';
    text_file_name[len + 1] = 't';
    union_file_name[len + 1] = 'u';

    mktemp(action_file_name);
    mktemp(text_file_name);
    mktemp(union_file_name);

    len = strlen(file_prefix);

	if (!output_file_name)
	{
    output_file_name = MALLOC(len + strlen(OUTPUT_SUFFIX) + 1);
    if (output_file_name == 0)
	no_space();
    strcpy(output_file_name, file_prefix);
    strcpy(output_file_name + len, OUTPUT_SUFFIX);
	}
    if (rflag)
    {
		if (!code_file_name)
		{
		code_file_name = MALLOC(len + strlen(CODE_SUFFIX) + 1);
		if (code_file_name == 0)
		    no_space();
		strcpy(code_file_name, file_prefix);
		strcpy(code_file_name + len, CODE_SUFFIX);
		}
    }
    else
	code_file_name = output_file_name;

    if (dflag && !defines_file_name)
    {
	defines_file_name = MALLOC(len + strlen(DEFINES_SUFFIX) + 1);
	if (defines_file_name == 0)
	    no_space();
	strcpy(defines_file_name, file_prefix);
	strcpy(defines_file_name + len, DEFINES_SUFFIX);
    }

    if (vflag && !verbose_file_name)
    {
	verbose_file_name = MALLOC(len + strlen(VERBOSE_SUFFIX) + 1);
	if (verbose_file_name == 0)
	    no_space();
	strcpy(verbose_file_name, file_prefix);
	strcpy(verbose_file_name + len, VERBOSE_SUFFIX);
    }
}


open_files()
{
    create_file_names();

    if (input_file == 0)
    {
	input_file = fopen(input_file_name, "r");
	if (input_file == 0)
	    open_error(input_file_name);
    }

    action_file = fopen(action_file_name, "w");
    if (action_file == 0)
	open_error(action_file_name);

    text_file = fopen(text_file_name, "w");
    if (text_file == 0)
	open_error(text_file_name);

    if (vflag)
    {
	verbose_file = fopen(verbose_file_name, "w");
	if (verbose_file == 0)
	    open_error(verbose_file_name);
    }

    if (dflag)
    {
	defines_file = fopen(defines_file_name, "w");
	if (defines_file == 0)
	    open_error(defines_file_name);
	union_file = fopen(union_file_name, "w");
	if (union_file ==  0)
	    open_error(union_file_name);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == 0)
	open_error(output_file_name);

    if (rflag)
    {
	code_file = fopen(code_file_name, "w");
	if (code_file == 0)
	    open_error(code_file_name);
    }
    else
	code_file = output_file;
}


int
main(argc, argv)
int argc;
char *argv[];
{
    set_signals();
    getargs(argc, argv);
    open_files();
    reader();
    lr0();
    lalr();
    make_parser();
    verbose();
    output();
    done(0);
    /*NOTREACHED*/
}
