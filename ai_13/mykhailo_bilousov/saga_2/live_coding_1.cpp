#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int VARIANT = 61; // v4

double function_1()
{
    float a, b; // v2
    int c, d, e; // v1
    double f; // v3
    cin >> a >> b; // v18
    cin >> c >> d >> e;
    cin >> f;
    double zeepzorp[6] = {a,b,c,d,e,f}; // v6
    sort(zeepzorp, zeepzorp + 6);
    double sum_biggest = zeepzorp[3]+zeepzorp[4]+zeepzorp[5]; // v15
    double sum_smallest = zeepzorp[0]+zeepzorp[1]+zeepzorp[2];
    double res = 0;
    // v5
    if (sum_biggest > sum_smallest * 4) res = sum_biggest + sum_smallest;
    else if (sum_biggest > sum_smallest * 3) res = sum_biggest / sum_smallest;
    else if (sum_biggest > sum_smallest * 2) res = sum_biggest * sum_smallest;
    cout << res / VARIANT << endl; // v18
    return res / VARIANT;
}

double ** function_2(double x) // v14
{
    srand(time(0));

    double **matrix = new double *[5]; // v7
    for (int i = 0; i < 5; i++) // v10
    {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

double * function_3(double **tower)
{
    double *mins1 = new double[5];
    double *mins2 = new double[5];
    double *temp = new double[5];
    bool equal = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            temp[j] = tower[j][i];
        }
        sort(temp, temp+5);
        mins1[i] = temp[0];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            temp[j] = tower[j][i];
        }
        mins2[i] = *min_element(temp, temp+5);
    }
    for (int i = 0; i < 5; i++)
    {
        if (mins1[i] != mins2[i])
        {
            equal = 0;
            break; // v11
        }
    }
    cout << (equal ? "Equal" : "Not equal") << endl;
    delete[] mins2;
    return mins1;
}

struct Student 
{
    char *name; // v20
    char *surname;
    double money;
}; // v19

struct Node
{
    Student *val;
    Node *prev;
    Node *next;
};

char * random_name()
{
    char *res = new char[10];
    res[0] = rand() % 26 + 0x41;
    for (int i = 1; i < 10; i++)
    {
        res[i] = rand() % 26 + 0x61;
    }
    return res;
}

Node * function_4(double *mins)
{
    Node *head = new Node;
    Node *n = head;
    Node *prev;
    n->val = new Student {random_name(), random_name(), *max_element(mins, mins+5)};
    for (int i = 0; i < 5; i++)
    {
        prev = n;
        n = new Node {NULL, prev, NULL};
        prev->next = n;
        n->val = new Student {random_name(), random_name(), mins[i]};
    }
    prev = n;
    n = new Node {NULL, prev, NULL};
    prev->next = n;
    n->val = new Student {random_name(), random_name(), *min_element(mins, mins+5)};
    
    n = head;
    while (n) // v9
    {
        cout << n->val->name << " " << n->val->surname << " " << n->val->money << endl;
        n = n->next;
    }
    return head;
}

void help_for_function_5(fstream *fs, Node *ll)
{
    Node *n = ll;
    do
    {
        *fs << n->val->name << " " << n->val->surname << " " << n->val->money << endl;
        n = n->next;
    } while (n->next); // v8
}

void function_5(Node *ll)
{
    fstream fs;
    fs.open("live_coding_1.dat", fstream::out | fstream::binary); // v16
    help_for_function_5(&fs, ll);
}

void function_6()
{
    fstream fs;
    fs.open("live_coding_1.dat", fstream::in | fstream::binary); // v17
    if (fs.fail())
    {
        cout << "Error when opening file" << endl;
        return;
    }
    char buf[300];
    while(fs.read(buf, 300)) ; // read all into buf until eofbit is set
    cout << buf << endl;
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *mins = function_3(tower);
    Node *ll = function_4(mins);
    function_5(ll);
    function_6();
}