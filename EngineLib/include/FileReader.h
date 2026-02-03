#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace Glib
{
	class FileReader
	{
	public:
		void readFile(std::ifstream& file);
	};
}