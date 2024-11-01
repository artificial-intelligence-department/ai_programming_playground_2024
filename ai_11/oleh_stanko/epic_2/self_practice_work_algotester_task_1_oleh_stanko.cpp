#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int S = n * m;
	if (S % 2 == 0)
	{
		cout << "Dragon";
	}
	else
	{
		cout << "Imp";
	}
	return 0;
}
