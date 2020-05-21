#include <iostream>
#include <vector>
#include "creating/units/Factory.h"
#include "parser/Parser.h"
#include "config.h"
#include "client/Handler.h"
#include "client/Client.h"
// #include "client/EventQueue.h"
#include <thread>

using std::vector;
using std::string;

int main()
{
    std::cout << "Started" << std::endl;

    Parser::openUnitJson(PROJECT_SOURCE_DIR + std::string("/gameinfo/units.json"));
    Parser::openMapFile(PROJECT_SOURCE_DIR + std::string("/gameinfo/map.txt"));

    Client client;

    std::thread handle_keyboard(Handler::handle);
    std::thread client_working([&client](){
        client.run();
    });
    handle_keyboard.join();
    client_working.join();

    return 0;
}