//
// Created by irwin on 02/05/2021.
//

#include "repl.h"

const std::string PROMPT = ">> ";

void repl_start() {
    std::string line;
    while (true) {
        std::cout << PROMPT;
        std::getline(std::cin, line);
        if (line.empty()) return;

        monkey::Lexer l;
        l.New(line);

        for (monkey::Token tok = l.NextToken(); tok.type != monkey::END; tok = l.NextToken()) {
            std::cout << "type: '" << tok.type << "', literal: '" << tok.literal << "'" << std::endl;
        }
    }
}

