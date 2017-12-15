%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex ();             // declared in LEX file
extern void yyerror (char*);     // declared in LEX file
%}

%union {
   char* sval;
}

%token<sval> DATA COMMENT

%start root_node

%%

root_node   : file
            ;

file        : file whatever
            | whatever
            ;

whatever    : DATA
               { printf ("%s\n", $1);
               }
            | COMMENT
               { //printf ("[[[%s]]]\n", $1);
               }
            ;
