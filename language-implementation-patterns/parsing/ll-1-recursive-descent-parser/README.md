# LL(1) Recursive-Descent Parser

This pattern analyzes the syntactic structure of the token sequence of a phrase using a single lookahead token.

## Computing Lookahead Sets
A lookahead set is the set of tokens that can begin a particular alternative.
The parser should attempt the alternative that can start with the current lookahead token.

Formally, we compute lookahead sets using two computations: `FIRST` and `FOLLOW`.

Start with the easiest lookahead computation case: an alternative that begins with a token reference. Its lookahead set is just that token.

    stat: `if` ...      // lookahead set is {if}
        | 'while' ...   // lookahead set is {while}
        | 'for' ...     // lookahead set is {for}
        ;

If an alternative begins with a rule reference insterad of a token reference, the lookahead set is whatever begins any alternative of that rule.

    body_element
        : stat      // lookahead is {if, while, for}
        | LABEL ':' // lookahead is {LABEL}
        ;

Lookahead only get complicated when we consider empty alternatives.

    optional_int
        : '=' expr;
        | // empty alternative
        ;


