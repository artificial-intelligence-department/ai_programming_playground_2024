#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void print(const std::vector<short> &result)
{
	std::cout << result.size() << std::endl;
	for (short num : result)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl << std::endl;
};

int main()
{
	short N, M;

	std::cin >> N;
	std::vector<short> arrayN(N);
	for (short i = 0; i < N; ++i)
	{
		std::cin >> arrayN[i];
	}
	std::cin >> M;
	std::vector<short> arrayM(M);
	for (short i = 0; i < M; ++i)
	{
		std::cin >> arrayM[i];
	}

	sort(arrayN.begin(), arrayN.end());
	sort(arrayM.begin(), arrayM.end());

	std::vector<short> difference_N_M;
	set_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(difference_N_M));
	print(difference_N_M);

	std::vector<short> difference_M_N;
	set_difference(arrayM.begin(), arrayM.end(), arrayN.begin(), arrayN.end(), std::back_inserter(difference_M_N));
	print(difference_M_N);

	std::vector<short> intersection_N_M;
	set_intersection(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(intersection_N_M));
	print(intersection_N_M);

	std::vector<short> unionSet_N_M;
	set_union(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(unionSet_N_M));
	print(unionSet_N_M);

	std::vector<short> symmetricDifference_N_M;
	set_symmetric_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(symmetricDifference_N_M));
	print(symmetricDifference_N_M);

	return 0;
}
