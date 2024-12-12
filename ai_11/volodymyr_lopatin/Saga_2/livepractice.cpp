#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Smartphone {
    string brand;
    int rom;
    double price;
    Smartphone(string BrandName, int RomCap, double Price) : brand(BrandName),
    rom(RomCap), price(Price) {}
    ~Smartphone() {
        cout << "You've just deleted an object.";
    }
};

int main() {
    Smartphone iphone13 ("Apple", 256, 554.0);
    string fileName;
    cin >> fileName;
    ofstream write(fileName); 
    if (!write) {
        cerr << "You aren't able to open this file(";
        return 1;
    }
    write << "Smartphone brand: " << iphone13.brand << endl <<
    "Smartphone's rom capacity: " << iphone13.rom << endl <<
    "Smartphone's price: " << iphone13.price;
    return 0;
}