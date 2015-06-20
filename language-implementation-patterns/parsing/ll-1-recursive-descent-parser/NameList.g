list        : '[' elements ']' ;        // match bracketed list
elements    : element (',' element)* ;  // match comma-separated list
element     : NAME | list ;             // element is name or nested list
