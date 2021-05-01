//
// Created by irwin on 01/05/2021.
//
#include "lexer.h"
namespace monkey {
    void Lexer::New(std::string& input) {
        this->input = input;
        readPosition = 0;
        readChar();
    }

    void Lexer::readChar() {
        if (readPosition >= input.size()) {
            ch = 0;
        } else {
            ch = input[readPosition];
        }
        position = readPosition;
        readPosition += 1;
    }

    Token Lexer::NextToken() {
        Token tok;
        switch (ch) {
            case '=':
                tok = Token(ASSIGN, ch);
                break;
            case ';':
                tok = Token(SEMICOLON, ch);
                break;
            case '(':
                tok = Token(LPAREN, ch);
                break;
            case ')':
                tok = Token(RPAREN, ch);
                break;
            case ',':
                tok = Token(COMMA, ch);
                break;
            case '+':
                tok = Token(PLUS, ch);
                break;
            case '{':
                tok = Token(LBRACE, ch);
                break;
            case '}':
                tok = Token(RBRACE, ch);
                break;
            case 0:
                tok.literal = "";
                tok.type = END;
            default:
                break;
        }
        readChar();
        return tok;
    }
}
