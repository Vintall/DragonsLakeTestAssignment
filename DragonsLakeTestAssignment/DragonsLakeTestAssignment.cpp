#include "GameEngine.h"
#include "Window.h"
#include "ConsoleLineHandler.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    ConsoleLineHandler::GetInstance()->ReadConsoleCommandPrompt(argc, argv);
    return run(new GameEngine);
}
