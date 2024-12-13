// <set>: 
// надає контейнер, який зберігає елементи у відсортованому порядку 
// та автоматично забезпечує їхню унікальність, тобто якщо ви попробуєте
// вставити елемент, який уже є в контейнері, то він не буде доданий.

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

int main(){

    // print s1:

    set<int, greater<int>> s1;
    s1.insert(1);
    s1.insert(2354);
    s1.insert(53);

    for(int i : s1){                   
        cout << i << " ";
    }

    // print set s1 (with iterator):

    set<int, greater<int>>::iterator itr;
    cout << "\n Set s1: \n";
    for(itr = s1.begin(); itr != s1.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl << endl;


// examples for library <iterator>:
    vector<int> vec = {1, 2, 3, 4, 5};

    // ітератори для обходу
    for (auto it = begin(vec); it != end(vec); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // reverse_iterator
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;


    return 0;
}