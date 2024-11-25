#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
int main(){
    int N;
    cin >> N;
    string a;
    vector <vector <int>> field(N);
    for(int i = 0; i < N; i++){
        cin >> a;
        for(int j = 0; j < N; j++){
            field[i].push_back(a[j] - '0');
        }
    }

    int Q;
    int x,y,count;
    vector <int> nums(N), result;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        iota(nums.begin(), nums.end(), 1);
        count = 0;
        result.clear();
        cin >> x >> y;
        if(field[x-1][y-1] != 0){
            cout << 1 << endl;
            cout << field[x-1][y-1];
        }
        else{
            for(int j = 0; j <N; j++){
                if(field[x-1][j] != 0){
                    nums[field[x-1][j] - 1] = 0;
                }
                if(field[j][y-1] != 0){
                    nums[field[j][y-1] - 1] = 0;
                }
            }
            for(int j : nums){
                if(j!=0){
                    count++;
                    result.push_back(j);
                }
            }
            cout << count << endl;
            for(int j : result){
                cout << j << ' ';
            }
        }
        cout << endl << endl;
    }
    return 0;
}