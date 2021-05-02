//
// Created by irwin on 01/05/2021.
//

#ifndef MONKEY___TOKEN_H
#define MONKEY___TOKEN_H

#include <string>
#include <map>

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
    TokenType LookupIdent(std::string ident);

    // create enumerable
    const TokenType ILLEGAL = "ILLEGAL";
    const TokenType END = "END";
    // identifiers + literals
    const TokenType IDENT = "IDENT"; // add, foobar, x, y, ...
    const TokenType INT = "INT"; // 12343456

    // Operators
    const TokenType ASSIGN = "=";
    const TokenType PLUS = "+";
    const TokenType MINUS = "-";
    const TokenType BANG = "!";
    const TokenType ASTERISK = "*";
    const TokenType SLASH = "/";

    const TokenType LT = "<";
    const TokenType GT = ">";
    const TokenType EQ = "==";
    const TokenType NOT_EQ = "!=";

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
    const TokenType TRUE = "TRUE";
    const TokenType FALSE = "FALSE";
    const TokenType IF = "IF";
    const TokenType ELSE = "ELSE";
    const TokenType RETURN = "RETURN";

}

#endif //MONKEY___TOKEN_H
