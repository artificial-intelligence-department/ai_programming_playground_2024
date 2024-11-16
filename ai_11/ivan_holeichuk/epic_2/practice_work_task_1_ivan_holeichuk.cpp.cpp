#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string weather;

	cout << "Enter the current weather conditions: " << endl;

	cin >> weather;

	if (weather == "snowy" || weather == "rainy" || weather == "windy") {
		cout << "Take a jacket!" << endl;
	}else {
		cout << "No jacket required." << endl;
	}
	
	if (weather == "snowy") {
		cout << "A nice day to have a hot cup of tea at home." << endl;
	}else if (weather == "rainy") {
		cout << "Don't forget an umbrella!" << endl;
	}else if (weather == "windy") {
		cout << "Make sure you don't get blown away." << endl;
	}else if (weather == "cloudy") {
		cout << "Great weather to walk around the city!" << endl;
	}else if (weather == "sunny") {
		cout << "A wonderful day to spend time together as a family in nature!" << endl;
	}else {
		cout << "Please enter a valid weather condition." << endl;
		
		return 1;
	}
	

	string slipperrec;

	int w;

	if (weather == "snowy") {
		w = 1;
	}else if (weather == "rainy") {
		w = 2;
	}else if (weather == "windy") {
		w = 3;
	}else if (weather == "cloudy") {
		w = 4;
	}else if (weather == "sunny") {
		w = 5;
	}else {
		w = 0;
	}
	
	switch (w) {
	case 1:
		slipperrec = "Wear warm slippers.";
		break;

	case 2:
		slipperrec = "Wear slippers that don't get wet easily!";
		break;

	case 3:
		slipperrec = "You can wear your favorite sneakers.";
		break;

	case 4:
		slipperrec = "Choose the shoes you like!";
		break;

	case 5:
		slipperrec = "Wear anything!";
		break;

	default:
		slipperrec = "Unknown weather.";
		break;

	}

	cout << slipperrec << endl;
	
	return 0;
}
