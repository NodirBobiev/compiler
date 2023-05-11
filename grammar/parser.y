%parse-param {void **root}

%{
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdarg.h>
#include "lexer.hpp"
#include "../common/node.hpp"



void yyerror(void ** root, const char* msg, ...) {
    std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
}

%}

%code requires{
    #include "../common/node.hpp"
}

%union {
    Node* node;
    char* value;
}

%define parse.error verbose

%token<value> VAR IS
%token<value> ROUTINE END
%token<value> IDENTIFIER TYPE
%token<value> INTEGER REAL BOOLEAN
%token<value> RECORD ARRAY
%token<value> ASSIGNMENT_SIGN RANGE_SIGN
%token<value> WHILE LOOP FOR
%token<value> REVERSE IN
%token<value> IF THEN ELSE
%token<value> AND OR XOR NOT
%token<value> LT_SIGN LET_SIGN GT_SIGN GET_SIGN EQ_SIGN NEQ_SIGN
%token<value> MULT_SIGN DIV_SIGN MOD_SIGN
%token<value> PLUS_SIGN MINUS_SIGN
%token<value> TRUE FALSE REAL_LITERAL INTEGER_LITERAL
%token<value> RETURN
%token<value> L_SQ_BR R_SQ_BR L_BR R_BR
%token<value> COLON DOT COMMA SEMICOLON
%token<value> INVALID_CHARACTER

%type<node> program 
%type<node> simple_declaration variable_declaration variable_expression type_declaration 
%type<node> routine_declaration routine_return_type routine_parameters parameters
%type<node> parameter_declaration type primitive_type record_type variables_declaration
%type<node> array_type body statement return assignment routine_call
%type<node> arguments expressions while_loop for_loop range reverse if_statement
%type<node> else_body expression logic_operation relation compare_sign simple
%type<node> mult_sign_f factor mult_sign_s summand primary modifiable_primary
%type<node> identifier

%start program
%%
program
    : {$$ = mNode("program");}
    | program simple_declaration { $$ = $1->add($2); *root = $$;}
    | program routine_declaration { $$ = $1->add($2); *root = $$;}
    ;

simple_declaration
    : variable_declaration { $$ = mpNode("simple_declaration", 1, $1); }
    | type_declaration { $$ = mpNode("simple_declaration", 1, $1); }
    ;

variable_declaration
    : VAR identifier COLON type variable_expression { $$ = mpNode("variable_declaration", 3, $2, $4, $5);}
    | VAR identifier IS expression { $$ = mpNode("variable_declaration_auto", 2, $2, $4);}
    ;

variable_expression
    : {$$ = nullptr;}
    | IS expression { $$ = $2;}
    ;

type_declaration
    : TYPE identifier IS type { $$ = mpNode("type_declaration", 2, $2, $4);}
    ;

routine_declaration
    : ROUTINE identifier L_BR routine_parameters R_BR routine_return_type IS body END { $$ = mpNode("routine_declaration", 4, $2, $4, $6, $8);}
    ;

routine_return_type
    : {$$ = nullptr;}
    | COLON type { $$ = $2;}
    ;

routine_parameters
    : {$$ = nullptr;}
    | parameters { $$ = $1;}
    ;

parameters
    : parameters COMMA parameter_declaration { $$ = $1->add($3);}
    | parameter_declaration { $$ = mpNode("parameters", 1, $1);}
    ;

//primitive types?
parameter_declaration
    : identifier COLON type { $$ = mpNode("parameter_declaration", 2, $1, $3);}
    ;

type
    : primitive_type { $$ = mpNode("type", 1, $1);}
    | array_type { $$ = mpNode("type", 1, $1);}
    | record_type { $$ = mpNode("type", 1, $1);}
    | identifier { $$ = mpNode("type", 1, $1);}
    ;

primitive_type
    : INTEGER { $$ = mNode("primitive_type", "integer");}
    | REAL { $$ = mNode("primitive_type", "real");}
    | BOOLEAN { $$ = mNode("primitive_type", "boolean");}
    ;

record_type
    : RECORD variables_declaration END { $$ = mpNode("record_type", 1, $2);}
    ;

variables_declaration
    : {$$ = mNode("variables_declaration");}
    | variables_declaration variable_declaration { $$ =  $1->add($2);}
    ;

array_type
    : ARRAY L_SQ_BR expression R_SQ_BR type { $$ = mpNode("array_type", 2, $3, $5);}
    ;

body
    : {$$ = mNode("body");}
    | body simple_declaration { $$ = $1->add($2);}
    | body statement { $$ = $1->add($2);}
    ;

statement
    : assignment  { $$ = mpNode("statement", 1, $1);}
    | routine_call { $$ = mpNode("statement", 1, $1);}
    | while_loop { $$ = mpNode("statement", 1, $1);}
    | for_loop { $$ = mpNode("statement", 1, $1);}
    | if_statement { $$ = mpNode("statement", 1, $1);}
    | return { $$ = mpNode("statement", 1, $1);}
    ;

return
    : RETURN expression { $$ = mpNode("return", 1, $2); }
    | RETURN { $$ = mNode("return"); }
    ;


assignment
    : modifiable_primary ASSIGNMENT_SIGN expression { $$ = mpNode("assignment", 2, $1, $3);}
    ;

routine_call
    : identifier L_BR arguments R_BR { $$ = mpNode("routine_call", 2, $1, $3);}
    ;

arguments
    : {$$ = nullptr;}
    | expressions { $$ = $1;}
    ;

expressions
    : expressions COMMA expression { $$ = $1->add($3);}
    | expression { $$ = mpNode("arguments", 1, $1);}
    ;

while_loop
    : WHILE expression LOOP body END { $$ = mpNode("while_loop", 2, $2, $4);}
    ;

for_loop
    : FOR identifier range LOOP body END { $$ = mpNode("for_loop", 3, $2, $3, $5);}
    ;

range
    : IN reverse expression RANGE_SIGN expression { $$ = mpNode("range", 3, $2, $3, $5);}
    
    ;

reverse
    : {$$ = nullptr;}
    | REVERSE { $$ = mNode("reverse");}
    ;

if_statement
    : IF expression THEN body else_body END { $$ = mpNode("if_statement", 3, $2, $4, $5);}
    ;

else_body
    : {$$ = nullptr;}
    | ELSE body { $$ = mpNode("body", 1, $2);}
    ;

expression
    : expression logic_operation relation { $$ = mpNode("expression", 3, $1, $2, $3);}
    | relation { $$ = mpNode("expression", 1, $1);}
    ;

logic_operation
    : AND { $$ = mNode("logic_operation", "and");}
    | OR { $$ = mNode("logic_operation", "or");}
    | XOR { $$ = mNode("logic_opeartion", "xor");}
    ;

relation
    : simple { $$ = mpNode("relation", 1, $1);}
    | simple compare_sign simple { $$ = mpNode("relation", 3, $1, $2, $3);}
    ;

compare_sign
    : LT_SIGN { $$ = mNode("compare_sign", "<");}
    | LET_SIGN { $$ = mNode("compare_sign", "<=");}
    | GT_SIGN { $$ = mNode("compare_sign", ">");}
    | GET_SIGN { $$ = mNode("compare_sign", ">=");}
    | EQ_SIGN { $$ = mNode("compare_sign", "=");}
    | NEQ_SIGN { $$ = mNode("compare_sign", "/=");}
    ;

simple
    : simple mult_sign_f factor { $$ = mpNode("simple", 3, $1, $2, $3);}
    | factor { $$ = mpNode("simple", 1, $1);}
    ;
// f mean first priority
mult_sign_f
    : MULT_SIGN { $$ = mNode("mult_sign", "*");}
    | DIV_SIGN { $$ = mNode("mult_sign", "/");}
    | MOD_SIGN { $$ = mNode("mod_sign", "%");}
    ;

factor
    : factor mult_sign_s summand { $$ = mpNode("factor", 3, $1, $2, $3);}
    | summand { $$ = mpNode("factor", 1, $1);}
    | mult_sign_s summand { $$ = mpNode("unary_factor", 2, $1, $2);}
    | NOT summand { $$ = mpNode("not_factor", 2, $1, $2);}
    ;
// s mean second priority
mult_sign_s
    : PLUS_SIGN { $$ = mNode("sum_sign", "+");}
    | MINUS_SIGN { $$ = mNode("sum_sign", "-");}
    ;

summand
    : primary { $$ = mpNode("summand", 1, $1);}
    | L_BR expression R_BR { $$ = mpNode("summand", 1, $2);}
    ;


primary
    : TRUE { $$ = mNode("boolean", "true");}
    | FALSE { $$ = mNode("boolean", "false");}
    | REAL_LITERAL { $$ = mNode("real", $1);}
    | INTEGER_LITERAL { $$ = mNode("integer", $1);}
    | modifiable_primary { $$ = $1;}
    | routine_call { $$ = $1;}
    ;

modifiable_primary
    : identifier { $$ = mpNode("modifiable_primary", 1, $1);}
    | modifiable_primary L_SQ_BR expression R_SQ_BR { $$ = mpNode("modifiable_primary_array", 2, $1, $3);}
    | modifiable_primary DOT modifiable_primary { $$ = mpNode("modifiable_primary_field", 2, $1, $3);}
    ;


identifier
    : IDENTIFIER { $$ = mNode("identifier", $1); }
    ;

%%
