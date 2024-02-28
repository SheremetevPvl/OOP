#include <iostream>
#include <optional>
#include <fstream>
#include <string>

const std::string ERROR_COUNT_ARGS_MSG = "Invalid arguments count\n";
const std::string RIGHT_USAGE_MSG = "Usage: findtext.exe <filename> <text to search>\n";
const std::string FILE_ERROR_MSG = "Fail to open file\n";
const std::string TEXT_NOT_FOUND_MSG = "Text not found\n";

struct Args
{
    std::string inputFileName;
    std::string textToSearch;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << ERROR_COUNT_ARGS_MSG << std::endl;
        std::cout << RIGHT_USAGE_MSG << std::endl;
        return std::nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.textToSearch = argv[2];
    return args;
}

int FindAllSameStrings(const std::string stringToFind, std::ifstream& file)
{
    std::string lineFromFile;
    int lineNumber = 0;
    bool found = false;
    while (std::getline(file, lineFromFile)) 
    {
        lineNumber++;
        if (lineFromFile.find(stringToFind) != std::string::npos) 
        {
            std::cout << lineNumber << "\n";
            found = true;
        }
    }
    if (!found) 
    {
        std::cout << TEXT_NOT_FOUND_MSG;
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 0;
    }
    std::ifstream inputFile;
    inputFile.open(args->inputFileName);
    if (inputFile.is_open())
    {
        FindAllSameStrings(args->textToSearch, inputFile);
    }
    else
    {
        std::cout << FILE_ERROR_MSG;
        return 0;
    }
    inputFile.close();
    return 0;
}
