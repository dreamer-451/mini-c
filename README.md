# mini-c
1) 源代码编译
win_flex -o lex.yy.c --wincompat lex.l
win_bison -o yacc.tab.c -d yacc.y
gcc -o minic main.c ast.c semantic.c yacc.tab.c lex.yy.c

2）源代码执行
以对float.c文件进行编译为例，输出结果的格式为：报错-符号表-四元式-抽象语法树
输入命令：minic float.c
