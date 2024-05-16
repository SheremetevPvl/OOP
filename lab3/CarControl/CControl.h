#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "CCar.h"
class Car;

class Control
{
public:
	    void CommandListener(Car& car, std::istream& input, std::ostream& output);
private:
};