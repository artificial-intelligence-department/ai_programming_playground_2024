#include <iostream> 
#include <string>
using namespace std;

int main()
{
	system("chcp 65001");  
	system("mode con cols=80 lines=25");  
	string weather;
	cout << "What is the weather like today? (sunny, rainy, cloudy, snowy, windy): ";
	cin >> weather;

	if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy")
	{
		cout << "Enter right weather  !" << endl;
		return 0;
	}

	if (weather == "snowy" || weather == "rainy")
	{
		cout << "Please, wear a jacket!" << endl;
	}
	else
	{
		cout << "You don't need a jacket" << endl;
	}


	if (weather == "sunny")
	{
		cout << "Great day for a picnic! " << endl;
	}
	else if (weather == "rainy")
	{
		cout << "An ideal weather to reed a book inside!" << endl;
	}
	else if (weather == "cloudy")
	{
		cout << "Maybe, you should go to museum?" << endl;
	}
	else if (weather == "snowy")
	{
		cout << "What about making a snowman?" << endl;
	}
	else if (weather == "windy")
	{
		cout << "Fly a kite if you have one!" << endl;
	}






	switch (weather[0])
	{
	case 's' :
		if (weather == "sunny")
		{
			cout << "Wear your favourite shoes!" << endl;
		}
		else if (weather == "snowy")
		{
			cout << "Snow boots will keep your feet warm!" << endl;
		}
		break;
	case 'r' : 
		cout << "Rain boots are a good idea! " << endl;
		break;
	case 'c' :
		cout << "Today, any shoe is suitable." << endl;
		break;
	case 'w' :
		cout << " Wear something sturdy!" << endl;
		break;
	default :
		cout << "Unexpected weather condition" << endl;
		break;
	}

	return 0;
}
