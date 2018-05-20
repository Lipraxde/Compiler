/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 1 Sample
 */

%{

#include <string.h>
#include "y.tab.h"

#define LIST strcat( buf, yytext )
#define token(t) { LIST; if (Opt_T) printf("<%s>\n", #t ); }
#define tokenChar(t) { LIST; if (Opt_T) printf("<%c>\n", t );}
#define tokenInteger(t, i) { LIST; if (Opt_T) printf("<%s: %d>\n", t, i); }
#define tokenOctInteger(t, i) { LIST; if (Opt_T) printf("<%s: %s>\n", t, i); }
#define tokenFloat(t, i) { LIST; if (Opt_T) printf("<%s: %s>\n", t, i ); }
#define tokenScientific(t, s) { LIST; if ( Opt_T ) printf("<%s: %s>\n", t, s); }
#define tokenString(t, s) { LIST; if (Opt_T) printf("<%s: %s>\n", t, s); }


#define  MAX_LINE_LENG  256

int Opt_S = 1;				/* list source code option */
int Opt_T = 1;				/* list token option */
int Opt_P = 0;				/* praser debug option */
int Opt_D = 1;				/* dump symbol table option */
int Opt_A = 1;				/* dump AST option */
int linenum = 1;			/* line number */
char buf[MAX_LINE_LENG];		/* source code line buffer */
char strContent[MAX_LINE_LENG];		/* string buffer */

void setPseudoComment( const char * );	/* pseudo comment option switch */
%}

whitespace	[ \t]+
letter		[A-Za-z]
digit		[0-9]
integer		0|[1-9][0-9]*
octal		0[0-7]+
fraction	0|[0-9]*[1-9]
float		{integer}"."{fraction}
scientific	({integer}|{float})[Ee][+-]?({integer})
identifier	({letter})({letter}|{digit})*

 /* exclusive start conditions */
%x COMMENT
%x COMMENT_CPP

%%

","				{ tokenChar(',');	return COMMA; }
";"				{ tokenChar(';');	return SEMICOLON; }
":"				{ tokenChar(':');	return COLON; }
"("				{ tokenChar('(');	return Lparenthese; }
")"				{ tokenChar(')');	return Rparenthese; }
"["				{ tokenChar('[');	return Lbracket; }
"]"				{ tokenChar(']');	return Rbracket; }

"+"				{ tokenChar('+');	return OP_ADD; }
"-"				{ tokenChar('-');	return OP_DEL; }
"*"				{ tokenChar('*');	return OP_MUL; }
"/"				{ tokenChar('/');	return OP_DIV; }
"mod"			{ token(mod);		return OP_MOD; }
":="			{ token(:=);		return ASSIGNMENT; }
"<"				{ tokenChar('<');	return OP_LT; }
"<="			{ token(<=);		return OP_LE; }
"<>"			{ token(<>);		return OP_NE; }
">="			{ token(>=);		return OP_GE; }
">"				{ tokenChar('>');	return OP_GT; }
"="				{ tokenChar('=');	return OP_EQ; }
"and"			{ token(and);		return TF_AND; }
"or"			{ token(or);		return TF_OR; }
"not"			{ token(not);		return TF_NOT; }

"array"			{ token(KWarray);	return KWarray; }
"begin"			{ token(KWbegin);	return KWbegin; }
"boolean"		{ token(KWboolean); return KWboolean; }
"def"			{ token(KWdef);		return KWdef; }
"do"			{ token(KWdo);		return KWdo; }
"else"			{ token(KWelse);	return KWelse; }
"end"			{ token(KWend);		return KWend; }
"false"			{ token(KWfalse);	return KWfalse; }
"for"			{ token(KWfor);		return KWfor; }
"integer"		{ token(KWinteger);	return KWinteger; }
"if"			{ token(KWif);		return KWif; }
"of"			{ token(KWof);		return KWof; }
"print"			{ token(KWprint);	return KWprint; }
"read"			{ token(KWread);	return KWread; }
"real"			{ token(KWreal);	return KWreal; }
"string"		{ token(KWstring);	return KWstring; }
"then"			{ token(KWthen);	return KWthen; }
"to"			{ token(KWto);		return KWto; }
"true"			{ token(KWtrue);	return KWtrue; }
"return"		{ token(KWreturn);	return KWreturn; }
"var"			{ token(KWvar);		return KWvar; }
"while"			{ token(KWwhile);	return KWwhile; }

{identifier}	{
                    yylval.text_val = strdup(yytext);;
                    tokenString("id",yytext);
                    return IDENT;
                }
{octal}			{
                    yylval.int_val = strtol(yytext,'\0',8);
                    tokenOctInteger("oct_integer",yytext);
                    return OCTAL;
                }
{integer}		{
                    yylval.int_val = atoi(yytext);
                    tokenInteger("integer",atoi(yytext));
                    return INTEGER;
                }
{float}			{
                    yylval.real_val = atof(yytext);
                    tokenFloat("float",yytext);
                    return FLOAT;
                }
{scientific}	{
                    yylval.real_val = atof(yytext);
                    tokenScientific("scientific", yytext);
                    return SCIENTIFIC;
                }

\"((\"\")|[^\"\n])*\"	{
				LIST;
				size_t wrt_idx = 0;
				size_t rd_idx = 1;
				int quote = 0;
				while( yytext[rd_idx] ){
					if( yytext[rd_idx] == '\"' ){
						if( quote )
							strContent[wrt_idx++] = '\"';
						quote = ~quote;
					}
					else
						strContent[wrt_idx++] = yytext[rd_idx];
					rd_idx++;
				}
				strContent[wrt_idx] = '\0';
				if (Opt_T){
					printf("<%s: %s>\n", "string", strContent);
				}
                                yylval.text_val = strdup(strContent);
				return STRING;
			}

"//&"[A-Z][+-][^\n]*		{ /* pseudo comment */
				  LIST;
				  setPseudoComment( yytext );
				}
"//"				{ /* C++ stype comment */
				  LIST;
				  BEGIN COMMENT_CPP;
				}

<COMMENT_CPP>[^\n]+		{
				  LIST;
				}

<COMMENT_CPP>"\n"		{
				  LIST;
				  if( Opt_S )
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
				  BEGIN INITIAL;
				}

"/*"				{ /* C-style comment */
				  LIST;
				  BEGIN COMMENT;
				}
<COMMENT>"*/"			{
				  LIST;
				  BEGIN INITIAL;
				}
<COMMENT>"\n"			{
				  LIST;
				  if  (Opt_S)
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
				}
<COMMENT>.			{
				  LIST;
				}

{whitespace}			{ 
				  LIST; 
				}

\n 				{
				  LIST;
				  if  (Opt_S)
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
		   		}

.				{
				  /* error */
				  printf("error at line %d: bad character \"%s\"\n", linenum, yytext );
				  exit(-1);
				}

%%

void setPseudoComment( const char *text )
{
	/* format : //&[A-Z][+-] */
	switch( text[3] ) {
	case 'S':
		if( text[4] == '+' )
			Opt_S = 1;
		else if( text[4] == '-' )
			Opt_S = 0;
		break;
	case 'T':
		if( text[4] == '+' )
			Opt_T = 1;
		else if( text[4] == '-' )
			Opt_T = 0;
	 	break;
	case 'P':
		if( text[4] == '+' )
			Opt_P = 1;
		else if( text[4] == '-' )
			Opt_P = 0;
	 	break;
	case 'D':
		if( text[4] == '+' )
			Opt_D = 1;
		else if( text[4] == '-' )
			Opt_D = 0;
	 	break;
	default:
	 	break;
	}
}

