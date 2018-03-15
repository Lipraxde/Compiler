/*** Delimiters ***/
, ; : ( ) [ ] () []

/*** Arithmetic, Relational, and　Logical Operators ***/
+ - * / mod := < <= <> >= > = and or not

/*** Keywords ***/
array begin boolean def do else end false for
integer if of print read real string then
to true return var while

/*** Identifiers ***/
ident Ident _uuw2
o1234 _9283 ___A0

/*** Integer Constants ***/
1233 5678 9012 9990
0    -120 -0
0234 0123 0666 0770
-012 00   0000

/*** Floating-Point Constants ***/
123.456 789.012
0.01234 0.0
-12.777 -123.01

/*** Scientific Notations ***/
1.23E4 1.2E+3 1.2E-3
1234e5 123e+5 123e-5
0E0    0.04E3 0.0e-8

/*** String Constants ***/
"qwe123e tt" "1234" "123.456"
"A _ A" "aa""bb" "__^^__"
" "" ""_"""" "

/*** Whitespace ***/
"space->"               "<-space"
"  tab->"		"<-tab  "

/*** Comments ***/
// test comment (basic)
/*
multiple
 line
  comments (basic)
*/
// this is a comment // line */ /* with some /* delimiters */ before the end
/* this is a comment // line with some /* and
// delimiters */

/*** Pseudocomments ***/
//&T-
these tokens should not response
//&T+
return to show tokens
//&S-
see me
see you
//&S-&S+
can not see
can not find
//&S+

 
