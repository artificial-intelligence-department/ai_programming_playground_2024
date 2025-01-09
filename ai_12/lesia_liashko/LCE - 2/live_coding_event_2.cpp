#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
 int main (){
    const int pi = 3; //одна цілочисельна константа
    string user;
    int l; //одна цілочисельна змінна

   
    cout << "ваше імʼя" << endl; //в коді використано оператори виведення та введення даних
    cin >> user; //в коді використано оператори виведення та введення даних
    double meter; //одна дійсна змінна подвійною точністю змінна

   
    cout << "Напишіть відстань" << endl;
    cin >> l;
    cout << "виберіть свою систему вимірювання: 1.mi 2.mi_US 3.m" << endl;
    
    string m;
    cin >> m;
  
   if (m=="m"){ //умовні оператори та розгалуження
    meter=1*l;
   } 
   else if (m=="mi") {
    meter=1609.347*l;
   } 
   else if (m=="mi_US") {
    meter=1609.344*l;
   }
   else {
    return 1;
   }

   int n, digit, rev = 0;
   n = l;
     do
     {//do while цикл
         digit = l % 10;
         rev = (rev * 10) + digit;
         l = l / 10;
     } while (l != 0);
     meter /=1000;
     
     if (n == rev and n > 0) {
        meter /=1000;
        meter +=200;
        } 
    
   
    int rest, bonus;
    string answer;
   
    cout << "чи хочете конвертувати у накопичення бонусів?" << endl;
    cin >> answer;
  
    if (answer == "yes"){
         rest/= meter;
         bonus = meter - rest*meter; // математичні операції та математичні функції
         cout << "твій залишок після конвертації:" << bonus << " Твоя накопичена знижка:" << rest << endl;}
        
        string name;
        name = user;
        
        sort(name.begin(), name.end());
       
        cout << "скільки букв у вашому імені?" << endl;
        int letters;
        cin >> letters;
      
       // в коді використано вказівники
       const char* vscii= name.c_str(); //одновимірний масив 
        for (int i = 0; i < sizeof(vscii); i++){// for цикл 
            cout << int(vscii[i])*0.4 << " номер: " << i << endl ;
         }
    
  

    ofstream OutFile ("delivery.txt"); //функції роботи з файлами, для того, щоб записати у файл
    if (OutFile.is_open()){
        OutFile << user << " "<< name << " " << l  << " " << meter << endl;
        OutFile.close();
    } else {
        cout << "error" ;
    }

    ifstream inFile("delivery.txt"); //в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    if (inFile.is_open()){
            string text;
            while (getline(inFile, text)){
                cout << text;
            }
        inFile.close();
    } else {
                cout << "error" ;
    }
    return 0;
    
 }