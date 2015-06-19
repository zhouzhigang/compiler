# Mapping Grammars to Recursive-Descent Recognizers

The translates a grammar to a recursive-descent recognizer that matches phrases and sentences in the language specified by the grammar.

This pattern identifies the core control-flow framwork for any recursive-descent lexer, parser, or tree parser.

Grammars are very concise way to express the languages ou intend to recognize.
Grammar are excellent documentation that can go into a reference manual and into parsing code as comments.

Example

    r : r X ;

It will leading to an infinite loop if we call itself immediately.

    void r() { r(); match(X); }

Besides left-recursive rules, there are other grammar constructs that yield nondeterministic resursive-descent recognizers.

## Implementation

A grammar `G` is a set of rules from which we generate a class definition containing a method for each rule.

    public class G extends Parser { // parser definition written in Java
        <<token-type-definitions>>
        <<suitable-constructor>>
        <<rule-methods>>
    }

Class `Parser` defines the state a typical parser needs, such as a lookahread token or tokens and an input stream.

## Converting Rules

For each rule `r`, defined in a grammar, we build a method of the same name.

    public void r() {
        //...
    }


## Converting Tokens

Token references for token type `T` become calls to `match(T)`.
`match()` is a support method in `Parser` that consumes a token if `T` is the current lookahead token.
If there is a mismatch, `match()` throws an exception.

Also, we need to define token type `T` somewhere, either in the `parser` object or in our `lexer` object.

    public static final int T = <<sequential-integer>>;

We'll also probably need this:

    public static final int INVALID_TOKEN_TYPE = 0; // to be explict
    public static final int EOF = -1;

**NOTE**: Why not use `enum` instead?

## Converting Subrules

Alternatives become either a `switch` or an `if-then-else` sequence, depending on the complexity of the lookahead decision.
Each alternative gets an expression that predicts whether that alternative would succeed at the current input location.

    (<<alt1>>|<<alt2>>|..<altN>>)

The most general subrule implementation looks like this:

    if (<<lookahead-predicts-alt1>> ) { <<match-alt1>> }
    else if (<<lookahead-predicts-alt2>> ) { <<match-alt2>> }
    ...
    else if (<<lookahead-predicts-altN>> ) { <<match-altN>> }
    else <<throw-exception>>

If all of those lookahead expressions only test a single symbol lookaheadm we can generate a `switch` statement, which is usually more efficient.

    switch (<<lookahead-token>> ) {
        case <<token1-predicting-alt1>> :
        case <<token2-predicting-alt1>> :
        ...
            <<match-alt1>>
            break;
        case <<token1-predicting-alt2>> :
        case <<token2-predicting-alt2>> :
        ...
            <<match-alt2>>
            break;
        case <<token1-predicting-altN>> :
        case <<token2-predicting-altN>> :
        ...
            <<match-altN>>
            break;
        default : <<throw-exception>>
    }

## Converting Subrule Operators

optional subrule `(T)?`

    if ( <<lookaead-is-T>> ) { mathc(T); } // no error else clause

one or more `(...)+`

    do {
        <<code-matching-alternatives>>
    } while ( <<lookahead-predicts-an-alt-of-subrule>> );

zero or more `(...)*`

    while ( <<lookahead-predicts-an-alt-of-subrule>> ) {
        <<code-matching-alternatives>>
    }

