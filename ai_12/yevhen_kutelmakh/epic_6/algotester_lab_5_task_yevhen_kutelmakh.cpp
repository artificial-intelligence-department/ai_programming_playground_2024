#include <iostream>
#include <algorithm>
using namespace std;

bool check(char *col, int N) {
    for(int i = 0; i < N - 1; i++) {
        if(col[i] == 'S' && col[i+1] == 'O') return false;
    }
    return true;
}

void dochanges(char *col,int N) {
    auto p = find(col, col + N, 'X');
    if(p == col + N) {
        int s = count(col, col + N, 'S');
        for(int i = N-1; i >= 0; i--) {
            if(s>0) {
                col[i] = 'S';
                s--;
            }
            else col[i] = 'O';
        }
    } else {
        while(!check(col, N)) {
            for(int i = 0; i < N - 1; i++) {
                if(col[i] == 'S' && col[i + 1] == 'O')
                    swap(col[i], col[i + 1]);
            }
        }
    }
}

void makeCols(char **arr,int N, int M) {
    for(int i = 0; i < M; i++) {
        char *col = new char[N];
        for(int j = 0; j < N; j++) {
            col[j] = arr[j][i];
        }
        dochanges(col, N);
        for(int j = 0; j < N; j++) {
            arr[j][i] = col[j];
        }
        delete[] col;
        col = nullptr;
    }
}

void print(char **arr, int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << "\n";
}

int main() {
    int N, M;
    cin >> N >> M;
    char **arr = new char*[N];
    cin.ignore(23421, '\n');
    for(int i = 0; i < N; i++) {
        arr[i] = new char[M+1];
        cin.getline(arr[i], M + 1);
    }
    makeCols(arr, N, M);
    print(arr, N);
    for(int i = 0; i < N; i++) {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
    return 0;
}