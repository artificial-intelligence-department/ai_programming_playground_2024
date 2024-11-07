#include <iostream>
#include <iomanip>
#include <cmath>


int main(){
    const double sure = -1e-9;

    // // a) n
    std::cout << "Для визначеного n=10 : \n";
    for(double x=0.2; x<=1; x+=0.08){
        double result = 0, n=10;
        for(double i=0; i<=n; i++){
            result += 1/(2*i+1)*pow(((x-1)/(x+1)), (2*i+1));
            if(result > sure) {
                result = 0;
            }
        }
        std::cout << "1/2 ln("<< x << ") = " << result << "\n";
    }

    //б) епселон
    std::cout << "\nДля визначеного eps = 0.0001 : \n";

    for(double x=0.2; x<=1; x+=0.08){
        double power = 0, result = 0, i = 0, epselon = 0.0001;
        power += 0.5*log(x);
        while (fabs(power-result) >= (epselon)){
            result += 1/(2*i+1)*pow(((x-1)/(x+1)), (2*i+1));
            if(result > (-1)*epselon) {
                result = 0;
            }
            i++;
        } 
        std::cout << "1/2 ln("<< x << ") = " << std::setprecision(5) << result << "\n";
    }

    //значення функції
    std::cout << "\nПряме визначення значення функції : \n";
    for(double x=0.2; x<=1; x+=0.08){
        double result;
        result = log(x)*0.5;
        if(result >  sure) {
            result = 0;
        }
        std::cout << "1/2 ln("<< x << ") = " << result << "\n";
    }

    return 0;
}