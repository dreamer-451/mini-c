# mini-c
1) 源代码编译
win_flex -o lex.yy.c --wincompat lex.l
win_bison -o yacc.tab.c -d yacc.y
gcc -o minic main.c ast.c semantic.c yacc.tab.c lex.yy.c

2）源代码执行
以对float.c文件进行编译为例，输出结果的格式为：报错-符号表-四元式-抽象语法树
输入命令：minic float.c
报错：
Line 6,Semantic error:Returns an error in the value type

输出符号表：
                ***Symbol Table***
-----------------------------------------------------------
Index   Name    Level   Type    Flag    Offset  Param_num
-----------------------------------------------------------
0       main    0       int     F       40      0
-----------------------------------------------------------

输出四元式：
**** Quaters Table ****
-----------------------
(0) (FUNCTION,-,-,main)
(1) (=,var1,-,var2)
(2) (=,var1,-,var3)
(3) (+,var2,var3,temp1)
(4) (=,temp1,-,var4)
(5) (LABEL,-,-,label1)
-----------------------

输出抽象语法树：
 Function definition:
   Type:int
   Function name:main
      No parameter function
   Compound statement:
      Variable definition of a compound statement:
         LOCAL VAR_NAME:
            Type:float
            VAR_NAME:
                a
                b
                c
      The statement part of the compound statement:
         Expression statement:
            ASSIGNOP
               ID: a
               FLAOT:1.200000
         Expression statement:
            ASSIGNOP
               ID: b
               FLAOT:2.400000
         Expression statement:
            ASSIGNOP
               ID: c
               PLUS
                  ID: a
                  ID: b
         Return statement:
            ID: c
