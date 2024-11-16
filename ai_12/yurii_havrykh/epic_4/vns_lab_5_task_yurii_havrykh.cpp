// Задано двовимірний масив. Знайти суму елементів першого стовпця без
// одного останнього елемента, суму елементів другого стовпця без двох
// останніх, суму елементів третього стовпця без трьох останніх і т.д. Останній
// стовпець не обробляється. Серед знайдених сум знайти максимальну.
#include<bits/stdc++.h>
using namespace std;

void print_matrix(int matrix[4][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

void max_column(int matrix[4][4]){
    int result=0;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3-i;j++){
            sum+=matrix[j][i];
        }
        result=max(result,sum);
    }
    cout<< result;
}

int main(){
    int matrix[4][4] = { {1,6,3,9}, {9,0,5,4} , {4,5,1,8}, {1,5,8,2} };
    print_matrix(matrix);
    max_column(matrix);
}