#include <iostream>
using namespace std;

void bubbleSort(int* array, int N){
    for (int step = 0; step < (N-1); ++step) {
    bool swapped = false;
    for (int i = 0; i < (N-step-1); ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main(){
    int N;
    cin >> N;
    int *array = new int[N];
    for(int i = 0; i<N; i++){
        cin >> array[i];
    }

    if(N==1){
        cout << 0;
        return 0;
    }

    bubbleSort(array, N);

    int tiredness = array[N-1] - array[0];
    tiredness = min(tiredness, array[N-2] - array[0]);
    tiredness = min(tiredness, array[N-1]-array[1]);

    cout << tiredness;
    return 0;
}

