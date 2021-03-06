%{
#include <stdio.h>
//#include "CommentRemoval.tab.h"  // include header generated by bison from the YACC file
void yyerror (char*);      // declaration
//int yyparse (void);        // declaration
// yylex is declared for us by LEX
// yywrap is declared for us by LEX
%}

%x comment

%%

"/*"                    { BEGIN(comment); }
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>"*"+"/"        { BEGIN(INITIAL); }

%%

// implementation
void yyerror (char* str)
{
   printf ("ERROR: Could not parse: %s\n", str);
}

int yywrap ()
{
}

int main(int argc, char** argv)
{
   if (argc != 2) {
      fprintf (stderr, "Wrong number of arguments. Please specify the input file.\n");
      return 1;
   }
   FILE* inFile = fopen(argv[1], "r");
   if (!inFile) {
      fprintf (stderr, "Failed to open input file.\n");
      return 1;
   } else {
      yyin = inFile;
      //yyparse();
      yylex();
      fclose(inFile);
   }
}
