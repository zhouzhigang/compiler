# Flex and Yacc

## Overview

Generate the executable file.

    yacc -dv mycalc.y
    lex mycalc.l
    cc -o mycalc y.tab.c lex.yy.c


mycalc.y -> (yacc) -> y.tab.c
                   -> y.tab.h
mycalc.l -> (lex)  -> lex.yy.c



## Reference
* [Lex & Yacc Tutorial by Tom Niemann](http://epaperpress.com/lexandyacc/download/LexAndYaccTutorial.pdf)
* [ANSI C grammar, Lex specification](http://www.lysator.liu.se/c/ANSI-C-grammar-l.html)
* [ANSI C grammar, Yacc specification](http://www.lysator.liu.se/c/ANSI-C-grammar-y.html)
