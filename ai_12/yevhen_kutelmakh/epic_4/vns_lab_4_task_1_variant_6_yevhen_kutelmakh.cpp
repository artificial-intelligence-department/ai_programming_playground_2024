#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

/*
1) Сформувати одновимірний масив цілих чисел, використовуючи генератор
випадкових чисел.
2) Роздрукувати отриманий масив.
3) Знищити елемент із заданим номером.
4) Додати після першого парного елемента масиву елемент зі значенням M[ I-1
]+2.
5) Роздрукувати отриманий масив.
*/

int main() {
    srand(static_cast<unsigned int>(time(0)));
    cout << "Enter size of an array: ";
    int n;
    cin >> n;
    int array[100];
    for(int i = 0; i < n; i++) {
        array[i] = rand();
        cout << array[i] << " ";
    }
    cout << "\nWhich el you want to delete? ";
    int k;
    cin >> k;
    //видаляємо елемент k
    int arraycopy[100];
    int counter = 0;
    cout << "Array with deleted element #" << k << "\n";
    for(int i = 0; i < n-1; i++) {
        if(counter==0) {
            if(i==k) {
                counter++;
                arraycopy[i]=array[i+1];
            }
            else {
                arraycopy[i]=array[i];
            }
        }
        else {
            arraycopy[i]=array[i+1];
        }
        cout << arraycopy[i] << " ";
    }
    //додаємо після першого парного елементу масиву елемент зі значенням arraycopy[b-1] + 2, де b - індекс першого парного елементу
    int even_index = -1;
    int arrayFinal[100];
    for(int i = 1; i < n-1; i++) {
     //Перший лемент не враховуємо бо не можемо обчислити значення попереднього, отже не можемо додати новий
        if(arraycopy[i] % 2 == 0) {
            even_index = i;
            break;
        }
    }
    if(even_index == -1) 
        cout << "\nThere is no even elements";
    else {
        cout << "\nNew array looks like: \n";
        for(int i = 0; i < n; i++) {
            if(counter!=2) {
                if(i-1 == even_index) {
                    arrayFinal[i] = arrayFinal[even_index-1] + 2;
                    counter++;
                }
                else {
                    arrayFinal[i] = arraycopy[i];
                }
            }
            else {
                arrayFinal[i] = arraycopy[i-1];
            }
            cout << arrayFinal[i] << " ";
        }
    }
    return 0;
}