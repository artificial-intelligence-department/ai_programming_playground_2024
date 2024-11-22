#include <iostream>
#include <string>
using namespace std;



bool isPalindrome(const string & str, int start, int end)
{
	if (start = end)
	{
		return true;
	}
	if (str[start] != str[end])
	{
		return false;
	}

	return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number)
{
	string str = to_string(number);
	return isPalindrome(str, 0, str.length() - 1);
}

int main()
{
	string testStr;
	cout << "Enter a string: ";
	cin >> testStr;
	if (isPalindrome(testStr, 0, testStr.length() - 1))
	{
		cout << "The string " << testStr << " is a palindrome." << endl;
	}
	else
	{
		cout << "The string " << testStr << " is not a palindrome." << endl;
	}

	int testNum;
	cout << "Enter a number: ";
	cin >> testNum;
	if (isPalindrome(testNum))
	{
		cout << "The number" << testNum << " is a palindrome." << endl;
	}
	else
	{
		cout << "The number " << testNum << " is not palindrome." << endl;
	}



	return 0;
}












