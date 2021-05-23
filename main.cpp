#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#ifdef _MSC_VER
#define getch() _getch()
#endif

static void handleExit()
{
	std::printf("Press any key to exit");
	int c = getch();
}

int main(int argc, char** argv)
{
	std::atexit(handleExit);

	std::string fileName = "";
	if (argc == 2)
	{
		fileName = argv[1];
	}
	else
	{
		std::printf("Enter file to search: ");
		std::getline(std::cin, fileName);
	}

	std::printf("Enter text to look for: ");
	std::string searchFor = "";
	std::getline(std::cin, searchFor);

	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::printf("Unable to open file\n");
		return EXIT_FAILURE;
	}

	std::string line = "";
	for (std::size_t idx = 1; std::getline(file, line); idx++)
	{
		if (line.find(searchFor) != std::string::npos)
		{
			std::printf("Found on line %d: %s\n", idx, line.c_str());
		}
	}

	return EXIT_SUCCESS;
}