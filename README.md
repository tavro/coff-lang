# coff-syntax (BNF)

`<program> ::= <main class>`

`<main class> ::= <class header> <class body>`

`<class header> ::= CLASS <identifier> [EXTENDS <identifier>] { }`

`<class body> ::= { <class members> }`

`<class members> ::= <class member> | <class members> <class member>`

`<class member> ::= <main method> | <field declaration>`

`<main method> ::= PUBLIC VOID main() <block>`

`<field declaration> ::= <type> <variable list> ;`

`<type> ::= INT | FLOAT | BOOL | CHAR | STRING`

`<variable list> ::= <variable> | <variable list> , <variable>`

`<variable> ::= <identifier> | <identifier> = <expression>`

`<block> ::= { <statements> }`

`<statements> ::= <statement> | <statements> <statement>`

`<statement> ::= <if statement> | <while statement> | <for statement> | <assignment> | <method call> | <return statement>`

`<if statement> ::= IF ( <expression> ) <block> [ELSE <block>]`

`<while statement> ::= WHILE ( <expression> ) <block>`

`<for statement> ::= FOR ( <for init> ; <expression> ; <assignment> ) <block>`

`<for init> ::= <assignment> | <variable declaration>`

`<variable declaration> ::= <type> <variable> | <type> <variable list>`

`<assignment> ::= <identifier> = <expression>`

`<method call> ::= <identifier> ( [ <argument list> ] )`

`<argument list> ::= <expression> | <argument list> , <expression>`

`<return statement> ::= RETURN <expression> ;`

`<expression> ::= <term> | <expression> <addop> <term>`

`<term> ::= <factor> | <term> <mulop> <factor>`

`<factor> ::= <identifier> | <literal> | ( <expression> ) | <method call>`

`<addop> ::= + | -`

`<mulop> ::= * | / | %`

`<identifier> ::= <letter> | <identifier> <letter or digit>`

`<literal> ::= <integer literal> | <float literal> | <bool literal> | <char literal> | <string literal>`
