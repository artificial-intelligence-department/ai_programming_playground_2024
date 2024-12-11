#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;
const int variant = 33;//цілочисельна константа

//не можна використовувати вектори

struct Student { //своя структуру даних
    string firstname;
    string lastname;
    float money;
};

class Node {
public:
    Student data;
    Node *next;
    Node *prev;

    Node(Student value) : data(value), next(nullptr), prev(nullptr) {};
};


class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {};
};


double function_1() {
    cout << "Function_1 begin" << endl;
    float a, b; //дійсна змінна
    cout << "Float a, b:";//оператори виведення та введення даних
    cin >> a >> b;//оператори виведення та введення даних
    int c, d, e;//цілочисельна змінна
    cout << "Int c, d, e:";
    cin >> c >> d >> e;
    double f;//дійсний з подвійною точністю змінна
    cout << "Double f:";
    cin >> f;
    double elements[6];
    elements[0] = a;
    elements[1] = b;
    elements[2] = c;
    elements[3] = d;
    elements[4] = e;
    elements[5] = f;

    for (int i = 0; i < 6; i++) {//for цикл 
        for (int j = i + 1; j < 6; j++) {
            if (elements[i] < elements[j]) //Сортування за зростанням
                swap(elements[i], elements[j]);
        }
    }
    double sum_max = elements[0] + elements[1] + elements[2];
    double sum_min = elements[3] + elements[4] + elements[5];
    double result;
    //cout<<sum_max<<" "<<sum_min<<endl;
    if (sum_max > sum_min * 4) result = sum_min + sum_max; //умовні оператори та розгалуження
    else if (sum_max > sum_min * 3) result = sum_max / sum_min;
    else //if(sum_max>sum_min*2)
        result = sum_max * sum_min;
    //else ???
    result /= variant;
    cout << "Function_1 result:" << result << endl;
    cout << "Function_1 end" << endl << endl;
    return result;
}

double **function_2(double &x) {//параметри та аргументи функції
    cout << "Function_2 begin" << endl;
    double **matrix = new double *[5];// двовимірний масив, вказівники
    for (int i = 0; i < 5; i++) {
        matrix[i] = new double[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + variant - i + j) * (rand() % 100 + 1);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Function_2 end" << endl << endl;
    return matrix;
}

double *functin_3(double **matrix) {
    cout << "Function_3 begin" << endl;
    double *array = new double[5];//одновимірний масив

    for (int i = 0; i < 5; i++) {        //Перший спосіб
        array[i] = matrix[0][i];
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[j] = min(array[j], matrix[i][j]);
        }
    }

    int i = 0;                 //Другий спосіб
    bool flag = true;
    while (i < 5) {
        double minn = pow(5, 10); // математичні операції та математичні функції (=1e5)
        int j = 0;
        do {//do while цикл
            minn = min(minn, matrix[j][i]);
            j++;
        } while (j < 5);//while цикл
        if (minn != array[i]) {
            flag = false;
            break;// break і continue
            }
        i++;
    }
    if (flag) cout << "Results are equal" << endl;
    else cout << "Results aren't equal" << endl;
    cout << "Function_3 end" << endl << endl;
    return array;
}

LinkedList function_4(double *array) {
    cout << "Function_4 begin" << endl;
    LinkedList list;
    Node *current = new Node({"Hgdfgdf", "Lwbndfd"});
    list.head = current;
    for (int i = 1; i < 7; i++) {
        Node *newNode = new Node({"A" + to_string(i + 100), "G" + to_string((i + 100) % 47)});
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (array[i] < array[j])           //за спаданням
                swap(array[i], array[j]);
        }
    }
    current = list.head;
    for (int i = 0; i < 7; i++) {
        if (i == 0) current->data.money = array[0];
        else if (i == 6) current->data.money = array[4];
        else current->data.money = array[i % 5] + array[i - 1];
        current = current->next;
    }

    current = list.head;
    while (current) {
        cout << current->data.firstname << " " << current->data.lastname << " " << current->data.money << endl;
        current = current->next;
    }
    cout << "Function_4 end" << endl << endl;
    return list;
}

void help_for_function_5(ofstream &file, Node *current) {
    file << current->data.firstname << " " << current->data.lastname <<" "<< current->data.money << endl;
}

void function_5(LinkedList list) {
    ofstream file("file.txt");//функції роботи з файлами, для того, щоб записати у файл
    Node *current = list.head;
    while (current) {
        help_for_function_5(file, current);
        current = current->next;
    }
    file.close();
}

void function_6() {
    cout << "Function_6 begin" << endl;
    ifstream file("file.txt");//функції роботи з файлами, для того, щоб зчитати з файлу
    string line;
    bool flag=false;
    while (getline(file,line)) {
        cout<<line<<endl;
        flag = true;
    }
    file.close();
    if(!flag) cout<<"File is empty or doesn't exist"<<endl;
    cout << "Function_6 end" << endl;
}

int main() {
    double x = function_1();

    double **tower = function_2(x);

    double *res_func_3 = functin_3(tower);

    LinkedList list = function_4(res_func_3);

    function_5(list);

    function_6();
}