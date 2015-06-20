public class Test {
    public static void main(String[] args) {
        ListLexer lexer = new ListLexer(args[0]); // parse command-line arg
        ListParser parser = new ListParser(lexer);
        parser.list(); // begin parsing at rule list
    }
}
