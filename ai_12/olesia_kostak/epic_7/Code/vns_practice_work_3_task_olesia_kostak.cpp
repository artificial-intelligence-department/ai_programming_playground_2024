#include <iostream>

int main()
{
    std::cout << "--)-Economy-(-----------------------------------------------------------------------------" << std::endl;
    long InitialDeposit;
    std::cout << "Enter sum of money: " << std::endl;
    std::cin >> InitialDeposit;
    double InterestRate = 0.03;
    long CurrentAmount = InitialDeposit;

    for(int year = 1; year <= 2; year++)
    {
        CurrentAmount += CurrentAmount * InterestRate;
        std::cout << "Sum of deposit after " << year << " year: " << CurrentAmount << std::endl;

    }

    std::cout << "--=-Physics-=----------------------------------------------------------------------------" << std::endl;
    std::cout << "Enter the amount of first resistsance: " << std::endl;
    double Res1; std::cin >> Res1;
    std::cout << "Enter the amount of second resistsance: " << std::endl;
    double Res2; std::cin >> Res2;
    std::cout << "Circuit resistance:" << Res1 + Res2 << " OM" << std::endl;
    
    return 0;
}