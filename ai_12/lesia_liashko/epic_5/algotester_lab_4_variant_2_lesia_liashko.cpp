#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    std::cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    
    auto mod0_end = partition(arr.begin(), arr.end(), [](int x) { return x % 3 == 0; });
    auto mod1_end = partition(mod0_end, arr.end(), [](int x) { return x % 3 == 1; });
    auto mod2_end = arr.end(); 

    // Сортування 
    sort(arr.begin(), mod0_end);               // ост 0 за зр
    sort(mod0_end, mod1_end, greater<int>()); // ост 1 за сп
    sort(mod1_end, mod2_end);                  // ост2 за зр

    // Видалення повторень
    auto unique_end = unique(arr.begin(), arr.end());

    
    int resultSize = distance(arr.begin(), unique_end);
    cout << resultSize << "\n";
    for (auto it = arr.begin(); it != unique_end; ++it) 
    {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}
