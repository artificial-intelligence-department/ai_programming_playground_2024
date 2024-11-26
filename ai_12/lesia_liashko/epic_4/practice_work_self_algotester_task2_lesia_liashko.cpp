#include <iostream>
using namespace std;
struct Student 
    {
        string Name;
        string Sname;
        int Age;
        int Perfomance;
    };
int main (){
    int n;
    cout << "how many students?" << endl;
    cin >> n;
    Student st[n];
    cout << "writing.."<< endl;
    for (int i=0; i<n; i++ ){
        cin >>st[i].Name;
        cin >> st[i].Sname;
        cin >> st[i].Age;
        cin >> st[i].Perfomance;     
    }
    cout << "Who do you want to see?" << endl;
    int k;
    cin >> k;
    if (k>n){
        return 1;
    }else {
        cout << st[k-1].Name;
        cout << st[k-1].Sname;
        cout << st[k-1].Age;
        cout << st[k-1].Perfomance;       
    }
}