#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		int x = 0;
		while(i - x >= 0 && i + x < (int)s.size() && s[i - x] == s[i + x])
			x++;
		ans = max(ans, 2 * x - 1);
	}
	for(int i = 0; i < n; i++)
	{
		int x = 0;
		while(i - x >= 0 && i + 1 + x < (int)s.size() && s[i - x] == s[i + 1 + x])
			x++;
		ans = max(ans, 2 * x);
	}
	cout << ans << "\n";
	return 0;
}

