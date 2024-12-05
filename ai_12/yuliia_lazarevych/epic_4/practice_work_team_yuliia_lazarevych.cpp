#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//використовую структуру для зберігання інформації про перевірку
struct Data {
    string value;
    bool isPalindrome;
};

//використовую вкладену структуру для групування даних про рядки і числа
struct TestData { 
    vector<Data> strings; //використовую масив даних для рядків
    vector<Data> numbers; //та масив даних для чисел
};

//використовую рекурсивну функцію для перевірки рядка на паліндромність (АЛГОРИТМ ОБРОБКИ)
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    string str = to_string(number);
    return isPalindrome(str, 0, str.size() - 1);
}

//використовую функцію для перевірки масивів даних на паліндромність
TestData checkPalindromes(const vector<string>& stringData, const vector<int>& numberData) {
    TestData results; // ВИКОРИСТАННЯ ВКЛАДЕНИХ СТРУКТУР

    //використовую обробку рядків (АЛГОРИТМ ОБРОБКИ МАСИВУ РЯДКІВ)
    for (const auto& str : stringData) {
        results.strings.push_back({str, isPalindrome(str, 0, str.size() - 1)});
    }

    //використовую обробку чисел (АЛГОРИТМ ОБРОБКИ МАСИВУ ЧИСЕЛ)
    for (int num : numberData) {
        results.numbers.push_back({to_string(num), isPalindrome(num)});
    }

    return results;
}

//використовую функцію для виведення результатів (ВИКОРИСТАННЯ СТРУКТУР ДЛЯ ВИВЕДЕННЯ)
void printResults(const TestData& data) {
    cout << "Результати перевірки рядків:" << endl;
    for (const auto& strData : data.strings) {
        cout << "Рядок \"" << strData.value << "\" є паліндромом? " 
             << (strData.isPalindrome ? "Так" : "Ні") << endl;
    }

    cout << "\nРезультати перевірки чисел:" << endl;
    for (const auto& numData : data.numbers) {
        cout << "Число " << numData.value << " є паліндромом? " 
             << (numData.isPalindrome ? "Так" : "Ні") << endl;
    }
}

int main() {
    //використовую масиви для введення текстових данних
    vector<string> stringData = {"radar", "hello", "level", "world"}; //масив рядків
    vector<int> numberData = {12321, 12345, 1112111, 98789};          //масив чисел

    //перевіряю паліндромів завдяки алгоритму обробки
    TestData results = checkPalindromes(stringData, numberData);

    printResults(results);

    return 0;
}
