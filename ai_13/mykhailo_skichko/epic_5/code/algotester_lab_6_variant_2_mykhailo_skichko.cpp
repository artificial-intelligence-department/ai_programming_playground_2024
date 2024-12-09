#include <iostream>
#include <vector>
#include <set>
#include <cmath>

struct Figure
{
	char name;
	int x, y;
};

bool canAttack(Figure &f, int x, int y)
{
	switch (f.name)
	{
	case 'P':
		return f.x == x - 1 && abs(f.y - y) == 1;
	case 'R':
		return f.x == x || f.y == y;
	case 'N':
		return (abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2);
	case 'B':
		return abs(f.x - x) == abs(f.y - y);
	case 'K':
		return abs(f.x - x) <= 1 && abs(f.y - y) <= 1;
	case 'Q':
		return f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y);
	default:
		return false;
	}
}

int main()
{
	std::vector<Figure> figures;
	for (int i = 1; i <= 8; ++i)
	{
		std::string row;
		std::cin >> row;
		for (int j = 0; j < row.size(); ++j)
		{
			if (row[j] != 'O')
			{
				figures.push_back({row[j], i, j + 1});
			}
		}
	}

	int n;
	std::cin >> n;
	std::vector<std::string> answers;

	while (n--)
	{
		int x, y;
		std::cin >> x >> y;

		std::set<char> attackers;
		bool isOccupied = false;

		for (auto &figure : figures)
		{
			if (figure.x == x && figure.y == y)
			{
				isOccupied = true;
				break;
			}
			if (canAttack(figure, x, y))
			{
				attackers.insert(figure.name);
			}
		}

		if (isOccupied)
		{
			answers.push_back("X");
		}
		else if (attackers.empty())
		{
			answers.push_back("O");
		}
		else
		{
			std::string result;
			for (char attacker : attackers)
			{
				result += attacker;
			}
			answers.push_back(result);
		}
	}

	for (const auto &answer : answers)
	{
		std::cout << answer << std::endl;
	}

	return 0;
}
