//
// Created by irwin on 01/05/2021.
//

#ifndef MONKEY___TOKEN_H
#define MONKEY___TOKEN_H

#include <string>

namespace monkey {
    typedef std::string TokenType;
    class Token {
    public:
        TokenType type;
        std::string literal;
        Token() {} // empty constructor
        Token(TokenType type, std::string literal) {
            this->type = type;
            this->literal = literal;
        }
        Token(TokenType type, char ch) {
            this->type = type;
            this->literal = std::string(1, ch);
        }
    };

    // create enumerable
    const TokenType ILLEGAL = "ILLEGAL";
    const TokenType END = "END";
    // identifiers + literals
    const TokenType IDENT = "IDENT"; // add, foobar, x, y, ...
    const TokenType INT = "INT"; // 12343456

    // Operators
    const TokenType ASSIGN = "=";
    const TokenType PLUS = "+";

    // Delimiters
    const TokenType COMMA = ",";
    const TokenType SEMICOLON = ";";
    const TokenType LPAREN = "(";
    const TokenType RPAREN = ")";
    const TokenType LBRACE = "{";
    const TokenType RBRACE = "}";

    // keywords
    const TokenType FUNCTION = "FUNCTION";
    const TokenType LET = "LET";
}

#endif //MONKEY___TOKEN_H
