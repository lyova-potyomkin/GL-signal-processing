#include "timespan.h"
#include "cli.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    std::cout << "Welcome! Type a command ('help' for help)\n";
    std::string cmd;
    std::vector<Parameter> params;
    JumpTable jump_table = create_table();
    do {
        std::cout << ">> ";
        std::getline(std::cin, cmd);
        params = {};
        if (cmd == "new") {
            params = {LENGTH, SAMPLE_RATE};
        } else if (cmd == "gen") {
            params = {AMP, PHASE, FREQ, START, FINISH, TYPE};
        } else if (cmd == "save-wav" || cmd == "save-csv") {
            params = {FILENAME};
        } else if (cmd == "load") {
            params = {FILENAME, SAMPLE_RATE};
        }
        if (jump_table.count(cmd)) {
            get_args(params);
            try {
                jump_table[cmd](params);
            } catch (std::invalid_argument& e) {
                std::cerr << "Invalid parameter: " << e.what() << '\n';
            } catch (std::runtime_error& e) {
                std::cerr << e.what() << '\n';
            }
        } else if (cmd != "quit" && cmd != "") {
            std::cerr << "Invalid command!\n";
        }
    } while (cmd != "quit" && !std::cin.eof());
    return 0;
}


