// https://algotester.com/uk/ArchiveProblem/DisplayWithFile/40476

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::string result = "";
	char more, less;
	int moreCount, lessCount;

	if (a > b)
	{
		more = 'Y';
		less = 'G';
		moreCount = a;
		lessCount = b;
	}
	else
	{
		more = 'G';
		less = 'Y';
		moreCount = b;
		lessCount = a;
	}

	while (moreCount > 0 && lessCount > 0)
	{
		result += more;
		result += less;
		moreCount--;
		lessCount--;
	}

	result += std::string(moreCount, more);
	result += std::string(lessCount, less);

	std::cout << result;

	return 0;
}
