#include <iostream>
#include <vector>
#include <string>

std::string pattern_match(const std::vector<std::vector<std::string>> input)
{   
    std::string result{};
    
    for (size_t i = 0; i < input.size(); ++i)
    {
        char identifier = i + 1 + 64;
        result += identifier;

        //Compare the 1st to the 4th element and the 2nd to the third of both strings 
        if ((input[i][0][0] == input[i][0][3]) == (input[i][1][0] == input[i][1][3]) && 
            (input[i][0][1] == input[i][0][2]) == (input[i][1][1] == input[i][1][2]))
        {
            result += ": true\n";
        }
        else
        {
            result += ": false\n";
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<std::string>> input = { {"ABCA", "LMBR"}, {"LDDA", "IMMR"}, {"LDDR", "IMMR"} };

    std::cout << pattern_match(input);
}