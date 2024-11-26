#include <iostream>
using namespace std;

int main(){

    int N, M;
    cin >> N;
    int *array1 = new int[N];
    for(int i=0; i<N; i++){
        cin >> array1[i];
    }
    cin >> M;
    int *array2 = new int[M];
    for(int i=0; i<M; i++){
        cin >> array2[i];
    }

    int both_arrays = 0, unique = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (array1[i]==array2[j]){
                both_arrays++;
                break;
            }
        }
    }
    unique = N + M - both_arrays;
    cout << both_arrays << endl << unique;

    delete[] array1;
    delete[] array2;

    return 0;
}
