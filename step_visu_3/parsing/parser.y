%{
#include "stepentities/cls_Parameter.h"
#include "stepentities/cls_ParameterTreeElement.h"
#include "stepentities/cls_EI.h"
#include "stepentities/cls_SEI.h"
#include "stepentities/cls_CEI.h"
#include "stepentities/cls_EIlist.h"
#include "stepentities/cls_STEPfile.h"
extern int yylex ();             // declared in LEX file
extern void yyerror (cls_STEPfile*& myStepFile, char*);     // declared in LEX file
%}

%union {
   int ival;
   char* sval;
   cls_ParameterTreeElement* parameterlistval;
   cls_EI* eival;
   cls_SEI* seival;
   cls_CEI* ceival;
   cls_EIlist* eilistval;
   cls_STEPfile* stepfileval;
}

%parse-param {cls_STEPfile*& myStepFile}

%token<ival> FILE_START HEADER_START DATA_START SECTION_END FILE_END
%token<ival> SEMICOLON OP_BR CL_BR EQUALS COMMA ASTERISK DOLLAR

%token<sval> USER_DEFINED_KEYWORD STANDARD_KEYWORD
%token<sval> INTEGER
%token<sval> REAL
%token<sval> STRING
%token<sval> ENTITY_INSTANCE_NAME
%token<sval> ENUMERATION
%token<sval> BINARY

%type<sval> keyword
%type<parameterlistval> parameter_list parameter typed_parameter untyped_parameter omitted_parameter list
%type<eival> entity_instance
%type<seival> simple_entity_instance simple_record
%type<ceival> complex_entity_instance subsuper_record simple_record_list
%type<eilistval> data_section entity_instance_list
%type<stepfileval> exchange_file

%start root_node

%%

// more or less implementation of yyparse()

root_node                  : exchange_file
                              {
                                 myStepFile = $1;
                              }
                           ;

exchange_file              : FILE_START header_section data_section data_section_list FILE_END
                              {
                                 //printf("parsed exchange file A\n");
                                 cls_STEPfile* f =  new cls_STEPfile();
                                 f->SetEIlist($3);
                                 $$ = f;
                              }
                           | FILE_START header_section data_section FILE_END
                              {
                                 //printf("parsed exchange file B\n");
                                 cls_STEPfile* f =  new cls_STEPfile();
                                 f->SetEIlist($3);
                                 $$ = f;
                              }
                           ;

header_section             : HEADER_START SEMICOLON header_entity header_entity header_entity header_entity_list SECTION_END
                           | HEADER_START SEMICOLON header_entity header_entity header_entity SECTION_END
                           ;
header_entity_list         : header_entity_list header_entity
                           | header_entity
                           ;
header_entity              : keyword OP_BR parameter_list CL_BR SEMICOLON
                           | keyword OP_BR CL_BR SEMICOLON
                           ;
parameter_list             : parameter_list COMMA parameter
                              {
                                 $3->SetNext($1);
                                 $$ = $3;
                              }
                           | parameter
                              {
                                 $$ = $1;
                              }
                           ;
parameter                  : typed_parameter
                              { $$ = $1; }
                           | untyped_parameter
                              { $$ = $1; }
                           | omitted_parameter
                              { $$ = $1; }
                           ;
typed_parameter            : keyword OP_BR parameter CL_BR
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, $3, nullptr);
                                 $$ = a;
                              }
                           ;
untyped_parameter          : DOLLAR
                              {
                                 cls_Parameter* b = new cls_Parameter("$");
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | INTEGER
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | REAL
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | STRING
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | ENTITY_INSTANCE_NAME
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | ENUMERATION
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | BINARY
                              {
                                 cls_Parameter* b = new cls_Parameter($1);
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           | list
                              {
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(nullptr, $1, nullptr);
                                 $$ = a;
                              }
                           ;
omitted_parameter          : ASTERISK
                              {
                                 cls_Parameter* b = new cls_Parameter("*");
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(b, nullptr, nullptr);
                                 $$ = a;
                              }
                           ;
list                       : OP_BR parameter_list CL_BR
                              {
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(nullptr, $2, nullptr);
                                 $$ = a;
                              }
                           | OP_BR CL_BR
                              {
                                 cls_ParameterTreeElement* a = new cls_ParameterTreeElement(nullptr, nullptr, nullptr);
                                 $$ = a;
                              }
                           ;

data_section_list          : data_section_list data_section
                           | data_section
                           ;
data_section               : DATA_START OP_BR parameter_list CL_BR SEMICOLON entity_instance_list SECTION_END
                              {
                                 $$ = $6;
                              }
                           | DATA_START OP_BR parameter_list CL_BR SEMICOLON SECTION_END
                              {
                                 $$ = nullptr;
                              }
                           | DATA_START SEMICOLON entity_instance_list SECTION_END
                              {
                                 $$ = $3;
                              }
                           | DATA_START SEMICOLON SECTION_END
                              {
                                 $$ = nullptr;
                              }
                           ;
entity_instance_list       : entity_instance_list entity_instance
                              {
                                 $1->AddEI($2->GetN(), $2);
                                 $$ = $1;
                              }
                           | entity_instance
                              {
                                 cls_EIlist* a = new cls_EIlist();
                                 a->AddEI($1->GetN(), $1);
                                 $$ = a;
                              }
                           ;
entity_instance            : simple_entity_instance
                              {
                                 $$ = $1;
                              }
                           | complex_entity_instance
                              {
                                 $$ = $1;
                              }
                           ;
simple_entity_instance     : ENTITY_INSTANCE_NAME EQUALS simple_record SEMICOLON
                              {
                                 $3->SetN($1);
                                 $$ = $3;
                              }
                           ;
simple_record              : keyword OP_BR parameter_list CL_BR
                              {
                                 cls_SEI* a = new cls_SEI($1);
                                 a->SetParamList($3);
                                 $$ = a;
                              }
                           | keyword OP_BR CL_BR
                              {
                                 cls_SEI* a = new cls_SEI($1);
                                 $$ = a;
                              }
                           ;


complex_entity_instance    : ENTITY_INSTANCE_NAME EQUALS subsuper_record SEMICOLON
                              {
                                 $3->SetN($1);
                                 $$ = $3;
                              }
                           ;
subsuper_record            : OP_BR simple_record_list CL_BR
                              {
                                 $$ = $2;
                              }
                           ;
simple_record_list         : simple_record_list simple_record
                              {
                                 $2->SetN("#0");
                                 $1->AddSEI($2);
                                 $$ = $1;
                              }
                           | simple_record
                              {
                                 cls_CEI* a = new cls_CEI();
                                 $1->SetN("#0");
                                 a->AddSEI($1);
                                 $$ = a;
                              }
                           ;


keyword                    : USER_DEFINED_KEYWORD
                              { $$ = $1; }
                           | STANDARD_KEYWORD
                              { $$ = $1; }
                           ;
