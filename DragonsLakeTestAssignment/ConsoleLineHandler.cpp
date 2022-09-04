#include "ConsoleLineHandler.h"


ConsoleLineHandler::ConsoleLineHandler() {}

ConsoleLineHandler* ConsoleLineHandler::instance = 0;

ConsoleLineHandler* ConsoleLineHandler::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ConsoleLineHandler();
	}
	return instance;
}
void ConsoleLineHandler::SetApplicationPath(char* path)
{
	std::string string_path = path;
	int last_slash_index = 0;
	for (int i = strlen(path) - 1; i >= 0; i--)
		if (path[i] == '\\')
		{
			last_slash_index = i+1;
			break;
		}
	application_path = string_path.substr(0, last_slash_index);
}
std::string ConsoleLineHandler::GetApplicationPath()
{
	return application_path;
}
void ConsoleLineHandler::ReadConsoleCommandPrompt(int argc, char* argv[])
{
	SetApplicationPath(argv[0]);

	if (argc == 1)
		return;
	std::string line;
	for (int i = 1; i < argc; i++)
	{
		line = argv[i];

		if (line[0] == '-')
		{
			CommandHandler(argv[i], argv[i + 1]);
		}
	}
}
void ConsoleLineHandler::CommandHandler(const std::string& command, const std::string& value)
{
	if (command == "-window")
	{
		int x, y;
		for (int i = 0; i < value.size(); i++)
			if (value[i] == 'x')
			{
				x = std::stoi(value.substr(0, i));
				y = std::stoi(value.substr(i + 1, value.size()));
				break;
			}
		Window::GetInstance()->SetWindow(x, y);
	}
}