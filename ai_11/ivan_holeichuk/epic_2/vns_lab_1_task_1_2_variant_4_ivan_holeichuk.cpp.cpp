#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//task1
	float af = 1000.0f;
	float bf = 0.0001f;

	double ad = 1000.0;
	double bd = 0.0001;

	float resultf = (pow(af + bf, 3) - (pow(af, 3) / 3 * af * pow(bf, 2) + pow(bf, 3) + 3 * pow(af, 2) * bf));

	double resultd = (pow(ad + bd, 3) - (pow(ad, 3) / 3 * ad * pow(bd, 2) + pow(bd, 3) + 3 * pow(ad, 2) * bd));
		
	cout << "float = " << resultf << endl;

	cout << "double = " << resultd << endl;



	//task2

	int m = 7;
	int n = 2;

	cout << "n++*m = " << (++n * m) << endl;

	bool v2 = (n++ < m);
	cout << "n++<m = " << v2 << endl;

	bool v3 = (m-- > m);
	cout << "m-- > m = " << v3 << endl;

	return 0;
}

