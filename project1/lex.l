%{
#define LIST               strcat(buf, yytext)
#define token(fmt, ...)    {LIST; if (Opt_T) printf("<" fmt ">\n", ##__VA_ARGS__);} // I modfiy this macor. !!TACK CARE!!
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %d>\n", #t, (i));}
#define tokenString(t, s)  {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG      256
#define MAX_STR_LENG       256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
char str_buf[MAX_STR_LENG];     // buffer for string.

// Replace t in string with p. 
int str_replace(char *des, const char *src, const char *t, const char *p)
{
    const char *temp1;
    const char *temp2;
    
    while(*src!=0)
    {
        temp1 = t;
        temp2 = src;
        while(*temp1==*temp2)
        {
            temp1++;
            temp2++;
        }
        if(*temp1==0)
        {
            src = temp2;
            temp1 = p;
            while(*temp1!=0)
                *des++ = *temp1++;
        }
        else
            *des++ = *src++;
    }
    *des = 0;
    return 0;
}

%}
delimiters  ","|":"|";"|"("|")"|"["|"]"
operators   "+"|"-"|"*"|"/"|"mod"|":="|"<"|"<="|"<>"|">="|">"|"="|"and"|"or"|"not"
keyword     array|begin|boolean|def|do|else|end|false|for|integer|if|of|print|read|real|string|then|to|true|return|var|while
letter      [a-zA-Z_]
digit       [0-9]
  /* Notice "space" doesn't contain "newling"(\n). */
space       [ \t]+
dec_integer ([1-9]{digit}*)|0
  /* We don't welcome redundant "0". QAQ */
float_point {dec_integer}\.(({digit}*[1-9])|0)
scientific  ({dec_integer}|{float_point})(E|e)(\+|\-)?{dec_integer}

  /* Condition for mutiple line comment is "Exclusive start". */
%X COMMENT                                      

%%
  /* Delimiters and operators just export "<____>\n" */
{delimiters}|{operators} {
          token("%s", yytext);
        }

  /* Keyword export "<KW____>\n". */
{keyword} {
          token("KW%s", yytext);
        }

  /* Export identifiers. */
{letter}({letter}|{digit})* {
          tokenString(id, yytext);
        }

  /* Ignore space. */
{space} { LIST; }

  /* Export string.                             */
  /* [ !#-~] means any visible ASCII without ". */
\"([ !#-~]|\"\")*\" {
          int len = strlen(yytext);
          yytext[len - 1] = '\0';
          str_replace(str_buf, yytext + 1, "\"\"", "\"");
          yytext[len - 1] = '\"';
          tokenString(string, str_buf);
        }

  /* Export integer. */
{dec_integer} { tokenString(integer, yytext); }

  /* Export Octal number.                                */
  /* Notice that octal number shouldn't contain 8 and 9. */
  /* But deal with this problem at Praser.               */
  /* And shouldn't follow by identifier head.            */
0{digit}* { tokenString(oct_integer, yytext); }

  /* Export floating-point. */
{float_point} { tokenString(float, yytext); }

  /* Export scientific.                                  */
  /* 0E10E2 !! We need to avoid this PROBLEM !!!         */
  /* Or ... it is Praser's job ?                         */
{scientific} { tokenString(scientific, yytext); }

  /* Pseudocomments. It is like comment. */
"//&T+".* { LIST; Opt_T = 1; }
"//&S+".* { LIST; Opt_S = 1; }
"//&T-".* { LIST; Opt_T = 0; }
"//&S-".* { LIST; Opt_S = 0; }

  /* Comment. To avoid pesudocomment not work, comment must be placed behind. (first match ^_^) */
"//".* { LIST; }

  /* Mutiple line comment.                                            */
  /* Because need export each line in program, I use start condition. */
"/*" { LIST; BEGIN COMMENT; }
<COMMENT>. { LIST; }
<COMMENT>\n {
          if (Opt_S)
            printf("%d: %s\n", linenum, buf);
          linenum++;
          buf[0] = '\0';
        }
<COMMENT>"*/" { LIST; BEGIN INITIAL;}
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
