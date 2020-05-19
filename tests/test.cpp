#include <iostream>
#include <vector>
#include "creating/units/Factory.h"
#include "parser/Parser.h"
#include "gtest/gtest.h"
#include "config.h"

class FactoryTests : public ::testing::Test
{
public:
    Factory factory;

protected:

    void SetUp() override; // Before all tests
};

void FactoryTests::SetUp()
{
    factory = Factory("Russian");
    Parser::openUnitJson(static_cast<std::string>(PROJECT_SOURCE_DIR) + static_cast<std::string>("/gameinfo/units.json"));
}

TEST_F(FactoryTests, createUnitArcher)
{
    ASSERT_NO_THROW(factory.createUnit("Archer"));
}

TEST_F(FactoryTests, createUnitSwordman)
{
    ASSERT_NO_THROW(factory.createUnit("Swordman"));
}

TEST_F(FactoryTests, UnitArcherFieldsCoreect)
{
    std::shared_ptr<Unit> ptr;
    ASSERT_NO_THROW(ptr = factory.createUnit("Archer"));
    ASSERT_EQ(ptr->getPower(), 5.0);
    ASSERT_EQ(ptr->getSteps(), 2);
}

TEST_F(FactoryTests, UnitSwordmanFieldsCoreect)
{
    std::shared_ptr<Unit> ptr;
    ASSERT_NO_THROW(ptr = factory.createUnit("Swordman"));
    ASSERT_EQ(ptr->getPower(), 7.0);
    ASSERT_EQ(ptr->getSteps(), 2);
}
