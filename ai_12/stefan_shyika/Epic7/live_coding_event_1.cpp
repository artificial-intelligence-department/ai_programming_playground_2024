#include <iostream>
#include <random>
#include <string>

using namespace std;

struct Student {
    string name;
    string surname;
    float balance;
    Student* next;
    Student* prev;
};


float min_element(float arr[], int n){
  // if size = 0 means whole array has been traversed
  if (n == 1) return arr[0];
  return min(arr[n-1], min_element(arr, n-1));
}

float function_1() {
    float a,b;
    int c,d,e;
    double f;
    cout << "intput 2 floats: ";
    cin >> a >> b;
    cout << endl << "input 3 ints: ";
    cin >> c >> d >> e;
    cout << endl << "input a double: ";
    cin >> f;

    double arr[] = {(double)a, (double)b, (double)c, (double)d, (double)e, f};

    // bubble sort
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    double largeSum = 0;
    double smallSum = 0;
    cout << "the largest 3: ";
    for (int i = 0; i < 3; i++) {
        largeSum += arr[i];
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "the smallest 3: ";
    for (int i = 3; i < 6; i++) {
        smallSum += arr[i];
        cout << arr[i] << " ";
    }

    double x;
    if(largeSum > smallSum * (double)2.0) {
        x = largeSum * smallSum;
    } else if (largeSum > smallSum * (double)3.0) {
        x = largeSum / smallSum;
    } else if (largeSum > smallSum * (double)4.0) {
        x = largeSum + smallSum;
    }
    const int variant = 58;
    x = x / (double)variant;
    cout << endl << x << endl;
    return (float)x;

}

    float** function_2(int x) {
        float** matrix = new float*[5];
        for(int i = 0; i < 5; i++) {
            matrix[i] = new float[5];
        }
        for (int i  = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrix[i][j] = 5;
            }
        }

        random_device rd; 
        mt19937 gen(rd()); 
        uniform_int_distribution<> distr(1, 100);
        int const variant = 58;
        cout << "matrix: ";
        for (int i  = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrix[i][j] = (matrix[i][j] + (float)variant + (float)i - (float)j) * (float)distr(gen);
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return matrix;
    }

    float* function_3(float** matrix) {
        float* arr = new float[5];
        for (int i  = 0; i < 5; i++) {
            float min1 = INT_MAX;
            float min2 = INT_MAX;
            float arrForMin2[5];
            for(int j = 0; j < 5; j++) {
                if(matrix[j][i] < min1) {
                    min1 = matrix[j][i];
                }
                arrForMin2[j] = matrix[j][i];
            }
            min2 = min_element(arrForMin2, 5);
            if (min1 = min2){
                cout << "equals" << endl;
            } else {
                cout << "does not equal" << endl;
            }
            arr[i] = min1;
        }
        return arr;       
    }

    Student* function_4(float* arr) {
        Student* head = new Student{"S1", "S1", 12.0};
        head->next = new Student{"S2", "S2", 2.0};
        head->prev = nullptr;

        head->next->next = new Student{"S3", "S3", 3.0};
        head->next->prev = head->next;

        head->next->next->next = new Student{"S4", "S4", 4.0};
        head->next->next->prev = head->next->next;
        return head;
    }
     // ПОЧАЛАСЯ ТРИВОГА КОМЕНТИ НЕ ВСТИГ

int main() {
    float x = function_1();
    float** matrix = function_2(x);
    float* arr = function_3(matrix);
}