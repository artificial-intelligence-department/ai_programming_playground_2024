#include <iostream> 
#include <string>
using namespace std;

int main()
{
	system("chcp 65001");  
	system("mode con cols=80 lines=25");  
	string weather;
	cout << "������ ������� ������� ����� (sunny, rainy, cloudy, snowy, windy): ";
	cin >> weather;

	if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy")
	{
		cout << "������ ����� ����� !" << endl;
		return 0;
	}

	if (weather == "snowy" || weather == "rainy")
	{
		cout << "�� �������� ����� ������!" << endl;
	}
	else
	{
		cout << "������ �� �������" << endl;
	}


	if (weather == "sunny")
	{
		cout << "������� ���� ��� ������! " << endl;
	}
	else if (weather == "rainy")
	{
		cout << "�������� ������, ��� ������ ����� ���������!" << endl;
	}
	else if (weather == "cloudy")
	{
		cout << "���� ������� �����?" << endl;
	}
	else if (weather == "snowy")
	{
		cout << "�� ���� ���� ��� ������ ���������" << endl;
	}
	else if (weather == "windy")
	{
		cout << "�������� ���������� ���, ���� �� � ��� �!" << endl;
	}






	switch (weather[0])
	{
	case 's' :
		if (weather == "sunny")
		{
			cout << "���� �������� �������!" << endl;
		}
		else if (weather == "snowy")
		{
			cout << "������ �������� ������ ���� ����!" << endl;
		}
		break;
	case 'r' : 
		cout << "����� ������� - ����� ����! " << endl;
		break;
	case 'c' :
		cout << "�������� �������� ����-��� ������" << endl;
		break;
	case 'w' :
		cout << " �������� ���� ������!" << endl;
		break;
	default :
		cout << "������� ������� �����!" << endl;
		break;
	}

	return 0;
}
