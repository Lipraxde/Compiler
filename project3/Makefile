P_DIR   = p_program/
LOG_DIR = test_log/
ANS_DIR = ans_log/

ALL_DIR = P_DIR LOG_DIR ANS_DIR

OBJS    = lex.yy.c y.tab.c y.tab.h y.output parser
P_SRCS  = $(wildcard $(P_DIR)*.p)
T_LOGS  = $(P_SRCS:$(P_DIR)%.p=$(LOG_DIR)%.log)
LEX  := flex
YACC := yacc
DIFF := diff

all: parser

test: clean_log parser $(T_LOGS)

parser: main.c y.tab.c lex.yy.c type.c attribute.c symbol.c stack.c
	$(CC) $^ -ly -lfl -o parser

y.tab.c: yacc.y
	yacc -d -v yacc.y

lex.yy.c: lex.l
	$(LEX) --outfile=lex.yy.c < lex.l

$(T_LOGS): $(LOG_DIR)%.log : $(P_DIR)%.p $(ANS_DIR)%.log parser $(LOG_DIR)
	@printf "\033[33m=======   %-30s   =======\033[0m\n" $(word 2, $^)
	@./parser $< > $@ 2>&1 || true
	@$(DIFF) $(word 2, $^) $@ || true

clean: clean_log
	-rm $(OBJS) -f

clean_log:
	-rm $(LOG_DIR)* -f
	@touch $(LOG_DIR).gitkeep

.PHONY : all test run clean # clean_log
