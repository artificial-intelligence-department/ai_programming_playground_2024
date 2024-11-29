#include <iostream>

using namespace std;

int main()
{
	int n;
    cin >> n;
	string s;
	cin >> s;
	int x = count(s.begin(), s.end(), '0');
	if (x * 2 > n){
		while(x--) cout << 0;
	}else{
		x = n - x;
		while(x--) cout << 1;
	}
	
    return 0;
}


