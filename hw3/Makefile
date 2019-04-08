all:
	bison -d hw4.y;flex hw4.flx; gcc  hw4.tab.c lex.yy.c  -lfl
clean:
	rm lex.yy.c hw4.tab.c hw4.tab.h
