#include <iostream>
#include <vector>
#include <stack>

long long n, k;


bool show = false;
std::vector<short> vec;


void fillFibs(std::stack<unsigned long long> &fibs) {
    unsigned long long prev = 1;
    unsigned long long current = 1;
    unsigned long long temp;
    for (int i = 0; i < n - 1; i++) {
        fibs.push(prev + current);
        temp = prev;
        prev = current;
        current = current + temp;
    }
}

void showCombination() {
    for (short val : vec) std::cout << val;
}

void findCombination(int pos, std::stack<unsigned long long> fibs) {
    unsigned long long currMaxCombs;
    unsigned long long nextMaxCombs;
    if (fibs.size() != 0) {
        currMaxCombs = fibs.top();
        fibs.pop();
        if (fibs.size() != 0) nextMaxCombs = fibs.top();
        else nextMaxCombs = 1;
    }
    else {
        currMaxCombs = 1;
        nextMaxCombs = 1;
    }

    
    if (pos == 0 || vec[pos - 1] != 4) {
        if (k < nextMaxCombs) {
            vec[pos] = 4;
            if (pos != vec.size() - 1) findCombination(pos + 1, fibs);
            if (k == 0) {
                show = true;
                return;
            }
        }
        else k -= nextMaxCombs;
    }
    
    
    
    if (k < currMaxCombs) {
        vec[pos] = 7;
        if (pos != vec.size() - 1) findCombination(pos + 1, fibs);
        if (k == 0) {
            show = true;
            return;
        }
    }
    
}

int main()
{
    std::stack<unsigned long long> fibs;
    std::cin >> n >> k;
    k--;
    fillFibs(fibs);
    for (int i = 0; i < n; i++) vec.push_back(0);
    findCombination(0, fibs);
    if (!show) std::cout << "Flowers";
    else showCombination();
    return 0;
}
