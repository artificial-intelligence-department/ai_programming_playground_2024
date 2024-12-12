#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int VARIANT = 61;

double function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;
    double zeepzorp[6] = {a,b,c,d,e,f};
    sort(zeepzorp, zeepzorp + 6);
    double sum_biggest = zeepzorp[3]+zeepzorp[4]+zeepzorp[5];
    double sum_smallest = zeepzorp[0]+zeepzorp[1]+zeepzorp[2];
    double res = 0;
    if (sum_biggest > sum_smallest * 4) res = sum_biggest + sum_smallest;
    else if (sum_biggest > sum_smallest * 3) res = sum_biggest / sum_smallest;
    else if (sum_biggest > sum_smallest * 2) res = sum_biggest * sum_smallest;
    cout << res / VARIANT << endl;
    return res / VARIANT;
}

double ** function_2(double x)
{
    srand(time(0));

    double **matrix = new double *[5];
    for (int i = 0; i < 5; i++)
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
            break;
        }
    }
    cout << (equal ? "Equal" : "Not equal") << endl;
    delete[] mins2;
    return mins1;
}

struct Student 
{
    char *name;
    char *surname;
    double money;
};

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
    while (n)
    {
        cout << n->val->name << " " << n->val->surname << " " << n->val->money << endl;
        n = n->next;
    }
    return head;
}

void help_for_function_5(fstream *fs, Node *ll)
{
    Node *n = ll;
    while (n)
    {
        *fs << n->val->name << " " << n->val->surname << " " << n->val->money << endl;
        n = n->next;
    }
}

void function_5(Node *ll)
{
    fstream fs;
    fs.open("live_coding_1.dat", fstream::out | fstream::binary);
    help_for_function_5(&fs, ll);
}

void function_6()
{
    fstream fs;
    fs.open("live_coding_1.dat", fstream::in | fstream::binary);
    if (fs.fail())
    {
        cout << "Error when opening file" << endl;
        return;
    }
    char buf[300];
    while(fs.read(buf, 300)) ; // read all into buf
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