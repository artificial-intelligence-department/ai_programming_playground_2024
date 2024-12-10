#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string str ="23,574,35,21,21,352";
    vector<int> v;
    stringstream ss(str);

    for(int i; ss >> i; ){
        v.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }

    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

// int this code we define integers in string