#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main (){

    string n;
    cin >> n;

    string max_num = n;
    sort(max_num.rbegin(), max_num.rend());//за спаданням

    string min_num = n;
    sort(min_num.begin(), min_num.end());//за зростанням

    if (min_num[0] == '0'){
        for (int i = 1; i < min_num.size(); i++){
            if (min_num[i] != '0'){
                swap (min_num[0], min_num[i]);
                break;
            }
        }
    }

    cout << min_num << " " << max_num << endl;

    return 0;
}
