#include <iostream>

unsigned long long int double_goals_every_match(const int matches)
{   
    unsigned long long int result = 1;

    for (size_t i = 1; i < matches; ++i)
    {
        result *= 2;
    }

    return result;
}

int main()
{
    std::cout << double_goals_every_match(50) << " goals";
}
