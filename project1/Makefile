P_DIR   = p_program/
LOG_DIR = test_token_log/
ANS_DIR = ans_token_log/

ALL_DIR = P_DIR LOG_DIR ANS_DIR

SRCS    = lex.l
OBJS    = lex.yy.c scanner
P_SRCS  = $(wildcard $(P_DIR)*.p)
T_LOGS  = $(P_SRCS:$(P_DIR)%.p=$(LOG_DIR)%.log)
LEX  := flex
DIFF := diff

all: scanner

test: clean_log scanner $(T_LOGS)

scanner: lex.yy.c
	$(CC) lex.yy.c -lfl -o scanner

lex.yy.c: lex.l
	$(LEX) --outfile=lex.yy.c < lex.l

$(LOG_DIR)%.log: $(P_DIR)%.p $(ANS_DIR)%.log scanner $(LOG_DIR)
	@printf "\033[33m=======   %-30s   =======\033[0m\n" $(word 2, $^)
	@./scanner $< > $@ || true
	@$(DIFF) $(word 2, $^) $@ || true

run: scanner test.p
	./scanner test.p

clean: clean_log
	-rm $(OBJS) -f

clean_log:
	-rm $(LOG_DIR)* -f
	@touch .gitkeep

.PHONY : all test run clean clean_log
