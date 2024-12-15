#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

double simulateMoneyPrecision(double value) {
	return round(value * 100.0) / 100.0;
}

bool isPalindrome(int distance) {
	int original = distance;
	int reversed = 0;

	while (distance > 0) {
		reversed = reversed * 10 + (distance % 10);
		distance /= 10;
	}

	return original == reversed;
}

string sortString(const string& str) {
	string sorted = str;
	for (size_t i = 0; i < sorted.length(); i++) {
		for (size_t j = i + 1; j < sorted.length(); j++) {
			if (sorted[i] > sorted[j]) {
				char temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}

	return sorted;
}

void createUserIdentifier(const string& name) {
	string sortedName = sortString(name);

	ofstream outFile("deliveryInfo.txt", ios::app);
	if (outFile.is_open()) {
		for (char c : sortedName) {
			int asciiValue = static_cast<int>(c);
			double identifierValue = simulateMoneyPrecision(asciiValue * 0.4);
			outFile << identifierValue << " ";
		}
		outFile.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}

void readFromFile() {
	ifstream inFile("deliveryInfo.txt");
	if (inFile.is_open()) {
		string line;
		cout << "Reading user identifier from file: " << endl;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}

double convertDistance(double distance, string unit) {
	if (unit == "mi") {
		return distance * 1609.344;
	}
	else if (unit == "mi_US") {
		return distance * 1609.347;
	}
	else if (unit == "m") {
		return distance;
	}
	else {
		cout << "Invalid unit" << endl;
		return -1;
	}
}

int main() {
	string name, unit;
	double distance;
	double deliveryDistanceInMeters = 0;

	cout << "Enter your name: ";
	cin >> name;

	createUserIdentifier(name);

	char readFromFileOption;
	cout << "Want to read user identifier from file (y/n): ";
	cin >> readFromFileOption;
	if (readFromFileOption == 'y' || readFromFileOption == 'Y') {
		readFromFile();
	}

	cout << "Enter distance: ";
	cin >> distance;

	cout << "Enter unit(mi/mi_US/m): ";
	cin >> unit;

	deliveryDistanceInMeters = convertDistance(distance, unit);
	if (deliveryDistanceInMeters == -1) return 0;

	cout << "Converted distance: " << deliveryDistanceInMeters << "merers" << endl;

	double deliveryDistanceInKilometers = deliveryDistanceInMeters / 1000.0;
	double discount = 0;
	double totalPrice = deliveryDistanceInKilometers * 0.1;

	if (isPalindrome(static_cast<int>(deliveryDistanceInKilometers))) {
		cout << "Distance is palindrome, you get a bonus of +200km" << endl;
		deliveryDistanceInKilometers += 200;
	}

	char useBonus;
	cout << "Do you want to use bonuses (100km = 1$)(y/n): ";
	cin >> useBonus;

	if (useBonus == 'y' || useBonus == 'Y') {
		double bonusInKm = static_cast<int>(deliveryDistanceInKilometers / 100);
		discount = bonusInKm;
		deliveryDistanceInKilometers -= bonusInKm * 100;
		totalPrice -= discount;
	}

	deliveryDistanceInMeters = simulateMoneyPrecision(deliveryDistanceInMeters);
	discount = simulateMoneyPrecision(discount);

	deliveryDistanceInKilometers = simulateMoneyPrecision(deliveryDistanceInKilometers);
	totalPrice = simulateMoneyPrecision(totalPrice);

	cout << "Current delivery distance: " << deliveryDistanceInMeters << "m" << endl;
	cout << "Your discount: " << discount << "$" << endl;
	cout << "Accumulated distance: " << deliveryDistanceInKilometers << "km" << endl;
	cout << "Shipping cost: " << totalPrice << "$" << endl;

	return 0;
}