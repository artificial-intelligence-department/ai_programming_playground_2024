#include <iostream>
#include <vector>
#include <numeric>

std::vector<std::vector<int>> create2DArray(const std::vector<int> &arr)
{
	int N = arr.size();
	std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 1));

	for (int j = 0; j < N; ++j)
	{
		int targetSum = arr[j];
		int currentSum = N;
		for (int i = 0; i < N; ++i)
		{
			matrix[i][j] = 1;
		}

		matrix[N - 1][j] += (targetSum - currentSum);
	}
	return matrix;
}

int main()
{
	std::vector<int> arr = {6, 10, 15};

	std::vector<std::vector<int>> matrix = create2DArray(arr);

	std::cout << "Resulting 2D array:\n";
	for (const auto &row : matrix)
	{
		for (int val : row)
		{
			std::cout << val << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
