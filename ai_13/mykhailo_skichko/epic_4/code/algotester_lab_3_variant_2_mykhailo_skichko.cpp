#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
	int N, M;
	std::cin >> N;

	std::vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> a[i];
	}

	std::cin >> M;

	std::vector<int> b(M);
	for (int i = 0; i < M; i++)
	{
		std::cin >> b[i];
	}

	std::set<int> setA(a.begin(), a.end());
	std::set<int> setB(b.begin(), b.end());

	std::vector<int> intersection;
	set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
					 back_inserter(intersection));

	std::set<int> unionSet(setA.begin(), setA.end());
	unionSet.insert(setB.begin(), setB.end());

	std::cout << intersection.size() << std::endl;
	std::cout << unionSet.size() << std::endl;

	return 0;
}
