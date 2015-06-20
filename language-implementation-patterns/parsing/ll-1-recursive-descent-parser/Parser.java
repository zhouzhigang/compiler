/**
 * Abstract Parser.
 *
 * Two state variables:
 * Input token stream and a lookahead buffer.
 */
public class Parser {
    /**
     * The input token stream: from where do we get tokens.
     */
    Lexer input;

    /**
     * Lookahead buffer: lookahead token.
     */
    Token lookahead;

    /**
     * Constructor.
     */
    public Parser(Lexer input) {
        this.input = input;
        consume();
    }

    /**
     * Compare expected tokens against the lookahead symbol.
     * If lookahead token type matches x, consume and return, else error.
     */
    public void match(int x) {
        if (lookahead.type == x) {
            consume();
        } else {
            throw new Error("expecting " + input.getTokenName(x) +
                    "; found " + lookahead);
        }
    }

    /**
     * Consume input, put next token as lookahead.
     */
    public void consume() {
        lookahead = input.nextToken();
    }
}
