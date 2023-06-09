#!/usr/bin/env bash
bison -d -v -o grammar/parser.cpp grammar/parser.y \
&& flex --header-file=grammar/lexer.hpp -o grammar/lexer.cpp grammar/lexer.l \
&& g++ grammar/lexer.cpp grammar/parser.cpp common/node.cpp common/visitor.cpp semantical_analyzer/analyzer.cpp main.cpp -o program \
&& ./program $1 $2 $3 $4\
&& java -jar jasmin/jasmin.jar generateds/$2 \
&& java outs/$3
