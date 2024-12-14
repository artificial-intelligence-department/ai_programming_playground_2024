#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size_arr;
	cin >> size_arr;

	vector<int> arr(size_arr);
	for (int i = 0; i < size_arr; i++)
	{
		cin >> arr[i];
	}

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> filtered_arr;
	for (int i = 0; i < size_arr; i++)
	{
		if (arr[i] != a && arr[i] != b && arr[i] != c)
		{
			filtered_arr.push_back(arr[i]);
		}
	}

	vector<int> new_arr;
	for (size_t i = 0; i + 1 < filtered_arr.size(); i++)
	{
		new_arr.push_back(filtered_arr[i] + filtered_arr[i + 1]);
	}

	cout << new_arr.size() << endl;
	for (int val : new_arr)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}