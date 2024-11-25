#include <iostream>
using namespace std;

char ans[7][7];

int main()
{
	int n, m;
	cin >> n >> m;
	bool t = false;
	if(m & 1)
	{
		swap(n, m);
		t = true;
	}
	if(m & 1)
	{
		cout << "-1\n";
		return 0;
	}
	char c = 'A';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j += 2)
			ans[i][j] = ans[i][j + 1] = c++;
	if(t)
		swap(n, m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		cout << (t ? ans[j][i] : ans[i][j]);
		cout << "\n";
	}
	return 0;
}

