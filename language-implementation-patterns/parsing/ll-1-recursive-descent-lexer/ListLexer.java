/**
 * List language lexer.
 * LL(1) Recursive-Descent Lexer.
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

    /**
     * To get readable token information or generate good error message.
     * @param  x token index
     * @return   token name
     */
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


    /**
     * Match tokens or routes traffic to the appropriate method.
     * @return token
     */
    public Token nextToken() {
        while (c != EOF) {
            switch (c) {
                case ' ': case '\t': case '\n':
                    WS();
                    continue;
                case ',':
                    consume();
                    return new Token(COMMA, ",");
                case '[':
                    consume();
                    return new Token(LBRACK, "[");
                case ']':
                    consume();
                    return new Token(RBRACK, "]");
                default:
                    if (isLETTER()) {
                        return NAME();
                    } else {
                        throw new Error("invalid character: " + c);
                    }
            }
        }
        return new Token(EOF_TYPE, "<EOF>");
    }

    // write the method for each token definition(lexical rule).
    // Token T's definition becomes method T(), eg. NAME -> NAME()

    /**
     * NAME/identifier is sequence >= 1 letter.
     * NAME: ('a'..'z'|'A'..'Z')+
     * @return [description]
     */
    Token NAME() {
        StringBuilder buf = new StringBuilder();
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