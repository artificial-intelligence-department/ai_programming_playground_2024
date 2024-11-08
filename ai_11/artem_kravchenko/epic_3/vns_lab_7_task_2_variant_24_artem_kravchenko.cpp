#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void rem(vector<int>& vec){
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return (x % 2) == 0 ; }), vec.end());
}

void rem(vector<string>& vec){
    vec.erase(remove_if(vec.begin(), vec.end(), [&](const string& word) {
        auto index = &word - &vec[0];
        return index % 2 != 0;
    }), vec.end());
}

int main(){
    int size_n = 0;
    cout << "введіть кількість елементів: "<< endl;
    cin >> size_n;

    vector<int> numbers(size_n);
    cout << "Введіть " << size_n << " чисел: " << endl;
    for (int i = 0; i < size_n; i++)
    {
        cin >> numbers[i];
    }
    rem(numbers);
    cout << "Результат видалення парних чисел: " << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " " << endl;
    }

    int size_w = 0;
    cout << "Введіть кількість слів: " << endl;
    cin >> size_w;
    cin.ignore();
    
    vector<string> words(size_w);
    cout << "Введіть " << size_w << " слів:" << endl;
    for (int i = 0; i < size_w; i++)
    {
        getline(cin, words[i]);
    }

     rem(words);
     cout << "Результат видалення парних слів: " << endl;
    for (const string& word : words)
    {
        cout << word << " " ;
    }
    
    
    return 0;

}