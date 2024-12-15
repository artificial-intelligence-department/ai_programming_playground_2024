#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> shiftArrayLeft(const std::vector<int> &arr, int shifts)
{
	int n = arr.size();
	shifts %= n;
	std::vector<int> result(arr.begin() + shifts, arr.end());
	result.insert(result.end(), arr.begin(), arr.begin() + shifts);
	return result;
}

std::vector<int> shiftArrayRight(const std::vector<int> &arr, int shifts)
{
	int n = arr.size();
	shifts %= n;
	std::vector<int> result(arr.end() - shifts, arr.end());
	result.insert(result.end(), arr.begin(), arr.end() - shifts);
	return result;
}

std::vector<int> processArray(const std::vector<int> &arr)
{
	if (arr.empty())
	{
		return {};
	}

	if (arr[0] % 2 == 0)
	{
		// if the first element is even, perform cyclic shift left by the first element's value
		return shiftArrayLeft(arr, arr[0]);
	}
	else
	{
		// if the first element is odd, perform cyclic shift right by the last element's value
		return shiftArrayRight(arr, arr.back());
	}
}

int main()
{
	std::vector<int> array1 = {4, 1, 2, 3, 5};
	std::vector<int> array2 = {3, 1, 4, 1, 5, 9};

	std::vector<int> result1 = processArray(array1);
	std::vector<int> result2 = processArray(array2);

	std::cout << "Original array 1: ";
	for (int num : array1)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Processed array 1: ";
	for (int num : result1)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Original array 2: ";
	for (int num : array2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Processed array 2: ";
	for (int num : result2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
