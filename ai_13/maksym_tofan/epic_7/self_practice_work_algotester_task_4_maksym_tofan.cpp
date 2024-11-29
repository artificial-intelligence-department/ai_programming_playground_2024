#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int N;  
    cin >> N;
    cin.ignore();  
    
    int rituals = 0;  // кількість ритуалів, які потрібно провести

    // Для кожного рядка закляття
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);  // зчитуємо рядок

        bool inRitual = false;  

        // посилання&вказівник
        for (char c : line) {
            if (c == '#') {
                if (!inRitual) {  
                    rituals++;  
                    inRitual = true;  
                }
            } else {
                inRitual = false;  
            }
        }
    }

    cout << rituals << endl;  
    return 0;
}
