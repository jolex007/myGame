#include "Parser.h"

#include <fstream>

void Parser::openUnitJson(const std::string& file_path)
{
    std::ifstream inp(file_path);
    inp >> Parser::unit_file;
    inp.close();
}

std::vector<std::string> Parser::getUnitNames(const std::string& nation_name)
{
    std::vector<std::string> unit_names;
    unit_names.reserve(unit_file.size());

    for (auto& unit : unit_file[nation_name]) {
        unit_names.push_back(unit["name"]);
    }

    return unit_names;
}

std::vector<std::string> Parser::getNationNames()
{
    std::vector<std::string> nations;

    for (auto& nation : unit_file.items()) {
        nations.push_back(nation.key());
    }

    return nations;
}

const json& Parser::getUnitParams(const std::string& nation_name, const std::string& unit_name)
{
    for (auto& unit : unit_file[nation_name]) {
        if (unit["name"] == unit_name) {
            return unit;
        }
    }

    throw std::runtime_error("filed an unknown unit");
}