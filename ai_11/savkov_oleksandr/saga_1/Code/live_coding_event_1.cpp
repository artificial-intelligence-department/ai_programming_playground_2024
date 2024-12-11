#include <iostream>
#include <vector>

using namespace std;

double var = 21;




double function_1() {
    double a,b,f;
    int c,d,e;
    

    cout << "Введіть дійсні числа: ";
    cin >> a >> b >>f;
    cout << "Введіть цілі числа: ";
    cin >> c >> d >>e;

    vector <double> pashka  = {a ,b,f,static_cast<double>(c),static_cast<double>(d),static_cast<double>(e)};
    
    sort(pashka.begin(), pashka.end());

    vector<double> bilshi = {pashka[5],pashka[4],pashka[3]};
    vector<double> menshi = {pashka[0], pashka[1], pashka[2]};

    double summMensh = 0;
    double summBilsh = 0;
    double result = 0;
     
    for(int i = 0; i < bilshi.size(); i++){
        summBilsh += bilshi[i];
    }
    for(int i = 0; i < menshi.size(); i++){
        summMensh += menshi[i];
    }

    if (summBilsh > summMensh * 2){
        result = summMensh * summMensh;
    } else if (summBilsh > summMensh * 3){
        result = summMensh/ summMensh;
    } else if (summBilsh > summMensh * 4){
        result = summMensh + summMensh;
    }
     result = result / var;
    
 return result;

    


}

double function_2(double& x, double matr[5][5]){
     for(int i=0; i<5; i++){
        for(int j=0; j< 5; j++) {
            matr[i][j] = x;
        }
     }

     for(int i=0; i<5; i++){
        for(int j=0; j< 5; j++) {
            matr[i][j] = (matr[i][j] + var + j -1) * (rand()% 100+1);

        }
     }
     for(int i =0; i<5; i++){
        for(int j=0; j<5; j++ ){
            cout << matr[i][j];
            
        }

     }
     return 0;
}


int main(){
    
    double x = function_1();

    double matr[5][5];

    function_2(x, matr);

    double stovb[5];




    return 0;
}