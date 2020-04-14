#include <iostream>
#include <vector>
#include "factories/Factory.h"
#include "parser/Parser.h"
#include "config.h"

using std::vector;
using std::string;

int main()
{
    Parser::openUnitJson(static_cast<std::string>(PROJECT_SOURCE_DIR) + static_cast<std::string>("/gameinfo/units.json"));

    Factory rus_factory("Russian");
    Factory en_factory("England");
    
    vector<std::shared_ptr<Unit> > units;

    std::cout << "Factories created\n";

    units.push_back(rus_factory.createWarrior("Archer"));
    units.push_back(rus_factory.createWarrior("Swordman"));
    units.push_back(en_factory.createWorker("Builder"));

    /* do next move */

    for (size_t i = 0; i < units.size(); i++) {
        units[i]->nextMove();
    }

    return 0;
}