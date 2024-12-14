#include <iostream>
#include <vector>
#include <algorithm>

void printCircularArray(const std::vector<int> &arr, int startIndex, bool left)
{
	int n = arr.size();
	int index = startIndex;
	std::cout << "Circular Array: ";
	if (left)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << arr[index] << " ";
			index = (index - 1 + n) % n; // move left
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << arr[index] << " ";
			index = (index + 1) % n; // move right
		}
	}
	std::cout << std::endl;
}

std::vector<int> deleteMaxElements(std::vector<int> &arr)
{
	int maxVal = *std::max_element(arr.begin(), arr.end());
	std::vector<int> result;
	for (int num : arr)
	{
		if (num != maxVal)
		{
			result.push_back(num);
		}
	}
	return result;
}

int main()
{
	std::vector<int> circularArray = {5, 3, 8, 6, 8, 2};
	int k = 2;

	std::cout << "Original Circular Array: ";
	printCircularArray(circularArray, 0, false);

	std::cout << "Task 2: Starting from Kth element to the left" << std::endl;
	printCircularArray(circularArray, k, true);

	std::cout << "Task 3: Removing elements matching the maximum value" << std::endl;
	circularArray = deleteMaxElements(circularArray);

	std::cout << "Task 4: Starting from Kth element to the right" << std::endl;
	printCircularArray(circularArray, k % circularArray.size(), false);

	return 0;
}
