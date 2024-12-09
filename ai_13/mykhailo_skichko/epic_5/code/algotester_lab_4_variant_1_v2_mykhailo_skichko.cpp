#include <iostream>
#include <string>
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
	std::cout << std::endl
			  << std::endl;
};

std::vector<short> makeSet(const std::vector<short> &array)
{
	if (array.empty())
	{
		return {};
	}

	std::vector<short> sortedArray = array;
	sort(sortedArray.begin(), sortedArray.end());

	std::vector<short> resultantSet;
	for (int i = 0; i < sortedArray.size(); ++i)
	{
		bool found = false;

		int low = 0;
		int high = resultantSet.size();
		while (low < high)
		{
			int mid = low + (high - low) / 2;
			if (resultantSet[mid] == sortedArray[i])
			{
				found = true;
				break;
			}
			else if (resultantSet[mid] < sortedArray[i])
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}

		if (!found)
		{
			resultantSet.push_back(sortedArray[i]);
		}
	}

	return resultantSet;
}

std::vector<short> getUniversalSet(const std::vector<short> &set1, const std::vector<short> &set2)
{
	std::vector<short> unionSet = set1;
	unionSet.insert(unionSet.end(), set2.begin(), set2.end());

	std::sort(unionSet.begin(), unionSet.end());

	std::vector<short> result;
	if (!unionSet.empty())
	{
		result.push_back(unionSet[0]);

		for (int i = 1; i < unionSet.size(); ++i)
		{
			if (unionSet[i] != unionSet[i - 1])
			{
				result.push_back(unionSet[i]);
			}
		}
	}

	return result;
}

std::vector<bool> transformToSetCharacteristicVector(const std::vector<short> &universalSet, const std::vector<short> &subset)
{
	std::vector<bool> characteristicVector(universalSet.size(), false);
	for (int i = 0; i < universalSet.size(); ++i)
	{
		if (find(subset.begin(), subset.end(), universalSet[i]) != subset.end())
		{
			characteristicVector[i] = true;
		}
	}
	return characteristicVector;
}

std::vector<short> transformToNumberSet(const std::vector<short> &universalSet, const std::vector<bool> &characteristicVector)
{
	std::vector<short> result;
	for (int i = 0; i < characteristicVector.size(); ++i)
	{
		if (characteristicVector[i])
		{
			result.push_back(universalSet[i]);
		}
	}
	return result;
}

std::vector<bool> setDifferenceCharacteristicVector(const std::vector<bool> &vec1, const std::vector<bool> &vec2)
{
	std::vector<bool> result(vec1.size(), false);
	for (int i = 0; i < vec1.size(); ++i)
	{
		result[i] = (vec1[i] != vec2[i]) && vec1[i];
	}
	return result;
}

std::vector<short> setDifference(const std::vector<short> &universalSet,
								 const std::vector<bool> &characteristicVector1,
								 const std::vector<bool> &characteristicVector2)
{
	std::vector<bool> resultCharacteristicVector = setDifferenceCharacteristicVector(characteristicVector1, characteristicVector2);
	std::vector<short> result = transformToNumberSet(universalSet, resultCharacteristicVector);
	return result;
}

std::vector<bool> setIntersectionCharacteristicVector(const std::vector<bool> &vec1, const std::vector<bool> &vec2)
{
	std::vector<bool> result(vec1.size(), false);
	for (int i = 0; i < vec1.size(); ++i)
	{
		result[i] = vec1[i] && vec2[i];
	}
	return result;
}

std::vector<short> setIntersection(const std::vector<short> &universalSet,
								   const std::vector<bool> &characteristicVector1,
								   const std::vector<bool> &characteristicVector2)
{
	std::vector<bool> resultCharacteristicVector = setIntersectionCharacteristicVector(characteristicVector1, characteristicVector2);
	std::vector<short> result = transformToNumberSet(universalSet, resultCharacteristicVector);
	return result;
}

std::vector<bool> setUnionCharacteristicVector(const std::vector<bool> &vec1, const std::vector<bool> &vec2)
{
	std::vector<bool> result(vec1.size(), false);
	for (int i = 0; i < vec1.size(); ++i)
	{
		result[i] = vec1[i] || vec2[i];
	}
	return result;
}

std::vector<short> setUnion(const std::vector<short> &universalSet,
							const std::vector<bool> &characteristicVector1,
							const std::vector<bool> &characteristicVector2)
{
	std::vector<bool> resultCharacteristicVector = setUnionCharacteristicVector(characteristicVector1, characteristicVector2);
	std::vector<short> result = transformToNumberSet(universalSet, resultCharacteristicVector);
	return result;
}

std::vector<bool> setSymmetricDifferenceCharacteristicVector(const std::vector<bool> &vec1, const std::vector<bool> &vec2)
{
	std::vector<bool> result(vec1.size(), false);
	for (int i = 0; i < vec1.size(); ++i)
	{
		result[i] = vec1[i] != vec2[i];
	}
	return result;
}

std::vector<short> setSymmetricDifference(const std::vector<short> &universalSet,
										  const std::vector<bool> &characteristicVector1,
										  const std::vector<bool> &characteristicVector2)
{
	std::vector<bool> resultCharacteristicVector = setSymmetricDifferenceCharacteristicVector(characteristicVector1, characteristicVector2);
	std::vector<short> result = transformToNumberSet(universalSet, resultCharacteristicVector);
	return result;
}

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

	std::vector<short> setN = makeSet(arrayN);
	std::vector<short> setM = makeSet(arrayM);

	std::vector<short> universalSet = getUniversalSet(setN, setM);

	std::vector<bool> charVecN = transformToSetCharacteristicVector(universalSet, setN);
	std::vector<bool> charVecM = transformToSetCharacteristicVector(universalSet, setM);

	std::vector<short> difference_N_M = setDifference(universalSet, charVecN, charVecM);
	print(difference_N_M);

	std::vector<short> difference_M_N = setDifference(universalSet, charVecM, charVecN);
	print(difference_M_N);

	std::vector<short> intersection_N_M = setIntersection(universalSet, charVecN, charVecM);
	print(intersection_N_M);

	std::vector<short> unionSet_N_M = setUnion(universalSet, charVecN, charVecM);
	print(unionSet_N_M);

	std::vector<short> symmetricDifference_N_M = setSymmetricDifference(universalSet, charVecN, charVecM);
	print(symmetricDifference_N_M);

	return 0;
}
