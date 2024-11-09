#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const int massive[], int n, int startIndex){
    for (int i = 0; i < n; i++)
    {
        cout << massive[(startIndex + i) % n] << " ";
    }
    cout << endl;
}

int main(){
    const int N = 100;
    int massive[N];
    int realSize;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> realSize;
    cout << "Введіть елементи в масиві: ";
    for (int i = 0; i < realSize; i++)
    {
        cin >> massive[i];
    }
    
    int K;
    cout << "Введіть елемент К: ";
    cin >> K; 

    print(massive, realSize, K);

    sort(massive, massive + realSize);
    cout << "Відсортований масив: " ;
    for (int i = 0; i <  realSize; i++)
    {
        cout << massive[i] << " ";
    }
    cout << endl;

    int new_massive[N];
    int new_size = 0;
    for (int i = 0; i < realSize; i++)
    {
        if (massive[i] % 2 != 0)
        {
            new_massive[new_size++] = massive[i];
        }
    }

    cout << "Масив після видалення парних чисел: ";
    print(new_massive, new_size, K);

    return 0;
}