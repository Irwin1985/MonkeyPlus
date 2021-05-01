#include <iostream>
#include "lexer.h"

int main() {

    monkey::Lexer l;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        l.New(line);
        monkey::Token tok;
        tok = l.NextToken();
        while (tok.type != monkey::END) {
            std::cout << "type: " << tok.type << ", Literal: '" << tok.literal << "'" << std::endl;
            tok = l.NextToken();
        }
    }
    return 0;
}
