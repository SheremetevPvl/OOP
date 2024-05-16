#include "../CarControl/CControl.h";
#include "../CarControl/CCar.h";

std::string const GET_INFO = "Info";
std::string const TURN_ON_ENGINE = "TurnOn";
std::string const TURN_OFF_ENGINE = "TurnOff";
std::string const SET_GEAR = "SetGear";
std::string const SET_SPEED = "SetSpeed";

std::string GenerateCommandList()
{
    std::string list;
    std::vector<std::string> commands = { GET_INFO, TURN_ON_ENGINE, TURN_OFF_ENGINE, SET_GEAR + " <int>", SET_SPEED + " <int>" };
    for (const std::string& command : commands)
    {
        std::copy(command.begin(), command.end(), std::back_inserter(list));
        list.push_back('\n');
    }
    return list;
}

std::string GetInfo(Car& car)
{
    std::string output;
    output = "Gear: " + std::to_string(static_cast<int>(car.GetGear())) + "\n";
    output = output + "Speed: " + std::to_string(car.GetSpeed()) + "\n";
    if (car.IsTurnedOn())
    {
        output = output + "on\n";
    }
    else
    {
        output = output + "off\n";
    }
    switch (car.GetDirection())
    {
    case MoveDirection::forward:
        output = output + "forward\n";
        break;
    case MoveDirection::standing_still:
        output = output + "standing still\n";
        break;
    case MoveDirection::backward:
        output = output + "backward\n";
        break;
    }
    return output;
}

std::string CommandResult(Car& car,const std::string& command)
{
    std::string output;
    std::istringstream input(command);
    std::string oper;
    input >> oper;
    if (oper == GET_INFO)
    {
        output = GetInfo(car);
        return output;
    }
    if (oper == TURN_ON_ENGINE)
    {
        if (car.TurnOnEngine())
        {
            output = "Engine is on\n";
        }
        else
        {
            output = "Unnable to turn on engine";
        }
        return output;
    }
    if (oper == TURN_OFF_ENGINE)
    {
        if (car.TurnOffEngine())
        {
            output = "Engine if off\n";
        }
        else
        {
            output = "Unnable to turn off engine\n";
        }
        return output;
    }
    if (oper == SET_GEAR)
    {
        int gear;
        if (input >> gear)
        {
            if (car.SetGear(static_cast<Gear>(gear)))
            {
                output = "New gear is set\n";
            }
            else
            {
                output = "Unnable to set new gear\n";
            }
        }
        else
        {
            output = "No gear in input\n";
        }
        return output;
    }
    if (oper == SET_SPEED)
    {
        unsigned int speed;
        if (input >> speed)
        {
            if (car.SetSpeed(speed))
            {
                output = "New speed is set\n";
            }
            else
            {
                output = "Unnable to set new speed\n";
            }
        }
        else
        {
            output = "No speed in input\n";
        }
        return output;
    }
    output = "Wrong command\n";
    return output;
}

void Control::CommandListener(Car& car, std::istream& input, std::ostream& output)
{
    std::string command;
    std::string commandList = GenerateCommandList();
    output << commandList;
    while (!input.eof() && !input.fail()) 
    {
        std::cout << "Enter command: ";
        std::getline(input, command);
        if (command == "exit") 
        {
            break;
        }
        else 
        {
            output << CommandResult(car, command);
        }
    }
}