#include <iostream>
#include <vector>
#include <string>

std::string bridge_to_cross(const std::vector<std::string> bridges)
{
    std::string result;

    for (size_t i = 0; i < bridges.size(); ++i)
    {
        char identifier = (i + 1) + 64;
        result += "Bridge ";
        result += identifier;

        if (bridges[i].find_first_of(" ") == std::string::npos)
        {
            result += " is safe to cross.\n";
        }
        else
        {
            result += " is not safe to cross.\n";
        }
    }

    return result;
}

int main()
{
    std::cout << bridge_to_cross({"######","### ##","###","# ###"});
}