#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "nlohmann/json.hpp"
#include "field/MapProperties.h"
using json = nlohmann::json;

class Parser
{
private:
    /* json file */
    inline static json unit_file;
    inline static std::vector<std::vector<char>> map_file;
    
public:
    /* methods for opening parser */
    /* arguments:                 */
    /* json file path             */
    static void openUnitJson(const std::string&);
    static void openMapFile(const std::string&);

    /* methods to get vector of unit/building names */
    /* arguments:                                   */
    /* nation name                                  */
    static std::vector<std::string> getUnitNames(const std::string&);

    /* method to get vector of nation names */
    static std::vector<std::string> getNationNames();

    static std::vector<std::vector<Relief>> getMap();

    /* method to get params of unit */
    /* arguments:                   */
    /* nation name, unit name       */
    static const json& getUnitParams(const std::string&, const std::string&);
};