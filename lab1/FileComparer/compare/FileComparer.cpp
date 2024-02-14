/*Разработайте программу compare.exe, выполняющую сравнение содержимого текстовых файлов. Формат командной строки:
compare.exe <file1> <file2>
В том случае, если файлы имеют одинаковое содержимое, программа должна вернуть нулевой результат в операционную систему и вывести строку «Files are equal» в стандартный поток вывода. 
В противном случае программа должна вывести номер первой строки, в которой были найдены расхождения в содержимом файлов: «Files are different. Line number is <номер строки>», и вернуть значение 1.
Программа должна корректно обрабатывать ошибки, связанные с файловыми операциями.
В комплекте с программой должны обязательно поставляться файлы, позволяющие проверить корректность её работы в автоматическом режиме.
*/

#include <iostream>
#include <fstream>
#include <optional>
#include "Compare.h"

const std::string ErrorCountArgsMsg = "Invalid arguments count";
const std::string RightUsageMsg = "Usage: compare.exe <file1> < file2>";

struct Args
{
    std::string firstInputFileName;
    std::string secondInputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << ErrorCountArgsMsg << std::endl;
        std::cout << RightUsageMsg << std::endl;
        return std::nullopt;
    }
    Args args;
    args.firstInputFileName = argv[1];
    args.secondInputFileName = argv[2];
    return args;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args) 
    {
        return 1;
    }
    else 
    {
        std::ifstream firstFile;
        firstFile.open(args->firstInputFileName);
        std::ifstream secondFile;
        secondFile.open(args->secondInputFileName);
        std::cout << FileCompare(firstFile, secondFile);
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
