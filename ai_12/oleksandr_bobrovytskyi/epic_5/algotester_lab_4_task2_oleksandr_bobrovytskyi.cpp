#include<bits/stdc++.h>

using namespace std;

vector<int> Difference(vector<int> v1, vector<int> v2)
{
    vector<int> result;

    for(int i = 0; i < v1.size(); i++)
    {
        auto FindPosition = find(v2.begin(), v2.end(), v1[i]);
        if(FindPosition == v2.end())
        {
            result.push_back(v1[i]);
        }
        else
        {
            *FindPosition = -1;
        }
    }

    sort(result.begin(), result.end());

    return result;
}

vector<int> ArrayIntersection(vector<int> v1, vector<int> v2)
{
    vector<int> result;

    for(int i = 0; i < v1.size(); i++)
    {
        auto FindPosition = find(v2.begin(), v2.end(), v1[i]);
        if(FindPosition != v2.end())
        {
            result.push_back(v1[i]);
            *FindPosition = -1;
        }
    }

    sort(result.begin(), result.end());

    return result;
}

vector<int> ArrayUnion(vector<int> v1, vector<int> v2, vector<int> v3)
{   
    v1.insert(v1.begin(), v2.begin(), v2.end());

    v1.insert(v1.begin(), v3.begin(), v3.end());

    sort(v1.begin(), v1.end());

    return v1;
}

vector<int> SymmetricDifference(vector<int> v1, vector<int> v2)
{
    v1.insert(v1.begin(), v2.begin(), v2.end());

    sort(v1.begin(), v1.end());

    return v1;
}

int main()
{
    int n, m;
    cin >> n;
    if(n < 1 || n > 100)
    {
        return 1;
    }
    
    vector<int> num1(n);

    for(int i = 0; i < n; i++)
    {
        cin >> num1[i];
        if(num1[i] < 1 || num1[i] > 100)
        {
            return 1;
        }
    }

    sort(num1.begin(), num1.end());

    cin >> m;
    if(m < 1 || m > 100)
    {
        return 1;
    }
    vector<int> num2(m);

    for(int i = 0; i < m; i++)
    {   
        cin >> num2[i];
        if(num2[i] < 1 || num2[i] > 100)
        {
            return 1;
        }
    }

    sort(num2.begin(), num2.end());

    vector<int> Intersection = ArrayIntersection(num1, num2);
    vector<int> N_M_difference = Difference(num1, num2);
    vector<int> M_N_difference = Difference(num2, num1);
    vector<int> Union = ArrayUnion(N_M_difference, M_N_difference, Intersection);
    vector<int> XOR = SymmetricDifference(N_M_difference, M_N_difference);

    cout << N_M_difference.size() << endl;
    for(int i : N_M_difference)
    {
        cout << i << " ";
    }
    cout << "\n\n";


    cout << M_N_difference.size() << endl;
    for(int i : M_N_difference)
    {
        cout << i << " ";
    }
    cout << "\n\n";


    cout << Intersection.size() << endl;
    for(int i : Intersection)
    {
        cout << i << " ";
    }
    cout << "\n\n";
    
    cout << Union.size() << endl;
    for(int i : Union)
    {
        cout << i << " ";
    }
    cout << "\n\n";

  cout << XOR.size() << endl;
    for(int i : XOR)
    {
        cout << i << " ";
    }

    return 0;
}
