#include <iostream>
#include <string>

const std::string NOT_NUM_MSG = "Input is not a number";
const std::string NOT_POS_NUM_MSG = "Input is not a pos number";
const std::string NOT_EIGHT_BIT_MSG = "Number from input is not eight-bit number";

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
        if ((num & (1 << bitIndex)) == 0)
        {
            flippedNum |= (1 << (7 - bitIndex));
        }
    }
    return flippedNum;
}

int main()
{
    std::string input;
    std::cin >> input;
    if (!IsDecimalNumber(input))
    {
        return 1;
    }
    int inputNum = std::stoi(input);
    if (!IsEightBitNum(inputNum))
    {
        return 1;
    }
    std::cout << FlippedDecNum(inputNum) << std::endl;
    return 0;
}
