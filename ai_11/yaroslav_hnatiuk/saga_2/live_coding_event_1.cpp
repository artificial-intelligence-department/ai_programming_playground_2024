#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <fstream>
using namespace std;

int const variant = 5;

struct Node {
    string name;
    string surname;
    double balance;

    Node *next;
    Node *prev;

    Node(string a1, string a2, double a3, Node *a4, Node *a5) : name(a1), surname(a2), balance(a3), next(a4), prev(a5) {}
};

class LinkedList {
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        void appendElement(string userName, string userSurame, double money) {
            Node* current = head;

            if (current == nullptr) {
                head = new Node(userName, userSurame, money, nullptr, nullptr);
                tail = head;
            } else {
                tail->next = new Node(userName, userSurame, money, nullptr, tail);
                tail = tail->next;
            }
        }

        void printListCaller() {
            printList(head);
        }

        void printList(Node* current) {
            if (current == nullptr) return;
            cout << current->surname << " " << current->name << " " << current->balance << endl;
            printList(current->next);
            return;
        }

        Node *executeHead() {
            return head;
        }

        void deleteListCaller() {
            deleteList(head);
        }

        void deleteList(Node *current) {
            if (current == nullptr)
                return;
            deleteList(current->next);
            delete current;
            return;
        }
};

double function_1();
double** function_2(double& x);
double* function_3(double** matrix);
Node *function_4(double *arr);
void function_5(Node *listHead);
void function_6();

int main()
{
    double x = function_1();
    double** tower = function_2(x);
    double *arr = function_3(tower);
    Node *listHead = function_4(arr);
    function_5(listHead);
    cout << endl;
    function_6();

    for (int i = 0; i < 5; i++)
        delete[] tower[i];
    delete[] tower;
    delete[] arr;

    return 0;
}

double function_1() {
    float a, b;
    cin >> a >> b;

    int c, d, e;
    cin >> c >> d >> e;

    double f;
    cin >> f;

    double arr[6];

    arr[0] = static_cast<double>(a);
    arr[1] = static_cast<double>(b);
    arr[2] = static_cast<double>(c);
    arr[3] = static_cast<double>(d);
    arr[4] = static_cast<double>(e);
    arr[5] = f;

    sort(arr, arr + 6);

    double maxSum = arr[3] + arr[4] + arr[5];
    double minSum = arr[0] + arr[1] + arr[2];

    if (maxSum > minSum * 4) {
        return (maxSum + minSum) / variant;

    } else if (maxSum > minSum * 3) {
        return (maxSum / minSum) / variant;

    } else if (maxSum > minSum * 2) {
        return (maxSum * minSum) / variant;

    } else return 1;
}

double** function_2(double &x) {
    double **matrix = new double *[5];

    for (int i = 0; i < 5; i++) {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
            
        }
    }

    srand(time(nullptr));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + variant + j - i) * (rand() % 100) + 1;
        }
    }

    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return matrix;
}

double* function_3(double **matrix) {
    double *arr = new double[5];

    for (int i = 0; i < 5; i++) {
        double min = 1.0 / 0.0;
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] < min)
                min = matrix[j][i];
        }
        arr[i] = min;
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        double col[5];
        for (int j = 0; j < 5; j++) {
            col[j] = matrix[j][i];
        }

        double min = *min_element(col, col + 5);
        if (arr[i] == min)
            cout << "Yes" << " ";
        else
            cout << "No" << " ";
    }
    cout << endl << endl;

    return arr;
}

Node *function_4(double *arr) {
    LinkedList list;

    list.appendElement("Name1", "Surname1", *max_element(arr, arr + 5));

    double money = 0;
    for (int i = 0; i < 5; i++) {
        money += arr[i];
        string userName = "Name" + to_string(i + 2);
        string userSurname = "Surname" + to_string(i + 2);
        list.appendElement(userName, userSurname, money);
    }

    list.appendElement("Name7", "Surname7", *min_element(arr, arr + 5));

    list.printListCaller();

    return list.executeHead();
}

void help_for_function_5(string info) {
    FILE *file;
    file = fopen("students.txt", "a");

    char *row = new char[info.length()];

    for (int i = 0; i < info.length(); i++) {
        row[i] = info[i];
    }

    fprintf(file, row);
    fprintf(file, "\n");

    fclose(file);
}

void help_for_function_5(double info) {
    FILE *file;
    file = fopen("students.txt", "a");

    char *row = new char[to_string(info).length()];

    for (int i = 0; i < to_string(info).length(); i++) {
        row[i] = to_string(info)[i];
    }

    fprintf(file, row);
    fprintf(file, "\n\n");

    fclose(file);
}

void function_5(Node *listHead) {
    LinkedList list;

    Node *current = listHead;

    ofstream file("students.txt");
    file << "";
    file.close();

    for (int i = 0; i < 7; i++) {
        help_for_function_5(current->name);
        help_for_function_5(current->surname);
        help_for_function_5(current->balance);
        current = current->next;
    }

    list.deleteListCaller();
}

void function_6() {
    ifstream file("students.txt");

    if (!file) {
        cout << "Файла не існує";
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}
