#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include "stdio.h"
using namespace std;

vector<int> NegativeNumbersElements(const vector<int>& array)
{
    vector<int> negatives;
    for (int num : array) 
    {
        if (num < 0) 
        {
            negatives.push_back(num);
        }
    }
    return negatives;
}

int countWords(const string& str)
{
    int count = 0;
    istringstream stream(str);  
    string word;
    while (stream >> word) 
    {
        if (word.front() == word.back()) 
        {
            count++; 
        }
    }

    return count;
}

void NewFunction(const vector<int>& negativeNumbers);

int main()
{

    vector<int> numbers = {1, 5, 7, 8, 16, 10, -15, -8, -32};
    vector<int> negativeNumbers = NegativeNumbersElements(numbers);
    for(int num : negativeNumbers)
    {
        cout << "Negative numders: " << num << endl; 
    }

    NewFunction(negativeNumbers);

    string text = "Львівська Політехніка один з найкращих ВНЗ України";
    int result = countWords(text);
    cout << "Words that start and finish with the same letter: " << result << endl;


    return 0;
}

void NewFunction(const vector<int>& negativeNumbers)
{
    cout << "Count of negative numbers: " << negativeNumbers.size() << endl;
}