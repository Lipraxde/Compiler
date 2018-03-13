SRCS  = lex.l
OBJS  = lex.yy.c scanner
LEX  := lex

all: scanner

scanner: lex.yy.c
	$(CC) lex.yy.c -lfl -o scanner

lex.yy.c: lex.l
	$(LEX) --outfile=lex.yy.c < lex.l

run: scanner test.p
	./scanner test.p

clean:
	rm $(OBJS) 

.PHONY : all run clean
