#include <iostream>
#include "../CarControl/CCar.h";
#include "../CarControl/CControl.h";

int main()
{
    Car car;
    Control carControl;
    carControl.CommandListener(car, std::cin, std::cout);
    return 0;
}
