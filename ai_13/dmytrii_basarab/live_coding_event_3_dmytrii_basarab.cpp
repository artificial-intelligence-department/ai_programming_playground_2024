#include <iostream>
#include <fstream>
 #include <bits/stdc++.h>
using namespace std;

int func2(string myname) {
    int size = myname.length();
    int vovels = 0;
    for (int i = 0; i < size; i++) {
        if (myname[i] == 'a' || myname[i] == 'o' || myname[i] == 'u' || myname[i] == 'e' || myname[i] == 'y' || myname[i] == 'i'){
            vovels++;
        } 
    }
    return vovels;
}


void func(int sum) {
    ofstream file;
    file.open("filenew.dot", ios::out);
    file << "Sum 1: " << sum;
    file.close();
}



void func (){
    int sum = 0;
    int **p = nullptr;
    p = new int*[8];
    for (int i =0; i < 8;i++) {
        p[i] = new int[8];
    }
    p[0][0] =1;
    p[0][0] =2;
    p[0][0] =3;
    p[0][0] =4;
    p[0][0] =5;
    p[0][0] =6;
    p[0][0] =7;
    p[0][0] =8;                
    for (int i= 1;i < 8;i++) {
        for (int j= 1;j < 8;j++) {
            p[i][j] = p[i-1][7];
        }
    } 

for (int i = 1; i < 5;i++)
    for (int j = 0; j < 8; j++)
    {
        sum += p[8-i][j+j];
        sum -= p[8-i][j-i-1];
    }

    func(sum);
}



void piramid(int** p,int i , int j) {
    
}

int main(){
    string name;
    cin >> name;
    int vovels = func2(name);

    int **ptr = nullptr;
    ptr = new int*[5];
    for (int i =0; i < 3;i++) {
        ptr[i] = new int[vovels];
    }
    for (int i = 0;i <vovels - 1;i++) {
        ptr[0][i] = 20 + rand()%40;
    }
    for (int i = 0;i <vovels - 1;i++) {
        if (i%2 != 0) {//непарні
        ptr[1][i] = i;
        } else {
        ptr[1][i] = i + 1; 
        }
    }
    for (int i = 0;i < vovels - 1;i++) {
        if (name[i] == 'a' || name[i] == 'o' || name[i] == 'u' || name[i] == 'e' || name[i] == 'y' || name[i] == 'i'){
        ptr[2][i] = int(name[i]);        
        } 
}  
    for (int i= 0;i < 3;i++) {
            for (int j= 0;j < vovels - 1;j++) {
        cout << ptr[i][j] << " ";
    }
    cout << endl;
    }





    string surname;
    cin >> surname;
        int **pt = nullptr;
    pt = new int*[surname.length()];
    for (int i =0; i < surname.length() - 1;i++) {
        pt[i] = new int[surname.length()];
    }
int temp = 0;
    for (int i= 0;i < surname.length() - 1;i++) {
        for (int j= 0;j < surname.length() - 1;j++) {
            
            pt[i][j] = 1;

        }
    }
        for (int i= 0;i < surname.length() - 1;i++) {
        for (int j= 0;j < surname.length() - 1;j++) {
cout << pt[i][j];
        }
        cout << endl;
    }

func();





}









