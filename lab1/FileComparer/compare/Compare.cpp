#include <string>
#include <fstream>
#include <iostream>
#include "Compare.h"

int FileCompare(const std::ifstream& firstFile, const std::ifstream& secondFile)
{
	if (!firstFile.is_open() || !secondFile.is_open()) 
	{
		std::cout << "Error: file is missing" << std::endl;
		return 0;
	}
}