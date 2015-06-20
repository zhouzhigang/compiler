/**
 * Test the lexer pattern.
 */
public class Test {
    public static void main(String[] args) {
        String input = "[a, b]";
        ListLexer lexer = new ListLexer(input); // create the concrete lexer
        Token t = lexer.nextToken(); // get the first token
        while (t.type != Lexer.EOF_TYPE) {
            System.out.println(t);
            t = lexer.nextToken(); // get the next token repeatly if not EOF of token type
        }
        System.out.println(t); // EOF
    }
}
