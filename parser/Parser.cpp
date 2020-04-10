#include "Parser.h"

#include <fstream>

void Parser::openUnitJson(std::string file_path)
{
    std::ifstream inp(file_path);
    inp >> Parser::unit_file;
    inp.close();
}

void Parser::openBuildingJson(std::string file_path)
{
    std::ifstream inp(file_path);
    inp >> Parser::building_file;
    inp.close();
}

std::vector<std::string> Parser::getUnitNames()
{
    std::vector<std::string> unit_names;
    unit_names.reserve(unit_file.size());

    for (auto& unit : unit_file) {
        unit_names.push_back(unit["name"]);
    }

    return unit_names;
}

std::vector<std::string> Parser::getBuildingNames()
{
    std::vector<std::string> building_names;
    building_names.reserve(building_file.size());

    for (auto& building : building_file) {
        building_names.push_back(building["name"]);
    }

    return building_names;
}

const json& Parser::getUnitParams(std::string unit_name)
{
    for (auto& unit : unit_file) {
        if (unit["name"] == unit_name) {
            return unit;
        }
    }
}

const json& Parser::getBuildingParams(std::string building_name)
{
    for (auto& building : building_file) {
        if (building["name"] == building_name) {
            return building;
        }
    }
}