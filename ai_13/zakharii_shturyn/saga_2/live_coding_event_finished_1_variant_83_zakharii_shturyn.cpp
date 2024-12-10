// доробити зайняло 40 хв
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

string filename = "test.txt";

struct Person
{
    string firstName;
    string lastName;
    double moneycount;

};

class Node {
public:
    Person data;
    Node* next;
    Node* prev;

    Node(Person value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(Person me) {
        Node* newNode = new Node(me);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* tmp = head;
        while(tmp != nullptr) {
            cout << tmp->data.firstName << " " <<tmp->data.lastName <<  " " << tmp->data.moneycount << " ";
            tmp = tmp->next;
            cout << endl;
        }
    }

    void help_for_function_5() {
        ofstream myFile(filename, ios::out);
        if (myFile.is_open()) {
            Node* tmp = head;
            while(tmp != nullptr) {
                myFile << tmp->data.firstName << " " <<tmp->data.lastName <<  " " << tmp->data.moneycount << endl;
                tmp = tmp->next;
            }
        }
        myFile.close();
        cout << endl;
    }

};



double function_1() {
    double a,b;
    int c,d,e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << endl;
    double arr[6] = {a,b,double(c),double(d),double(e),f};

    sort(arr, arr + 6);

    double biggersum = arr[3] + arr[4] + arr[5];
    double smallersum = arr[0] + arr[1] + arr[2];
    double res = 0;

    if(biggersum > smallersum * 4) {
        res = biggersum* smallersum;
    } else if(biggersum > smallersum * 3) {
        if(smallersum != 0) {
            res = biggersum / smallersum;
        } else {
            cout << "Ділення на нуль недоступне" << endl;
        }
    } else if(biggersum > smallersum * 2) {
        res = biggersum + smallersum;
    } else {
        cout << "Не задовільняється жодна з умов" << endl;
    }


    res /= 83;

    return res;
}

double** function_2(double x) {

    double** array2D = 0;
      array2D = new double*[5];
    
      for (int h = 0; h < 5; h++)
      {
            array2D[h] = new double[5];
    
            for (int w = 0; w < 5; w++)
            {
                  array2D[h][w] = x;
            }
      }

    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            array2D[i][j] = (array2D[i][j] + 83 + j + i) * (rand() % 100 + 1);
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    return array2D;
}

double* function_3(double** tower) {
    double arr[5];
    double* arr1min = new double[5];
    double* arr2min = new double[5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            arr[j] = tower[j][i];
        }
        sort(arr, arr + 5);
        arr1min[i] = arr[0];

        sort_heap(arr, arr + 5);
        arr2min[i] = arr[0];
    }
    bool isEqual = true;
    for(int i = 0; i < 5; i++) {
        if(arr1min[i] != arr2min[i]) {
            isEqual = false;
        }
    }
    if(isEqual) {
        cout << "Масиви однакові" << endl;
    } else {
        cout << "Масиви різні" << endl;
    }

    return arr1min;
}

LinkedList function_4(double* tmp) {
    LinkedList list;
    sort(tmp, tmp + 5);
    Person me;
    me.firstName = "Zahar";
    me.lastName = "Shturyn";
    me.moneycount = tmp[4];
    list.insert(me);

    int sum = 0;
    string firstnames[5] = {"Angelina", "Alina", "Vlad", "Milana", "Makar"};
    string lastnames[5] = {"Bobrynok", "Hodatska", "Murashko", "Sachatska", "Kuznecov"};
    for(int i = 0; i < 5; i++) {
        sum += tmp[i];
        me.firstName = firstnames[i];
        me.lastName = lastnames[i];
        me.moneycount = sum;
        list.insert(me);

    }

    me.firstName = "Anton";
    me.lastName = "Tsymbaluk";
    me.moneycount = tmp[0];
    list.insert(me);

    list.print();

    return list;
}

void function_5(LinkedList list) {
    list.help_for_function_5();
}

void function_5() {
    ifstream myFile(filename, ios::in);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Person newPerson;
            istringstream lineStream(line);
            lineStream >> newPerson.firstName >> newPerson.lastName >> newPerson.moneycount;
            cout << newPerson.firstName << " " << newPerson.lastName << " " << newPerson.moneycount << " " << endl;
        }
        myFile.close();
    } else {
        cout << "File not exist" << endl;
    }
}


int main() {

    double x = function_1();
    cout << endl;
    double** tower = function_2(x);
    cout << endl;
    double* tmp = function_3(tower);
    cout << endl;
    LinkedList res = function_4(tmp);
    function_5(res);
    function_5();

    return 0;
}