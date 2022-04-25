lex ast.l
yacc -d -v ast.y
gcc lex.yy.c y.tab.c graph.c -ll -ly -o ast.out
./ast.out < code.java