public class Test {
    public static void main(String[] args) {
        String input = "[a, b]";
        ListLexer lexer = new ListLexer(input);
        Token t = lexer.nextToken();
        while (t.type != Lexer.EOF_TYPE) {
            System.out.println(t);
            t = lexer.nextToken();
        }
        System.out.println(t); // EOF
    }
}