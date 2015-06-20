/**
 * Concrete Lexer: List language lexer.
 * LL(1) Recursive-Descent Lexer.
 *
 * Token T's definition and corresponding lexical rule method T(), eg. NAME -> NAME().
 * Concrete nextToken method.
 * 
 */
public class ListLexer extends Lexer {
    // detail token type in list language.
    // Note: Lexers also typically deal with whitespace and comments.

    /**
     * Token type NAME represents the identifier category.
     */
    public static int  NAME = 2;
    public static int COMMA = 3;
    public static int LBRACK = 4;
    public static int RBRACK = 5;

    public static String[] tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

    @Override
    public String getTokenName(int x) {
        return tokenNames[x];
    }

    /**
     * ListLexer constructor.
     * @param  input
     */
    public ListLexer(String input) {
        super(input);
    }

    @Override
    public Token nextToken() {
        while (c != EOF) { // not EOF
            
            // skip comment and other tokens.

            switch (c) { // which token approaches?
                case ' ': case '\t': case '\n': // skip withespace
                    WS();
                    continue;
                case ',': // match ','
                    consume();
                    return new Token(COMMA, ",");
                case '[': // match '['
                    consume();
                    return new Token(LBRACK, "[");
                case ']': // match '['
                    consume();
                    return new Token(RBRACK, "]");
                default: // match 'NAME'
                    if (isLETTER()) {
                        return NAME();
                    } else {
                        throw new Error("invalid character: " + c);
                    }
            }
        }
        return new Token(EOF_TYPE, "<EOF>");
    }


    /**
     * NAME/identifier is sequence >= 1 letter.
     * NAME: ('a'..'z'|'A'..'Z')+
     * @return NAME token
     */
    Token NAME() {
        StringBuilder buf = new StringBuilder();
        // on or more(...)+ subrules use do-while loops.
        do {
            buf.append(c);
            consume();
        } while (isLETTER());
        return new Token(NAME, buf.toString());
    }

    /**
     * Ignore any whitespace.
     * WS: (' '|'\t'|'\n'|'\r')*
     */
    void WS() {
        while (c == ' ' || c == '\t' || c == '\n') {
            consume();
        }
    }

    /**
     * check if current char is a letter.
     * @return true if current char is a letter
     */
    boolean isLETTER() {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
}
