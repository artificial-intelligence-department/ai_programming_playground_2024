#include <iostream>

using namespace std;
int main(){
    long long n;
    cout << "Введіть кол-во пачок:" << endl;
    cin >> n; 
    cout << "Введіть печиво в пачках:" << endl;
    long long eat = 0;
    for (long long i = 0; i < n; i++) {
        long long a;
        
        cin >> a;
        if (a > 1) {

            eat += (a - 1);
        }
    }

        cout << "Можна зісти:" << " ";
        cout << eat;
        return 0;
} // algotester link https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/2
// link to photo https://i.imgur.com/bZQJZ3P.png