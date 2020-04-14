#pragma once

#include <iostream>
#include <map>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Parser
{
private:
    /* json file */
    inline static json unit_file;
    inline static json building_file;
    
public:
    /* methods for opening parser */
    /* arguments:                 */
    /* json file path             */
    static void openUnitJson(const std::string&);
    static void openBuildingJson(const std::string&);

    /* methods to get vector of unit/building names */
    /* arguments:                                   */
    /* nation name                                  */
    static std::vector<std::string> getUnitNames(const std::string&);
    static std::vector<std::string> getBuildingNames(const std::string&);

    /* method to get vector of nation names */
    static std::vector<std::string> getNationNames();

    /* method to get params of unit */
    /* arguments:                   */
    /* nation name, unit name       */
    static const json& getUnitParams(const std::string&, const std::string&);
    static const json& getBuildingParams(const std::string&, const std::string&);
};