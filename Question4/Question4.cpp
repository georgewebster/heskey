#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string shirt_numbers(std::vector<int> existing_shirts, const std::vector<int> potential_shirts)
{
	std::string result = "";
	int missing_shirt = -1;

	//sort the existing shirts
	std::sort(existing_shirts.begin(), existing_shirts.end());


	//is there a gap in the existing list of shirt numbers?
	for (size_t i = 0; i < existing_shirts.size() - 1; ++i)
	{
		if (existing_shirts[i] + 1 != existing_shirts[i + 1])
		{
			missing_shirt = existing_shirts[i] + 1;
			break;
			//Assuming here that there is no possibility of multiple shirts missing from the existing consecutive list
		}
	}

	for (size_t i = 0; i < potential_shirts.size(); ++i)
	{	
		char identifier = i + 1 + 64;
		result += "Shirt ";
		result += identifier;

		if (missing_shirt == -1)
		{	
			// add a valid shirt to start or end if the list is already consecutive 
			if ((potential_shirts[i] == existing_shirts[0] - 1 || potential_shirts[i] == existing_shirts[existing_shirts.size() - 1] + 1))
			{
				result += " is valid.\n";
			}
			else
			{
				result += " is invalid.\n";
			}
		}
		else
		{
			if (potential_shirts[i] == missing_shirt)
			{
				result += " is valid.\n";
			}
			else
			{
				result += " is invalid.\n";
			}
		}
	}
	return result;
}

int main()
{
	std::vector<int> exising_shirts = {3, 9, 4, 8, 7, 6, 5 };
	std::vector<int> potential_shirts = { 2, 8, 14, 10 };

	std::cout << shirt_numbers(exising_shirts, potential_shirts);
	std::cin.get();
}