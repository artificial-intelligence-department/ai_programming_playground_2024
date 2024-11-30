// https://algotester.com/uk/ArchiveProblem/DisplayWithFile/40637

#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> odd, even;

	for (int i = 0; i < n; ++i)
	{
		int a;
		std::cin >> a;
		if (a % 2 == 0)
		{
			even.push_back(a);
		}
		else
		{
			odd.push_back(a);
		}
	}

	if (abs((int)odd.size() - (int)even.size()) > 1)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		if (odd.size() > even.size())
		{
			for (int i = 0; i < odd.size(); ++i)
			{
				std::cout << odd[i] << " ";
				if (i < even.size())
				{
					std::cout << even[i] << " ";
				}
			}
		}
		else
		{
			for (int i = 0; i < even.size(); ++i)
			{
				std::cout << even[i] << " ";
				if (i < odd.size())
				{
					std::cout << odd[i] << " ";
				}
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
