#pragma once

#include <iostream>
#include <map>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Parser
{
private:
    /* this is json file */
    inline static json unit_file;
    inline static json building_file;
    
public:
    /* methods for parser */
    static void openUnitJson(std::string);
    static void openBuildingJson(std::string);

    static std::vector<std::string> getUnitNames();
    static std::vector<std::string> getBuildingNames();

    static const json& getUnitParams (std::string);
    static const json& getBuildingParams (std::string);

    static void f()
    {
        std::cout << Parser::getUnitParams("Archer") << "\n";
        std::cout << Parser::getUnitParams("Swordman") << "\n";
    }
};