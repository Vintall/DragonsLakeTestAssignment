#pragma once
#include <string.h>
#include <iostream>
#include "Window.h"
class ConsoleLineHandler
{
private:
	std::string application_path;
	static ConsoleLineHandler* instance;
	ConsoleLineHandler();
public:
	static ConsoleLineHandler* GetInstance();
	void SetApplicationPath(char*);
	std::string GetApplicationPath();
	void ReadConsoleCommandPrompt(int, char*[]);
	void CommandHandler(const std::string& command, const std::string& value);
};