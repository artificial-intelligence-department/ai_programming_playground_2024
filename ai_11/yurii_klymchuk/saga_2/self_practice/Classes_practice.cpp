#include <iostream>
#include <cmath>
using namespace std;

#define EPSILON 0.0001
class Cylinder {
    private:
    float radius;
    float height;

    public:
    Cylinder () : radius(5), height(10) {}

    void SetRadius(float new_radius) {
        if (new_radius > 0) {
            radius = new_radius;
        }
    }

    void SetHeight(float new_height) {
        if (new_height > 0) {
            height = new_height;
        }
    }

    float GetRadius() const {
        return radius;
    }

    float GetHeight() const {
        return height;
    }

    float SurfaceArea() const {
        return 2 * M_PI * pow(radius, 2) + height*radius;
    }

    float Volume() const {
        return M_PI * pow(radius, 2) * height;
    }
};

int main() {
    Cylinder figure_1;

    figure_1.SetHeight(24.5);
    figure_1.SetRadius(11.2);
    
    cout << "Surface area of the cylinder is " << figure_1.SurfaceArea();

    const Cylinder figure_2;

    float r = figure_2.GetRadius();
    float h = figure_2.GetHeight();

    if(((M_PI*pow(r, 2)*h) - figure_2.Volume()) < EPSILON) { 
        cout << "\nCalculations are equal.";
    }
}