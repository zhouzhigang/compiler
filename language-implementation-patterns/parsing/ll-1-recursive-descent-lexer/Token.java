/**
 * Token(type and text propertity).
 *
 * Ther is no detail tokens or token enumerations.
 */
public class Token {
    /**
     * Token type.
     */
    public int type;
    /**
     * Token text propertity.
     */
    public String text;

    /**
     * Token constructor.
     */
    public Token(int type, String text) {
        this.type = type;
        this.text = text;
    }

    @Override
    public String toString() {
        String tname = ListLexer.tokenNames[type];
        return "<'" + text + "', " + tname + ">";
    }
}
