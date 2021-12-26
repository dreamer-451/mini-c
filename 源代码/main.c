#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "yacc.tab.h"
#include "def.h"

extern FILE *yyin;
extern int yyparse();

int main(int argc, char *argv[]){
  yyin=fopen(argv[1],"r");
  if (!yyin) {
     printf("open file error");
     return 0;
  }
  yyparse();
  return 0;
}
