#include <string>
#include <fstream>
#include <iostream>
#include "Compare.h"

const std::string DIFF_FILES_MSG = "Files are different. Line number is ";
const std::string EQUAL_FILES_MSG = "Files are equal";

int FileCompare(std::ifstream& firstFile, std::ifstream& secondFile)
{
	if (!firstFile.is_open() || !secondFile.is_open()) 
	{
		std::cout << "Error: file is missing" << std::endl;
		return 0;
	}
	std::string strFromFirFile;
	std::string strFromSecFile;
	int diffLineNum(0);
	while (!firstFile.eof() && !secondFile.eof())
	{
		getline(firstFile, strFromFirFile);
		getline(secondFile, strFromSecFile);
		diffLineNum++;
		if (strFromFirFile != strFromSecFile)                  //при обнаружении первой не похожей строки выходим из функции
		{
			std::cout << DIFF_FILES_MSG << diffLineNum << std::endl;
			return 1;
			break;
		}
	}
	if (!firstFile.eof() || !secondFile.eof())                //прверка на ситуацию, когда первый файл имеет строк больше чем второй или наоборот
	{
		std::cout << DIFF_FILES_MSG << diffLineNum << std::endl;
		return 1;
	}
	else
	{
		std::cout << EQUAL_FILES_MSG << std::endl;
		return 0;
	}
}