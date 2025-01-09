#include <iostream> 

using namespace std;

int main()
{
    float price;
    cout << "Введіть ціну яблук за кілограм: ";
    cin >> price;
    
    cout << "\nВага (г)\t Вартість (грн)\n";
    cout << "-----------------------------\n";
    for(int weight = 100; weight <= 1000; weight+=100){
        float cost = price* weight / 1000;
        cout << weight << " г\t\t" << cost << " грн" << endl;
    }
    return 0;
}