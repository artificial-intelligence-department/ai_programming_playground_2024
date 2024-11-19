// https://algotester.com/en/ArchiveProblem/DisplayWithEditor/20075#home
#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int* teeth_array = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> teeth_array[i];
    }
    
	int current_number = 0, maximum_number = 0;

    for (int i = 0; i < N; ++i) {
        if (teeth_array[i] >= K) {
            ++current_number;
            maximum_number = max(maximum_number, current_number);
        } else {
            current_number = 0;
        }
    }

    cout << maximum_number;

	delete[] teeth_array;
    
    return 0;
}

