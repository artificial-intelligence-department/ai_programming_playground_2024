//не можна використовувати вектори
#include <iostream>
#include <algorithm>


using namespace std;
//використана як мінімум одна цілочисельна константа
const int variant = 30;
//використано свою структуру даних
struct student{
    string name;
    string surname;
    int money;
};

float function_1(){
    //використана одна дійсна змінна
    float a, b;
    //в коді використано оператори виведення та введення даних
    cout << "Enter 2 float" << endl;
    cin >> a >> b;
    // використана одна цілочисельна змінна
    cout << "Enter 3 int" << endl;
    int c, d, e;
    cin >> c >> d >> e;
    // використана як мінімум одна дійсний з подвійною точністю змінна
    cout << "Enter 1 double" << endl;
    double f;
    cin >> f;
    //використаний одновимірний масив
    double arr[] = {(double)a, (double)b, (double)c, (double)d, (double)e, (double)f};
    //використаний for цикл 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Biggest number is: ";
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Smallest number is: ";
    for(int i = 3; i < 6; i++){
        cout << arr[i] << " ";
    }

    double sum1 = arr[0] + arr[1] + arr[2];
    double sum2 = arr[3] + arr[4] + arr[5];
    double result;
    //використані умовні оператори та розгалуження
    if(sum1 > sum2*2){
        result = sum1*sum2;
        }else if(sum1 > sum2*3){
            result = sum1/sum2;
        }else if(sum1 > sum2*4){
            result = sum1+sum2;
        }
        float x = result / variant;
        cout << endl;
        cout << "x = ";
        cout << x;
        return;
    }



double function_2(float x){
const size_t M = 5;
    const size_t N = 5;
    //використаний двовимірний масив
    int a[M][N];
    //можна переписати без використання STL
    //в коді використано вказівники
    fill( *a, *a + M * N, x);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            //використано математичні операції та математичні функції
            a[i][j] = a[i][j] + variant + i - j * (rand() % 100);
        }
    }

    for ( const auto &row : a )
    {
        for ( int x : row ) cout << x << ' ';
        cout << endl;
    }
    //використано рекурсивну функцію
    return function_2;
}
void function_3(){

}

int main(){
    function_1();
    function_2();

    return 0;
}