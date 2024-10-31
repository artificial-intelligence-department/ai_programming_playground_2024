#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>
#include<cmath> 
#include <fstream>
using namespace std;

class Hero; // оголошення класу

class Villian {
private:
	int health1 = 100;
public:
	friend class Hero;
	void damage(Hero& hero);
	int getx() const {
		return health1;
	}
};

class Hero {
private:
	int health2 = 100;
public:
	friend class Villian;
	void damage(Villian& villian) {
		villian.health1 -= 10;
		cout << "health of villian = " << villian.health1 << endl;
	}
	void heal(Villian& villian) {
		villian.health1 += 5;
		cout << "Villian healed = " << villian.health1 << endl;
	}
	int gety() const {
		return health2;
	}
};

void Villian::damage(Hero& hero) {
	hero.health2 -= 2;
	cout << "Health of hero = " << hero.health2 << endl;
}

int main() {

	Villian Hamurapi;
	Hero Solon;
	srand(static_cast<unsigned int>(time(NULL)));

	int rand_num = 1 + rand() % 5;
	bool stop = false;
	int user_num = 0;

	do {
		cout << "Your number? ";
		cin >> user_num;
		if (user_num != rand_num) {
			Hamurapi.damage(Solon);
			Solon.heal(Hamurapi);
			cout << "Ouch! (-2hp) =" << endl;

		}
		else {
			Solon.damage(Hamurapi);
			cout << "Villian health -10hp" << endl;
		}

		if (Hamurapi.getx() <= 0) {                 //перевірка для завершення циклу
			cout << "Game over! You win!" << endl;
			stop = true;
		}

		if (Solon.gety() <= 0) {
			cout << "Game over! You lose!" << endl;
			stop = true;
		}



	} while (!stop);



	return 0;
}

