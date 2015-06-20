# Parsing

## Identify Phrase Structure
Tke `return x + 1;` for example.

`x + 1` plays the role of `expression`;

the entire statement is a `return statement`, which is also a kind of statement.

`if x < 0 then x = 0;`

## Building Recursive-Descent Parser
A `parse` checks whether a `sentence` conforms to the syntax of a `language`.

To verify language membership, a parser has to identify a sentence's parse tree.

In fact, the parser doesn't actually have to construct a tree data structure in memory. It's enough to just recognize the various sub-structures and the associated tokens.

To avoid building parse trees, we trace them out implictly via a function call `sequence`(a call tree). All we have to do is make a function for each named substructure(interior node) of the parse tree.

Each function `f`, execute code to match its children.
To match a `substructure(subtree)`, `f` call the function associated with that subtree.
To match a `token` children, `f` call a `match()` support function.

    /** To parse a statement, call stat() */
    void stat()         { returstat(); }
    void returnstat()   { match("return"); expr(); match(";"); }
    void expr()         { mathc("x"0; match("+"); match("1"); }


Function `match()` advances an input cursor after comparing the current input token to its arguement.

When we advance the cursor, we `consume` that token since the parser never has to look at it again.


    /** Parse the three kinds of statements found in the parse trees: if, return and assignment statement. */
    void stat() {
        if ( <<lookahead token is return>> )            returnstat();
        else if ( <<lookahead token is identifier>> )   assign();
        else if ( <<lookahead token is if>> )           ifstat();
        else <<parse error>>
    }


`Top-down parser`: starts at the top of the parse tree and works its way down to the token leaf nodes.

`LL(1) Recursive-Descent Parser`
`descent` refers to its top-down nature, 
`recursive` refers to the fact the its functions potentially call themselves.


## Parser Construction Using a Grammar DSL

`Mapping Grammars to Recursive-Descent Recognizers`

    stat        : returnstat            // "return x+0;" or
                | assign                // "x=0;" or
                | ifstat                // "if x<0 then x=0;"
                ;
    returnstat  : 'return' expr ';' ;   // single-quoted strings are tokens
    assign      : 'x' '=' expr ;
    ifstat      : 'if' expr 'then' stat;
    expr        : 'x' '+' '0'           // used by returnstat
                | 'x' '<' '0'           // used by if conditional
                | '0'                   // used in assign
                ;

## Tokenizing Sentences

Recognize that feed off character streams are called `tokenizers` or `lexers`.
`LL(1) Recursive-Descent Lexer`

Just as an overall sentence has structure, the individual tokens have structure.
At the character level, we reer to syntax as the `lexical structure`.


    Number  : '0'..'9'+ ;           // 1-or-more digits(0..9)
    ID      : ('a'..'z'|'A'..'Z')   // 1-or-more upper or lower case letters

Now we can make a better version of rule `expr` using generic vaiable names and numbers instead of specific ones.

    expr        : ID '+' Number         // used by returnstat
                | ID '<' Number         // used by if condition
                | Number                // used in assign
                ;

The rule still isn't general enough, but it demonstrates how lexical and syntacitc rules can interact.


A concrete example
recognize list of names such as `[a, b, c]` and nested list such as `[a, [b, c], d]`.

ANLTR grammer

    grammar NestedNameList
    list        : '[' elements ']';         //match bracketed list
    elements    : element (',' element)* ;  // match comma-separated list
    element     : NAME | list;              // element is name or nested list
    NAME        : ('a'..'z'|'A'..'Z')+ ;    // NAME is sequence of >=1 letter

## Tokenizing Sentences
* [Mapping Grammars to Recursive-Descent Recognizers](parsing/grammar-recursive-descent/README.md)
* [LL(1) Recursive-Descent Lexer](parsing/ll-1-rescursive-descent-lexer/README.md)
* [LL(1) Recursive-Descent Parer]()
* [LL(k) Recursive-Descent parer]()
