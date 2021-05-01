//
// Created by irwin on 01/05/2021.
//

#include "token.h"

namespace monkey {
    std::map<std::string, TokenType> keywords({
            {"fn", FUNCTION},
            {"let", LET}
    });

    TokenType LookupIdent(std::string ident) {
        if (keywords.find(ident) == keywords.end()) {
            return IDENT;
        }
        return keywords[ident];
    }
}
