#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, element;
    cin >> N;

    vector<int> firstSet;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        firstSet.push_back(element);
    }

    cin >> M;
    vector<int> secondSet;
    for (int i = 0; i < M; i++)
    {
        cin >> element;
        secondSet.push_back(element);
    }

    cout << endl;

    // Сортування множин
    sort(firstSet.begin(), firstSet.end());
    sort(secondSet.begin(), secondSet.end());

    // Різниця: N - M
    vector<int> difference1;
    set_difference(firstSet.begin(), firstSet.end(),
                   secondSet.begin(), secondSet.end(),
                   inserter(difference1, difference1.end()));
    cout << difference1.size() << endl;
    for (int value : difference1)
    {
        cout << value << " ";
    }
    cout << endl;

    // Різниця: M - N
    vector<int> difference2;
    set_difference(secondSet.begin(), secondSet.end(),
                   firstSet.begin(), firstSet.end(),
                   inserter(difference2, difference2.end()));
    cout << difference2.size() << endl;
    for (int value : difference2)
    {
        cout << value << " ";
    }
    cout << endl;

    // Перетин множин
    vector<int> intersection;
    set_intersection(firstSet.begin(), firstSet.end(),
                     secondSet.begin(), secondSet.end(),
                     inserter(intersection, intersection.end()));
    cout << intersection.size() << endl;
    for (int value : intersection)
    {
        cout << value << " ";
    }
    cout << endl;

    // Об'єднання множин
    vector<int> unionSet;
    set_union(firstSet.begin(), firstSet.end(),
              secondSet.begin(), secondSet.end(),
              inserter(unionSet, unionSet.end()));
    cout << unionSet.size() << endl;
    for (int value : unionSet)
    {
        cout << value << " ";
    }
    cout << endl;

    // Симетрична різниця
    vector<int> symmetricDifference;
    set_symmetric_difference(firstSet.begin(), firstSet.end(),
                              secondSet.begin(), secondSet.end(),
                              inserter(symmetricDifference, symmetricDifference.end()));
    cout << symmetricDifference.size() << endl;
    for (int value : symmetricDifference)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}