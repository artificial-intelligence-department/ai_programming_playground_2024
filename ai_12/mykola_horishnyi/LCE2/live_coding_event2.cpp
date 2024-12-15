#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string> // стрічки
#include <cmath> // обчислення
using namespace std;

double measurement(double distance, const string& system)  // Рахуємо дистанцію і конвертуємо її 
{
	if (system == "m")
		return distance;
	else if (system == "mi_US")
		return distance * 1609.347;
	else if (system == "mi")
		return distance * 1609.344;
	else
		return;
}

bool  isPalindrome(double distance)
{
	string numberStr = string(distance);
	int lengh = numberStr;
		for (int i = 0; i < lengh; i++)
		{
			if (numberStr[i] != numberStr[lengh - 1])
				return false;
		}
		return true;
}

// sort бульбашкою
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[i])
			{
				// ffffffffffff
			}
		}

	}
}

// Тепер про користувача
void  User(string const& name)
{
	int nameLenght = name.lenght();
	int arr[nameLenght];



	for (int i = 0; i < nameLenght; i++)
	{
		arr[i] = max 
	}



}









