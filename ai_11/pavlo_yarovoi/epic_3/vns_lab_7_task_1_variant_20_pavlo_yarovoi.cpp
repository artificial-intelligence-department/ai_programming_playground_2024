#include <iostream>
#include <vector>

using namespace std;

#define NeedsForTriangle(x, y, z) ((x + y > z) && (y + z > x) && (z + x > y))

bool ValidTriangle(int x, int y, int z) {
    return NeedsForTriangle(x, y, z);
}

int triangle(const vector<int>& numbers) {
    int validTriangles = 0;
    for (size_t i = 0; i < numbers.size(); i += 3) {
        if (i + 2 < numbers.size()) {
            int x = numbers[i];
            int y = numbers[i + 1];
            int z = numbers[i + 2];
            if (ValidTriangle(x, y, z)) {
                validTriangles++;
            }
        }
    }
    return validTriangles;
}

int main() {
    vector<int> numbers1 = {3, 4, 5};
    vector<int> numbers2 = {3, 4, 5, 5, 5, 5, 7, 8, 10};
    vector<int> numbers3 = {3, 4, 5, 6, 7, 8, 10, 10, 10, 12, 14};

    cout << "Number of possible triangles for 3 parameters: " << triangle(numbers1) << endl;
    cout << "Number of possible triangles for 9 parameters: " << triangle(numbers2) << endl;
    cout << "Number of possible triangles for 11 parameters: " << triangle(numbers3) << endl;

    cout << "Can we form a triangle with (3, 4, 5): " << (ValidTriangle(3, 4, 5) ? "Yes" : "No") << endl;
    cout << "Can we form a triangle with (5, 5, 5): " << (ValidTriangle(5, 5, 5) ? "Yes" : "No") << endl;

    return 0;
}
