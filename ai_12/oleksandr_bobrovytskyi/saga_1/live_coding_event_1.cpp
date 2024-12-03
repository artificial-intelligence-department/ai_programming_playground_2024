#include<bits\stdc++.h>

using namespace std;

const int MyVariant = 31;

struct ArrStruct
{
    double arr[5][5];
};

struct My1darr
{
	double Arr[5];
};

ArrStruct function_2(double x)
{
    ArrStruct var;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            var.arr[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            var.arr[i][j] += (MyVariant + j - i) * (rand() % 101);
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << var.arr[i][j] << " ";
        }
        cout << endl;
    }

    return var;
}

double function_1()
{
    float a, b;
    int c, d, e, count = 0;
    double f, sum1 = 0, sum2 = 0, result = 0;

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    set<double> st;

    st.insert(c);
    st.insert(d);
    st.insert(e);
    st.insert(f);
    st.insert(static_cast<double>(a));
    st.insert(static_cast<double>(b));

    for(double a : st)
    {
        if(count < 3)
        {
            sum1 += a;
        }
        else
        {
            sum2 += a;
        }

        count++;
    }

    if(sum2 > (sum1 * 2))
    {
        result = sum1 * sum2;
    }
    else if(sum2 > (sum1 * 3))
    {
        result = sum2 / sum1;
    }
    else if(sum2 > (sum1 * 4))
    {
        result = sum1 + sum2;
    }

    result = result / MyVariant;

    cout << result << endl;

    return result;
}

My1darr function_3(ArrStruct tower)
{
    My1darr arr1;
    My1darr arr2;
    double min = 100000000000; 

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tower.arr[j][i] < min)
            {
                min = tower.arr[j][i];
            }
        }
        arr1.Arr[i] = min;
    }

    for(int i = 0; i < 5; i++)
    {
        set<double> st;
        for(int j = 0; j < 5; j++)
        {
            st.insert(tower.arr[j][i]);
        }
        auto first = st.begin();
        arr2.Arr[i] = *first;
    }

    for(int i = 0; i < 5; i++)
    {
        if(arr1.Arr[i] == arr2.Arr[i])
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }

    return arr1;
}

int main()
{   
    double x = function_1();

    ArrStruct tower;
    tower = function_2(x);

    function_3(tower);

    return 0;
}