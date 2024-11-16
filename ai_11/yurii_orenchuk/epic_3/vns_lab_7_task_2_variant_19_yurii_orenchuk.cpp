#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int minfinder(int size, int arr[]){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min) min = arr[i];
    }

    return min;
}

string minfinder(string text){
    string tmpWord = "";
    string minWord = "";
    istringstream stream(text);
    size_t minLength = numeric_limits<size_t>::max();

    while (stream >> text) { 
        if (text.length() < minLength) {
            minLength = text.length();
            minWord = text;
        }
    }
    return minWord;
}

int main(){
    int size;
    string sent;

    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];

    cout << "Enter array numbers: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int min = minfinder(size, arr);
    cout << "Minimum number in array: " << min << endl;


    cout << "Enter a sentence you'd like to check: ";
    cin.ignore();
    getline(cin, sent);
    string smallestWord = minfinder(sent);

    cout << "The smallest word is: " << smallestWord;

    return 0;
}