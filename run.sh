flex lexer.l
bison -dy parser.y
gcc y.tab.c lex.yy.c -w
./a.out < test.c