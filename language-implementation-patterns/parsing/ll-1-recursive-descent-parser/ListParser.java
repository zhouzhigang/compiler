/**
 * Concrete Parse.
 * LL(1) Recursive-Descent Parser.
 *
 * Use lookahead to make parsing decisions.
 */
public class ListParser extends Parser {
    public ListParser(Lexer input) {
        super(input);
    }

    /**
     * Match bracketed list.
     * list : '[' elements ']' ;
     */
    public void list() {
        match(ListLexer.LBRACK);
        elements();
        match(ListLexer.RBRACK);
    }

    /**
     * Match elements.
     * elements: element (',' element)* ;
     */
    void elements() {
        element();
        // zero or more use while loop.
        while (lookahead.type == ListLexer.COMMA) { // lookahead: COMMA predicts entering the (...)* subrule.
            match(ListLexer.COMMA);
            element();
        }
    }

    /**
     * Match element(element is name or nested list).
     * element: name | list ;
     */
    void element() {
        if (lookahead.type == ListLexer.NAME) { // Name predict the first alternative.
            match(ListLexer.NAME);
        } else if (lookahead.type == ListLexer.LBRACK) { // LBRACK predict the second alternative.
            list();
        } else {
            throw new Error("expecting name or list; found " + lookahead);
        }
    }
}
