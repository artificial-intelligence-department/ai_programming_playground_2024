// https://algotester.com/uk/ArchiveProblem/DisplayWithFile/40306

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool canMakeCandles(const std::vector<int> &candles, int N, double length)
{
	int count = 0;
	for (int candle : candles)
	{
		count += (int)(candle / length);
	}
	return count >= N;
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> candles(M);
	for (int i = 0; i < M; ++i)
	{
		std::cin >> candles[i];
	}

	double low = 0.0, high = *max_element(candles.begin(), candles.end());
	double mid;

	while (high - low > 1e-7)
	{
		mid = (low + high) / 2;
		if (canMakeCandles(candles, N, mid))
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	std::cout << std::fixed << std::setprecision(8) << low;
	return 0;
}
