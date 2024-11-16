#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> number(N);
    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
    }
    int a, b, c;
    cin >> a >> b >> c;

    number.erase(remove(number.begin(),number.end(), a), number.end());
    number.erase(remove(number.begin(),number.end(), b), number.end());
    number.erase(remove(number.begin(),number.end(), c), number.end());

    vector<int> new_number;
    if (number.size() > 1)
    {
        for (size_t i = 0; i < number.size() - 1; i++)
        {
            new_number.push_back(number[i] + number[i+1]);
        }
        
    }
     cout << new_number.size() << endl;
     for (int sum : new_number)
     {
        cout << sum << " ";
     }
     cout << endl;
    
    return 0;
}