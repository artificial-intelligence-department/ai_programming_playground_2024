#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
// lab 3 variant 1

int main() {
    // ������� ������� �����
    int N;
    cin >> N;
    cin.ignore();  // �������� ����������� �� ����� ����� ���� N

    int totalRituals = 0;

    // ���������� ����� �����
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;

        // ���������� ����� ����� � �����
        while (ss >> word) {
            int rituals = 0;
            bool inRitual = false;

            // ���������� ����� ������ � ����
            for (char c : word) {
                if (c == '#') {
                    if (!inRitual) {
                        // ������� ���� ����������� ����������� �������
                        rituals++;
                        inRitual = true;
                    }
                }
                else {
                    // ���������� ����������� ����������� �������
                    inRitual = false;
                }
            }

            totalRituals += rituals;
        }
    }

    // �������� �������� ������� �������
    cout << totalRituals << endl;

    return 0;
}
