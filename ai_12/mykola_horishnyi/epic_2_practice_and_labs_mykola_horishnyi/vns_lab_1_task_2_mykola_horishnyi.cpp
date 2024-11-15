#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	cout << "enter n : ";
	cin >> n;
	cout << "enter m : ";
	cin >> m;
	cout << n-- - m << endl;

	if (m-- < n)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


	if (n++ > m)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}



	return 0;

}
