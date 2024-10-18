#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    // цікавий спосіб зробити перебір
    while(n--) {
        cin >> arr[n];
    }
    // вбудована функція для сортування
    sort(arr.begin(), arr.end());

    if(arr.size() == 1){
        cout << 0;
        return 0;
    }
    /*в залежності від того що є меншим виводить втому*/
    arr[arr.size() - 1] - arr[1] > arr[arr.size() - 2] - arr[0] ?  
    (cout << arr[arr.size() - 2] - arr[0]) : 
    (cout << arr[arr.size() - 1] - arr[1]);

    return 0;
}