#include <iostream>

using namespace std;

int main() {

	int n;

	cout << "Your number?" << endl;

	cin >> n;

	
	if (n % 2 == 0) {
		cout << "Your number even" << endl;
	} else {
		cout << "Your number odd" << endl;
	}

	
	int r;
	cout << "The author of this program guessed a number from 1 to 3, you have 1 try to guess!" << endl;

	cout << "Enter your guess: ";

	cin >> r;

	switch (r) {
		case 1:
			cout << "Incorrect. Bye!" << endl;
			break;
		case 2:
			cout << "Correct. Bye!" << endl;
			break;
		case 3:
			cout << "Incorrect. Bye!" << endl;
			break;
		default:
			cout << "I said from 1 to 3. Bye<" << endl;
			break;
	}
	
	
	
	
	
	
	
	
	
	return 0;
}