#include<bits/stdc++.h>

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

struct student
{
    string name;
    string surname;
    double balance;
};

struct Node
{
    student data;
    Node *next;
    Node *prev;

    Node(student s) : data(s), next(nullptr), prev(nullptr) {}
};
 
class DoublyLL
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLL() : head(nullptr), tail(nullptr){}

    Node *GetNode()
    {
        return head;
    }

    void AddToEnd(student s)
    {
        Node *NewNode = new Node(s);
        if(!head)
        {
            head = tail = NewNode;
            tail->next = nullptr;
        }
        else
        {
            tail->next = NewNode;
            NewNode->prev = tail;
            tail = NewNode;
            tail->next = nullptr;
        }
    }

    void PrintLL()
    {   
        if(!head)
        {
            return;
        }

        Node *temp = head;
        while(temp)
        {
            cout << temp->data.name << " " << temp->data.surname << " " <<temp->data.balance << " " << endl; 
            temp = temp->next;
        }
    }
};

DoublyLL function_4(My1darr arr)
{
    double balance[5];
    double min, sum = 0;
    double max; 

    for(int i = 0; i < 5; i++)
    {
        max = -1;
        min = 1e10;
        if(arr.Arr[i] > max)
        {
            max = arr.Arr[i];
        }

        
        if(arr.Arr[i] < min)
        {
            min = arr.Arr[i];
        }

        sum += arr.Arr[i];

        balance[i] = sum;
    }

    DoublyLL DLL;

    DLL.AddToEnd({"John", "Smith", max});
    DLL.AddToEnd({"Alice", "Cooper", balance[0]});
    DLL.AddToEnd({"Mike", "Jordan", balance[1]});
    DLL.AddToEnd({"Joe", "Biden", balance[2]});
    DLL.AddToEnd({"James", "Jameson", balance[3]});
    DLL.AddToEnd({"Marta", "Cameron", balance[4]});
    DLL.AddToEnd({"Jane", "Doe", min});

    DLL.PrintLL();

    return DLL;
}

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

    if(sum2 > (sum1 * 4))
    {
        result = sum1 + sum2;
    }
    else if(sum2 > (sum1 * 3))
    {
        result = sum2 / sum1;
    }
    else if(sum2 > (sum1 * 2))
    {
        result = sum1 * sum2;
    }

    result = result / MyVariant;

    cout << result << endl;

    return result;
}

My1darr function_3(ArrStruct tower)
{
    My1darr arr1;
    My1darr arr2;
    double min; 

    for(int i = 0; i < 5; i++)
    {   
        min = 1e10;
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

    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        if(arr1.Arr[i] == arr2.Arr[i])
        {
            count++;
        }
    }

    if(count == 5)
    {
        cout << "Values are equal \n";
    }
    else
    {
        cout << "Values are not equal \n";
    }

    return arr1;
}

void help_for_function_5(ofstream &file, string s)
{
    file << s << " ";
}

void help_for_function_5(ofstream &file, double d)
{
    file << d << " ";
}

void function_5(DoublyLL DLL)
{
    ofstream file;

    file.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/list.txt");

    Node *temp = DLL.GetNode();
    while(temp)
    {
        help_for_function_5(file, temp->data.name);
        help_for_function_5(file, temp->data.surname);
        help_for_function_5(file, temp->data.balance);
        temp = temp->next;
        file << endl;
    }

    file.close();
}

void function_6()
{
    ifstream file;
    file.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/list.txt");

    string s;

    while(getline(file, s))
    {
        cout << s << endl;
    }

    file.close();
}

int main()
{   
    double x = function_1();

    ArrStruct tower;
    tower = function_2(x);

    My1darr arr;
    arr = function_3(tower);

    DoublyLL DLL = function_4(arr);

    function_5(DLL);

    function_6();

    return 0;
}