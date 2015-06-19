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

    public void match(char x) {
        if (c == x) {
            consume();
        } else {
            throw new Error("expecting " + x + "; found " + c);
        }
    }

    public abstract Token nextToken();

    public abstract String getTokenName(int tokenType);
}