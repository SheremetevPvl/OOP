#include <iostream>
#include <string>
#include <optional>

const std::string NOT_NUM_MSG = "Input is not a number";
const std::string NOT_POS_NUM_MSG = "Input is not a natural number";
const std::string NOT_EIGHT_BIT_MSG = "Number from input is not eight-bit number";
const std::string ERROR_COUNT_ARGS_MSG = "Invalid arguments count";
const std::string RIGHT_USAGE_MSG = "Usage: flipbyte.exe <0-255>";

struct Args
{
    std::string numToFlip;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << ERROR_COUNT_ARGS_MSG << std::endl;
        std::cout << RIGHT_USAGE_MSG << std::endl;
        return std::nullopt;
    }
    Args args;
    args.numToFlip = argv[1];
    return args;
}

bool IsDecimalNumber(std::string inputStr)
{
    if (inputStr[0] == '-' || isdigit(inputStr[0]))
    {
        for (char ch : inputStr)
        {
            if (!isdigit(ch))
            {
                std::cout << NOT_POS_NUM_MSG << std::endl;
                return false;
            }
        }
        return true;
    }
    else
    {
        std::cout << NOT_NUM_MSG << std::endl;
        return false;
    }
}

bool IsEightBitNum(int num)
{
    if (num > 0 && num < 255)
    {
        return true;
    }
    else
    {
        std::cout << NOT_EIGHT_BIT_MSG << std::endl;
        return false;
    } 
}

int FlippedDecNum(int num)
{
    int flippedNum = 0;
    for (int bitIndex = 0; bitIndex < 8; bitIndex++)
    {
        flippedNum |= ((num >> bitIndex) & 1) << (7 - bitIndex);  //сдвигаем исходный байт вправо на i позиций, затем извлекаем младший бит и устанавливаем его в отзеркаленном байте на позицию 7 - i.
    }
    return flippedNum;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }
    if (!IsDecimalNumber(args->numToFlip))
    {
        return 1;
    }
    int inputNum = std::stoi(args->numToFlip);
    if (!IsEightBitNum(inputNum))
    {
        return 1;
    }
    std::cout << FlippedDecNum(inputNum) << std::endl;
    return 0;
}
