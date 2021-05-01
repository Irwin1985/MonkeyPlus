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

    bool Lexer::isLetter(char ch) {
        return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
    }

    bool Lexer::isDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }

    void Lexer::skipWhitespace() {
        while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            readChar();
        }
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

    std::string Lexer::readNumber() {
        int start = position;
        while (isDigit(ch)) {
            readChar();
        }
        return input.substr(start, position - start);
    }

    std::string Lexer::readIdentifier() {
        int start = position;
        while (isLetter(ch)) {
            readChar();
        }
        return input.substr(start, position - start);
    }

    Token Lexer::NextToken() {
        Token tok;

        skipWhitespace();

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
                break;
            default:
                if (isLetter(ch)) {
                    tok.literal = readIdentifier();
                    tok.type = LookupIdent(tok.literal);
                    return tok;
                } else if(isDigit(ch)) {
                    tok.type = INT;
                    tok.literal = readNumber();
                    return tok;
                } else {
                    tok = Token(ILLEGAL, ch);
                }
                break;
        }
        readChar();
        return tok;
    }
}
