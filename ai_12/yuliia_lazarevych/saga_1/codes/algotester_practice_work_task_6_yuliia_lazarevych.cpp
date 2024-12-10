//Менші зліва менші справа

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i = 0;
    cin >> n;

    vector<vector<int>> lr(n, vector<int>(2)); //двохвимірний масив для зберігання l та r
    vector<int> result(n, 0);

    while (i < n) { //використовую цикл while для зчитування l_i та r_i
        cin >> lr[i][0] >> lr[i][1];
        i++;
    }

    i = 0;
    while (i < n) { //цикл while для обчислення значень елементів масиву
        int count_left = lr[i][0];
        int count_right = lr[i][1];
        int value = count_left + count_right + 1;
        result[i] = value;
        i++;
    }

    i = 0;
    while (i < n) {
        cout << result[i] << " ";
        i++;
    }
    cout << endl;

    return 0;
}
