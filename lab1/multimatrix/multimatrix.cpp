#include <iostream>
#include <optional>
#include <fstream>

const std::string ERROR_COUNT_ARGS_MSG = "Invalid arguments count\n";
const std::string RIGHT_USAGE_MSG = "Usage: flipbyte.exe <matrixfile1> <matrixfile2>\n";
const std::string FILE_ERROR_MSG = "Fail to open one file or both\n";
const int ROWS_NUM = 3;
const int COL_NUM = 3;

struct Args
{
    std::string firstFileName;
    std::string secondFileName;
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
    args.firstFileName = argv[1];
    args.secondFileName = argv[2];
    return args;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }
    std::ifstream firstMatrixFile, secondMatrixFile;
    firstMatrixFile.open(args->firstFileName);
    secondMatrixFile.open(args->secondFileName);
    if (firstMatrixFile.is_open() && secondMatrixFile.is_open())
    {
        int MatrixTable[ROWS_NUM][COL_NUM];

    }
    else
    {
        std::cout << FILE_ERROR_MSG;
        return 0;
    }
}