#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distance, fuelConsumption, fuelPrice;
    cout << "Calculation of the trip cost to the dacha and back.\n";
    cout << "Distance to the dacha (km) > ";
    cin >> distance;
    cout << "Fuel consumption (liters per 100 km) > ";
    cin >> fuelConsumption;
    cout << "Price per liter of fuel (UAH) > ";
    cin >> fuelPrice;

    double totalCost = (distance * fuelConsumption / 100) * 2 * fuelPrice;

    cout << fixed << setprecision(2);
    cout << "The trip to the dacha and back will cost " << totalCost << " UAH." << endl;

    double voltage, resistance;
    cout << "Calculation of current using known values of voltage and resistance.\n";
    cout << "Enter the voltage (volts) > ";
    cin >> voltage;
    cout << "Enter the resistance (ohms) > ";
    cin >> resistance;

    if (resistance != 0) {
        double current = voltage / resistance;
        cout << "The current in the circuit: " << current << " amperes.\n";
    } else {
        cout << "Resistance cannot be zero.\n";
    }

    return 0;
}
