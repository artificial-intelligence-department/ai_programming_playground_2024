#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n), evens, odds;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
		{
			evens.push_back(a[i]);
		}
		else
		{
			odds.push_back(a[i]);
		}
	}

	if (abs((int)evens.size() - (int)odds.size()) > 1)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<int> result;
	bool evenTurn = evens.size() >= odds.size();
	while (!evens.empty() || !odds.empty())
	{
		if (evenTurn && !evens.empty())
		{
			result.push_back(evens.back());
			evens.pop_back();
		}
		else if (!evenTurn && !odds.empty())
		{
			result.push_back(odds.back());
			odds.pop_back();
		}
		evenTurn = !evenTurn;
	}

	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}