#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>

static void handleExit()
{
    std::cout << "Press any key to exit";

#ifdef _MSC_VER
    ((void)_getch());
#else
    ((void)getch());
#endif
}

int main(int argc, char** argv)
{
    std::atexit(handleExit);

    std::string fileName = "";
    if (argc == 2) {
        fileName = argv[1];
    } else {
        std::cout << "Enter file to search: ";
        std::getline(std::cin, fileName);
    }

    std::cout << "Enter text to look for: ";
    std::string searchFor = "";
    std::getline(std::cin, searchFor);

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line = "";
    bool found       = false;
    for (std::size_t idx = 1; std::getline(file, line); idx++) {
        if (line.find(searchFor) != std::string::npos) {
            found = true;
            std::cout << "Found on line " << idx << " : " << line << std::endl;
        }
    }

    if (!found) {
        std::cout << "Unable to find wanted text" << std::endl;
    }

    return EXIT_SUCCESS;
}