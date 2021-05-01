//
// Created by irwin on 01/05/2021.
//

#ifndef MONKEY___LEXER_H
#define MONKEY___LEXER_H
#include "token.h"

#include <string>

namespace monkey {
    class Lexer {
    public:
        void New(std::string& input);
        Token NextToken();
    private:
        void readChar();
        char peekChar();
        std::string readIdentifier();
        std::string readNumber();
        std::string readString();
        void skipWhitespace();

        std::string input;
        int position;
        int readPosition;
        char ch;
    };
}


#endif //MONKEY___LEXER_H
