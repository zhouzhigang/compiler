# LL(1) Recursive-Descent Lexer

`Lexer` are also called `scanners`, `lexical analyzers`, and `tokenizers`.

Lexers derive a stream of tokens from a character stream by recognizing lexxical patterns.

The goal of a lexer is to emit a sequence of tokens.
Each token has two primary attributes: a `token type`(symbol category) and the text associated with it.

To build a lexer by hand, we write a method for each token definition(lexical rule).
In other words, token `T`'s definition becomes method `T()`. eg. `NAME` -> `NAME()`.

To make the lexer look like an enumeration of tokens, it's handy to define a method called `nextToken()`.
`nextToken()` uses the lookahead character(character under the input cursor) to route control flow to the appropriate recognition method,

    public Token nextToken() {
        while ( <<lookahead-char>> != EOF ) { // EOF == -1 per in java.io
            if ( <<comment-start-sequence>> ) { COMMET(); continue; }
            ...// other skip tokens
            switch ( <<lookahead-char>> ) { // which token approaches?
                case <<whitespace>> : { consume(); continue; } // skip
                case <<char-predicting-T1>> : return T1(); // match T1
                case <<char-predicting-T2>> : return T2();
                ...
                case <<char-predicting-TN>> : return TN();
                default : <<error>>
            }
        }
        return <<EOF-token>>; // return token with EOF_TYPE token type
    }

To use this lexer patter, we create an instance of a lexer from an input string ro stream reader. Our parser object then feeds off this lexer, calling its `nextToken()` method to extract tokens.

    MyLexer lexer = new MyLexer("<<input-sentece>>");   // create lexer
    MyParser parser = new MyParser(lexer);              // cater parser
    parser.<<start_rule>>(); // begin parsing, looking for a list sentence
