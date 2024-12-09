#include <iostream>
#include <vector>
#include <string>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> cave(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> cave[i];
	}

	std::vector<std::string> result(N, std::string(M, 'O'));

	for (int col = 0; col < M; ++col)
	{
		int sandPosition = N - 1;

		for (int row = N - 1; row >= 0; --row)
		{
			if (cave[row][col] == 'X')
			{
				result[row][col] = 'X';
				sandPosition = row - 1;
			}
			else if (cave[row][col] == 'S')
			{
				result[sandPosition][col] = 'S';
				--sandPosition;
			}
		}
	}

	for (const std::string &row : result)
	{
		std::cout << row << std::endl;
	}

	return 0;
}
