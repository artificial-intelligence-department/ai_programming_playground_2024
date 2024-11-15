#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, M;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> a[i];
    }

    cin >> M;

    vector<int> b(M);
    for (int i = 0; i < M; i++) 
    {
        cin >> b[i];
    }

    int count = 0;
    vector<int> elements;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (a[i] == b[j]) 
            {
                bool counted = false;
                for (int k = 0; k < elements.size(); k++) 
                {
                    if (elements[k] == a[i]) 
                    {
                        counted = true;
                        break;
                    }
                }
                if (!counted) 
                {
                    elements.push_back(a[i]);
                    count++;
                }
            }
        }
    }

    vector<int> unionElem = a;
    for (int i = 0; i < M; i++) 
    {
        bool unique = true;
        for (int j = 0; j < N; j++) 
        {
            if (b[i] == a[j]) 
            {
                unique = false;
                break;
            }
        }

        if (unique) 
        {
            unionElem.push_back(b[i]);
        }
    }

    cout << count << endl;
    cout << unionElem.size() << endl;

    return 0;
}
