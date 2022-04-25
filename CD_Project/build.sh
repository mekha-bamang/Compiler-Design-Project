cd symTab
lex project.l
yacc -d project.y
gcc y.tab.c lex.yy.c -ll -ly
cd ..
./symTab/a.out < code.java
cd AST
lex ast.l
yacc -d  ast.y
gcc lex.yy.c y.tab.c graph.c -ll -ly -o ast.out
cd ..
./AST/ast.out < code.java
echo $'\n\n'
echo "ICG"
cat icg.txt
echo $'\n\n'
echo "Optimized Code"
gcc optimized_code.c
./a.out > optimized_code.txt
cat optimized_code.txt
echo $'\n\n'
echo "Target Code"
python assemble.py 



