#include <iostream>
#include <string>
#include <vector>

using namespace std;

double find_average(vector<vector<double>>& mas1, int x){
    double resault = 0;
    for(int i = 0; i < x; i++){
        resault += mas1[i][0];
    }
    resault /= x;
    return resault;
}

void average_compare(vector<vector<double>>& mas1, int x, int y, double average1){
    int count = 0;
    for(int k = 1; k < y; k++){
        for(int i = 0; i < x; i++){
            if(mas1[i][k] > average1){
                count++;
            }
            if(i == x - 1){
                cout << "In " << k + 1 << "row: " << count << endl;
                count = 0;
            }
        }   
    }
}

int main(){
    
    int a,b;
    cin >> a >> b;
    vector<vector<double>> mas(a, vector<double>(b));
    double average = 0;
    int count = 0;
    for(int i = 0; i < a; i++){
        for(int k = 0; k < b; k++){
            cin >> mas[i][k];
        }   
    }
    
    average = find_average(mas, a);
    
    cout << "Average: " << average << endl;
    
    average_compare(mas, a, b, average);
    
    return 0;
}