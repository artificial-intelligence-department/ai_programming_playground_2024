#include <iostream>
#include <stdio.h>
#include <fstream>//Бібліотека, яка працює з файлами
using namespace std;
int main()
{
    int operation;
    int InitialBalance = 1000;
    int Amount;

    ifstream infile("Balance.txt");//Відкриваємо файл для читання

    if (infile.is_open()) // Якщо файл існує і можна прочитати, зчитуємо баланс
    {
        infile >> InitialBalance;
        infile.close();
    }
    else
    {
        InitialBalance = 1000; // Якщо файл не існує, встановлюємо початковий баланс
    }

    while (true)
{
    printf("Choose operation\nExit - [0]\nCheck balance - [1]\nDeposit money - [2]\nWithdraw money - [3]\n");
    scanf("%d", &operation);


if (operation == 0)
{
    //Зчитуємо поточний баланс перед виходом
    ofstream outfile("Balance.txt");
    outfile << InitialBalance;
    outfile.close();
    break;
}
else if(operation == 1)
{
    printf("Your current balance:%d\n\n", InitialBalance);
}
else if(operation == 2)
{
    printf("Enter amount: ");
    scanf("%d",&Amount);

    InitialBalance +=Amount;

    printf("Your current balance:%d\n\n ", InitialBalance);

}
else if(operation == 3)
{
    printf("Enter how much you want to withdraw: ");
    scanf("%d", &Amount);

    if(Amount > InitialBalance)
    {
        printf("Not enough money!\n ");
    }else if(Amount <= InitialBalance)
    {
      InitialBalance -= Amount;
      printf("The operation was successful. Your balance now:%d\n\n ", InitialBalance);
    }
}
}
return 0;
}


