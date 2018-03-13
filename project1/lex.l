%{
#define LIST               strcat(buf, yytext)
#define token(fmt, ...)    {LIST; if (Opt_T) printf(fmt, __VA_ARGS__);}
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %d>\n", #t, (i));}
#define tokenString(t, s)  {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG      256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
char *strfront;
%}
delimiters  ","|":"|";"|"("|")"|"["|"]"
operators   "+"|"-"|"*"|"/"|"mod"|":="|"<"|"<="|"<>"|">="|">"|"="|"and"|"or"|"not"
keyword     array|begin|boolean|def|do|else|end|false|for|integer|if|of|print|read|real|string|then|to|true|return|var|while
letter      [a-zA-Z_]
digit       [0-9]
space       [ \t]+
dec_integer {digit}*
float_point [1-9]{digit}*\.{digit}*[1-9]
scientific  {float_point}(E|e)(\+|\-)?{dec_integer}
%%
{delimiters}|{operators} {
          token("<%s>\n", yytext);
        }
{keyword} {
          token("<KW%s>\n", yytext);
        }
{letter}({letter}|{digit})* {
          tokenString(id, yytext);
        }
{space} { LIST; }
\"({letter}|{digit}|{space}|"")*\" {
          yytext[strlen(yytext) - 1] = '\0';
          tokenString(string, yytext + 1);
          strcat(buf, "\"");
        }
0({digit})* { tokenString(oct_integer, yytext); }
{dec_integer} { tokenString(integer, yytext); }
{float_point} { tokenString(float, yytext); }
{scientific} { tokenString(scientific, yytext); }
"//&T+".*$ { LIST; Opt_T = 1; }
"//&S+".*$ { LIST; Opt_S = 1; }
"//&T-".*$ { LIST; Opt_T = 0; }
"//&S-".*$ { LIST; Opt_S = 0; }
"//".*$ { LIST; }
\n      {
          if (Opt_S)
            printf("%d: %s\n", linenum, buf);
          linenum++;
          buf[0] = '\0';
        }
.       {
          /* error */
          printf("error at line %d: bad character \"%s\"\n", linenum, yytext );
          exit(-1);
        }
%%
int main( int argc, char **argv )
{
  if( argc != 2 ) {
    fprintf( stderr, "Usage: ./scanner [filename]\n" );
    exit(0);
  }
	
  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    exit(-1);
  }
	
  yyin = fp;

  yylex();

  exit(0);
}
