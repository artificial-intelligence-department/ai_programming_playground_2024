#include <iostream>
#include <vector>
#include <math.h>

int main() //Permutations of Two Arrays
{
    int n, m;
    std::cin >> n >> m;
    int size = n < m ? n : m;
    std::vector<int> a;
    std::vector<int> b;
    int temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        if (a.size() == 0 || a[a.size() - 1] <= temp) {
            a.push_back(temp);
            continue;
        }
        for (int j = 0; j < a.size(); j++) {
            if (a[j] > temp) {
                a.insert(a.begin() + j, temp);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        std::cin >> temp;
        if (b.size() == 0 || b[b.size() - 1] <= temp) {
            b.push_back(temp);
            continue;
        }
        for (int j = 0; j < b.size(); j++) {
            if (b[j] > temp) {
                b.insert(b.begin() + j, temp);
                break;
            }
        }
    }
    unsigned long long maxScore = 0;
    int lastA = n - 1;
    int lastB = m - 1;
    int minA = 0;
    int minB = 0;
    for (int i = 0; i < size; i++) {
        int q = abs(a[lastA] - b[minB]);
        int w = abs(b[lastB] - a[minA]);
        if (q > w) {
            maxScore += q;
            lastA--;
            minB++;
        }
        else {
            maxScore += w;
            lastB--;
            minA++;
        }
        
    }
    std::cout << maxScore;
}
