#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool weight_training(std::vector<int> weights)
{
	constexpr int num_stacks = 4;
	constexpr int stack_limit = 10;

	constexpr int is_on_stack = -1;	//flag for a weight that has already been counted

	int completed_stacks = 0;
	int weights_to_be_stacked = weights.size();

	std::string result_str{};

	//sort the stack so we can always start with a large weight
	std::sort(weights.begin(), weights.end());

	while (weights_to_be_stacked != 0)
	{	
		//weight of the current stack
		int kilos_on_stack = 0;
		result_str += "Stack " + std::to_string(completed_stacks + 1) + " | ";

		for (int i = weights.size() - 1; i >= 0; --i)
		{	
			if (weights[i] != is_on_stack)
			{	
				//weights under the limit are added to the stack
				if (kilos_on_stack + weights[i] <= stack_limit) {

					kilos_on_stack += weights[i];
					result_str += std::to_string(weights[i]) + " ";
					--weights_to_be_stacked;
					weights[i] = is_on_stack;

				}

				// complete the stack if it's full or we're out of weights
				if (kilos_on_stack == stack_limit || i <= 0)
				{
					++completed_stacks;
					result_str += "|\n";
					break;
				}
			}
		}

		//exit the loop if all of our stacks are full
		if (completed_stacks == num_stacks)
		{
			break;
		}
	}


	if (completed_stacks <= num_stacks && weights_to_be_stacked == 0)
	{
		result_str += "All weights can be stacked into " + std::to_string(completed_stacks) + " stacks\n";
		std::cout << result_str;
		return true;
	}
	else
	{
		result_str += "There are " + std::to_string(weights_to_be_stacked) + " too many weights to fit into the " + std::to_string(num_stacks) + " stacks\nWeights | ";
		for (size_t i = 0; i < weights.size(); ++i)
		{
			if (weights[i] != is_on_stack)
			{
				result_str += std::to_string(weights[i]) + " ";
			}
		}
		result_str += "| Do not fit.\n";

		std::cout << result_str;
		return false;
	}
}

int main()
{
	std::vector<std::vector<int>> input = { {2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2}, {2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2} };

	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << std::boolalpha << weight_training(input[i]) << "\n\n";
	}
}
