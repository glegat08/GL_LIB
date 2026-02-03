#include "FileReader.h"

void Glib::FileReader::readFile(std::ifstream& file)
{
    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return;
    }

    std::string str;
    while (std::getline(file, str))
    {
        std::cout << str << '\n';
    }
}
