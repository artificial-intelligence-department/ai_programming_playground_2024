#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	std::vector<int> newArr;
	for (int i = 1; i <= n; i++) arr[i - 1] = i;
	int k = (arr.size()) / 2;		//Всі елементи, які йдуть до рівно половини масиву будуть їхніми дільниами, тобто вони не потрібні
	for (int i = k ; i < arr.size(); i++) { 
		newArr.push_back(arr[i]);	
	}
	

	std::cout << newArr.size() << std::endl;
	for (auto& val : newArr) std::cout << val << " ";
	return 0;
}