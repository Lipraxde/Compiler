OBJS    = lex.yy.c y.tab.c y.tab.h y.output parser
LEX  := flex
YACC := yacc
DIFF := diff

all: parser

parser: codegen.c err.c main.c y.tab.c lex.yy.c
	$(CC) -g $^ -ly -lfl -o parser

y.tab.c: yacc.y
	yacc -d -v yacc.y

lex.yy.c: lex.l
	$(LEX) --outfile=lex.yy.c < lex.l

clean:
	-rm $(OBJS) -f

.PHONY : all clean
