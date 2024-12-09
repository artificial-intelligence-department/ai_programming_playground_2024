#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Stadium
{
	char name[50];
	int year;
	int numFields;
	char sports[100];
};

void createFile(const std::string &filename, const std::vector<Stadium> &stadiums)
{
	std::ofstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Помилка відкриття файлу для запису!" << std::endl;
		return;
	}
	for (const auto &stadium : stadiums)
	{
		file.write(reinterpret_cast<const char *>(&stadium), sizeof(Stadium));
	}
	file.close();
}

void printFile(const std::string &filename)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Помилка відкриття файлу для читання!" << std::endl;
		return;
	}
	Stadium stadium;
	while (file.read(reinterpret_cast<char *>(&stadium), sizeof(Stadium)))
	{
		std::cout << "Назва: " << stadium.name
				  << ", Рік: " << stadium.year
				  << ", Кількість майданчиків: " << stadium.numFields
				  << ", Види спорту: " << stadium.sports << std::endl;
	}
	file.close();
}

void addRecord(const std::string &filename, const Stadium &stadium, int position)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Помилка відкриття файлу для читання!" << std::endl;
		return;
	}

	std::vector<Stadium> stadiums;
	Stadium temp;
	while (file.read(reinterpret_cast<char *>(&temp), sizeof(Stadium)))
	{
		stadiums.push_back(temp);
	}
	file.close();

	if (position >= 0 && position <= stadiums.size())
	{
		stadiums.insert(stadiums.begin() + position, stadium);
	}
	else
	{
		std::cerr << "Некоректна позиція!" << std::endl;
		return;
	}

	createFile(filename, stadiums);
}

void deleteRecordByName(const std::string &filename, const std::string &nameToDelete)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Помилка відкриття файлу для читання!" << std::endl;
		return;
	}

	std::vector<Stadium> stadiums;
	Stadium temp;
	bool found = false;

	while (file.read(reinterpret_cast<char *>(&temp), sizeof(Stadium)))
	{
		if (nameToDelete != temp.name)
		{
			stadiums.push_back(temp);
		}
		else
		{
			found = true;
		}
	}
	file.close();

	if (!found)
	{
		std::cerr << "Запис з назвою \"" << nameToDelete << "\" не знайдено!" << std::endl;
	}
	else
	{
		createFile(filename, stadiums);
		std::cout << "Запис з назвою \"" << nameToDelete << "\" успішно видалено." << std::endl;
	}
}

void searchRecordByName(const std::string &filename, const std::string &nameToSearch)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Помилка відкриття файлу для читання!" << std::endl;
		return;
	}

	Stadium stadium;
	bool found = false;

	while (file.read(reinterpret_cast<char *>(&stadium), sizeof(Stadium)))
	{
		if (nameToSearch == stadium.name)
		{
			std::cout << "Знайдено запис: "
					  << "Назва: " << stadium.name
					  << ", Рік: " << stadium.year
					  << ", Кількість майданчиків: " << stadium.numFields
					  << ", Види спорту: " << stadium.sports << std::endl;
			found = true;
		}
	}
	file.close();

	if (!found)
	{
		std::cout << "Запис з назвою \"" << nameToSearch << "\" не знайдено!" << std::endl;
	}
}

int main()
{
	std::string filename = "stadiums.bin";

	std::vector<Stadium> stadiums = {
		{"Олімпійський", 1990, 5, "Футбол, Баскетбол"},
		{"Арена Львів", 2010, 3, "Футбол"},
		{"Дніпро-Арена", 2005, 4, "Футбол, Волейбол"}};

	createFile(filename, stadiums);

	std::cout << "Вміст файлу після створення:\n";
	printFile(filename);

	std::cout << "\nПошук запису за назвою \"Арена Львів\":\n";
	searchRecordByName(filename, "Арена Львів");

	std::cout << "\nВидалення запису з назвою \"Олімпійський\":\n";
	deleteRecordByName(filename, "Олімпійський");

	std::cout << "\nВміст файлу після видалення запису:\n";
	printFile(filename);

	return 0;
}
