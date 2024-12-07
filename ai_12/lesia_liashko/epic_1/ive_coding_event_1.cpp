#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>


using namespace std;

const int variant = 44; //константа
const string filename = "list.txt"; 

void function_1 (){
    float a,b; //одна дійсна змінна

    double f; //дійсний з подвійною точністю змінна

    int c,d,e; //цілочисельна змінна;
    
    cout << "enter numbers: a,b,c,d,e,f" << endl;
    cin >> a >> b >> c >> d >> e >> f;//введення даних
    
    double arr[6]= {a,b,c,d,e,f}; // одновимірний масив
    double max1, max2, max3;
    max1=max2=max3=arr[0];

    for (int i = 0; i< 6; i++){
        if (arr[i]> max1){
            max3=max2;
            max2=max1;
            max1 = arr[i];
        }else if (arr[i]> max2){
            max3= max2;
            max2= arr[i];
        } else if (arr[i]>max3){
            max3= arr[i];
        }
    }
   
    double min1, min2, min3;
    min1=min2=min3=arr[0];
    for (int i = 0; i< 6; i++){
        if (arr[i]<min1){
            min3=min2;
            min2=min1;
            min1 = arr[i];
        }else if (arr[i]< min2){
            min3= min2;
            min2= arr[i];
        } else if (arr[i]<min3){
            min3= arr[i];
        }
    }
   
   
   double summax = max1+max2+max3;
   double summin = min1+min2+min3;
   
   
   if (summax > 2* summin ){
       double x=summax*summin;
       double result;
       return result=x/variant;
    } else if(summax > 3*summin && summin*3 < summin*2 ) {
       double  x= summax/summin;
        double result;
       return result=x/variant;

    } else if (summax > summin * 4 && summin*4 < summin*3 ){
       double x= summax+summin;
        double result;
       return result=x/variant;
    }
}

void function_2(double** x) {
    for (int i = 0; i < 5; i++){ //цикл
        for (int j = 0; j < 5; j++){
            arr[i][j]= x[i][j];//двовимірний масив
        }
    }

for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            new arr[i][j]=(x+44+j-i)*rand(1,100);
            cout << arr[i][j] << endl;//виведення даних
        }
    }
}
void function_3 (double** x){


}
 struct List{
        string name;
        string sname;
        float amount;
    };

List listinput (){
    List list;
    cin.ignore();
    cin.getline (name);
    cin.getline (sname);
    cin.getline (amount);

} 
void function_4 (const char* filename, ){
   ofstream file(filename );
   if (!file){

   }
}

int main (){
    double result1 = function_1 (result);
    cout << result1 << endl;
function_2(x);
double** tower[i][j]= function_2(x);



}