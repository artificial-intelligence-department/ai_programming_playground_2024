#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Food {
    string name;
    int maxWeight;
};

int main() {
    int N;
    cin >> N;

    vector<Food> foods;

    for (int i = 0; i < N; ++i) {
        string food;
        int weight;
        cin >> food >> weight;

        bool found = false;

        for (auto& f : foods) {
            if (f.name == food) {
                f.maxWeight = max(f.maxWeight, weight);
                found = true;
                break;
            }
        }

        if (!found) {
            foods.push_back({ food, weight });
        }
    }

    int totalWeight = 0;
    for (const auto& f : foods) {
        totalWeight += f.maxWeight;
    }

    cout << totalWeight << endl;

    return 0;
}
