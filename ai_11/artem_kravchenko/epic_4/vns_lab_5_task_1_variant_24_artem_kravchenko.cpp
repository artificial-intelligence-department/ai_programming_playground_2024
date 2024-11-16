#include <iostream>

using namespace std;

int process(const int masive[][3], int ryad, int stovp){
    int sum = 0;
    for (int i = 0; i < ryad && i < stovp; i++)
    {
        int diagonal = masive[i][i];
        for (int r = 0; r < ryad; r++)
        {
            for (int s = 0; s < stovp; s++)
            {
                if (masive[r][s] > diagonal)
                {
                    sum++;
                }
                
            }
            
        }
        
    }
    return sum;
}
int main(){
    const int ryad = 3;
    const int stovp = 3;
    int masive[ryad][stovp] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int result = process(masive, ryad, stovp);
    cout << "Результат: " << result << endl;
}