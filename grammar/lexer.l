%{
#include "parser.hpp"
#include <string>
%}

%option noyywrap
%option yylineno

digit      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer    {digit}+
real       {integer}("."{integer})?("E"("+"|"-")?{integer})?

%%

"+"              { return PLUS_SIGN; }
"-"              { return MINUS_SIGN; }
"*"              { return MULT_SIGN; }
"/"              { return DIV_SIGN; }
"%"              { return MOD_SIGN; }
":="             { return ASSIGNMENT_SIGN; }
".."             { return RANGE_SIGN; }
":"              { return COLON; }
";"              { return SEMICOLON; }
"="              { return EQ_SIGN; }
"/="             { return NEQ_SIGN; }
"<"              { return LT_SIGN; }
"<="             { return LET_SIGN; }
">"              { return GT_SIGN; }
">="             { return GET_SIGN; }
"and"            { return AND; }
"or"             { return OR; }
"xor"            { return XOR; }
"not"            { return NOT; }
"var"            { return VAR; }
"is"             { return IS; }
"then"           { return THEN; }
"type"           { return TYPE; }
"routine"        { return ROUTINE; }
"end"            { return END; }
"record"         { return RECORD; }
"array"          { return ARRAY; }
"in"             { return IN; }
"reverse"        { return REVERSE; }
"loop"           { return LOOP; }
"for"            { return FOR; }
"while"          { return WHILE; }
"if"             { return IF; }
"else"           { return ELSE; }
"true"           { return TRUE; }
"false"          { return FALSE; }
"return"         { return RETURN; }
"integer"        { return INTEGER; }
"real"           { return REAL; }
"boolean"        { return BOOLEAN; }
{integer}        { yylval.value = yytext; return INTEGER_LITERAL; }
{real}           { yylval.value = yytext; return REAL_LITERAL; }
{identifier}     { yylval.value = yytext; return IDENTIFIER; }
"("              { yylval.value = yytext; return L_BR; }
")"              { yylval.value = yytext; return R_BR; }
"."              { yylval.value = yytext; return DOT; }
"["              { yylval.value = yytext; return L_SQ_BR; }
"]"              { yylval.value = yytext; return R_SQ_BR; }
","              { yylval.value = yytext; return COMMA; }
[\t\f\r ]+        /* ignore whitespace */
\n                /* ignore newlines */
.                { return INVALID_CHARACTER; }

%%