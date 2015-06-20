/**
 * Abstract Lexer.
 * Contains some support code, no code to match detail tokens.
 *
 * The nexToken and getTokenName method should be imolemented in concrete Lexer.
 * 
 */
public abstract class Lexer {
    /**
     * Identity for end of file char.
     */
    public static final char EOF = (char) -1;
    /**
     * EOF token type.
     */
    public static final int EOF_TYPE = 1;
    /**
     * Input string.
     */
    String input;
    /**
     * Current position.
     */
    int p = 0;
    /**
     * Current character.
     */
    char c;

    /**
     * The constructor records the input string,
     * and primes the lookahead by loading the first character into lookahead character c.
     */
    public Lexer(String input) {
        this.input = input;
        c = input.charAt(p); // prime lookahead
    }

    /**
     * Move one character, detect "end of file".
     */
    public void consume() {
        p++;
        if (p >= input.length()) {
            c = EOF;
        } else {
            c = input.charAt(p);
        }
    }

    /**
     * Ensure x is the next character on the input stream.
     */
    public void match(char x) {
        if (c == x) {
            consume();
        } else {
            throw new Error("expecting " + x + "; found " + c);
        }
    }

    /**
     * Match tokens or routes traffic to the appropriate method.
     * @return token
     */
    public abstract Token nextToken();

    /**
     * To get readable token information or generate good error message.
     * @param  x token index
     * @return   token name
     */
    public abstract String getTokenName(int tokenType);
}
