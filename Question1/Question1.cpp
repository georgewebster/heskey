#include <iostream>
#include <string>

std::string seconds_conversion(const int seconds)
{
    int minutes = seconds / 60;
    int hours = minutes / 60;
    
    minutes -= hours * 60;;

    return std::to_string(hours) + ":" + std::to_string(minutes);
}


int main()
{
    std::cout << seconds_conversion(5400) << std::endl;
}
