#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

const int var = 12;

class Node {
public:
    string name;
    string surname;
    double bankAccount;
    Node* next;
    Node* prev;

    Node(string content, string surnContent, double value) {
        name = content;
        surname = surnContent;
        bankAccount = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int index, int count, string nameContents[], string surnContents[], double values[]);
    void print();
    void get(int index, string &name1, string &surname1, double &bankAccount1);

    Node* head;
    Node* tail;
    int size;
};

void LinkedList::insert(int index, int count, string nameContents[], string surnContents[], double values[]) {
     if (index == 0) { 
        for (int i = count - 1; i >= 0; i--) {
            Node* newNode = new Node(nameContents[i], surnContents[i], values[i]);
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) { 
                tail = newNode;
            }
            size++;
        }
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    for (int i = 0; i < count; i++) {
        Node* newNode = new Node(nameContents[i], surnContents[i], values[i]);
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        size++;
    }
}

void LinkedList::print() {
    Node* current = head;
    while (current) {
        cout << current->name << " " << current->surname << " " << current->bankAccount << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::get(int index, string &name1, string &surname1, double &bankAccount1) {
    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    name1 = current->name;
    surname1 = current->surname;
    bankAccount1 = current->bankAccount;
}

double function_1 (double x) {
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b >> c >> d >> e >> f;
    
    double max1, max2, max3, min1, min2, min3;

    max1 = -99999999;
    max2 = -99999999;
    max3 = -99999999;
    min1 = 99999999;
    min2 = 99999999;
    min3 = 99999999;

    double numbers[6] = {a, b, c, d, e, f};

    for (int i = 0; i < 6; i++) {
        if (max1 < numbers[i]) {
            max1 = numbers[i];
        }

        if (min1 > numbers[i]) {
            min1 = numbers[i];
        }

    }

    for (int i = 0; i < 6; i++) {
        if (max2 < numbers[i] && numbers[i] < max1) {
            max2 = numbers[i];
        }

        if (min2 > numbers[i] && numbers[i] > min1) {
            min2 = numbers[i];
        }
    }

    for (int i = 0; i < 6; i++) {
        if (max3 < numbers[i] && numbers[i] < max1 && numbers[i] < max2) {
            max3 = numbers[i];
        }

        if (min3 > numbers[i] && numbers[i] > min1 && numbers[i] > min2) {
            min3 = numbers[i];
        }
    }

    double sumMax = max1 +  max2 + max3;
    double sumMin = min1 + min2+ min3;
    double result;
    
    if (sumMax > sumMin*2 && sumMax < sumMin*3) {
        result = sumMax*sumMin;
    }

    if (sumMax > sumMin*3 && sumMin*4 > sumMax) {
        result = sumMax/sumMin;
    }

    if (sumMax > sumMin*4) {
        result = sumMax + sumMin;
    }
    
    x = result/(double)var;

    return x;
}

void function_2 (double& x, double arr[][5]) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = x;
        }
    }

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = (x + var + j - i)*(1 + rand() % 99);
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void function_3 (double arr[][5], double row[5]) {
    double MinValuesRow[5];
    double MinValuesRow2[5];
    double MinValue = 99999999;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (MinValue > arr[i][j]) {
                MinValue = arr[i][j];
            }
        }
        MinValuesRow[i] = MinValue;
    }

    MinValue = 99999999;

    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            if (MinValue > arr[i][j]) {
                MinValue = arr[i][j];
            }
        }
        MinValuesRow2[i] = MinValue;
    }

    bool equals = true;

    for (int i = 0; i < 5; i++) {
       if (MinValuesRow[i] != MinValuesRow2[i]) {
            equals = false;
       }
    }

    if (!equals) {
        cout << "Two algorithms gave different results\n";
    }
    else {
        cout << "Both algorithms gave the same result\n";
    }

    for (int i = 0; i < 5; i++) {
        cout << MinValuesRow[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        row[i] = MinValuesRow[i];
    }

}

LinkedList function_4 (double arr[5], LinkedList kist) {
    struct Student
    {
        string name;
        string surname;
        double bankAccount;
    };

    Student s1, s2, s3, s4, s5, s6, s7;

    string nameVariants[] = {"GOOOleg", "Hleb", "Dryuha", "Sanchous", "Plashka", "Garik", "Goy"};
    string surnameVariants[] = {"Goychenkov", "HARAMilo", "Jewchenko", "Neojid", "Baked", "Esdabes", "Stecenko"};

    srand(time(0));

    s1.name = nameVariants[rand() % 6];
    s2.name = nameVariants[rand() % 6];
    s3.name = nameVariants[rand() % 6];
    s4.name = nameVariants[rand() % 6];
    s5.name = nameVariants[rand() % 6];
    s6.name = nameVariants[rand() % 6];
    s7.name = nameVariants[rand() % 6];

    s1.surname = surnameVariants[rand() % 6];
    s2.surname = surnameVariants[rand() % 6];
    s3.surname = surnameVariants[rand() % 6];
    s4.surname = surnameVariants[rand() % 6];
    s5.surname = surnameVariants[rand() % 6];
    s6.surname = surnameVariants[rand() % 6];
    s7.surname = surnameVariants[rand() % 6];

    
    double min = 99999999;
    double max = -99999999;

    for (int i = 0; i < 5; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    
    s1.bankAccount = max;
    s7.bankAccount = min;
    s2.bankAccount = arr[0];
    s3.bankAccount = s2.bankAccount + arr[1];
    s4.bankAccount = s3.bankAccount + arr[2];
    s5.bankAccount = s4.bankAccount + arr[3];
    s6.bankAccount = s5.bankAccount + arr[4];

    string names[7] = {s1.name, s2.name, s3.name, s4.name, s5.name, s6.name, s7.name};
    string surnames[7] = {s1.surname, s2.surname, s3.surname, s4.surname, s5.surname, s6.surname, s7.surname};
    double bankAccounts[7] = {s1.bankAccount, s2.bankAccount, s3.bankAccount, s4.bankAccount, s5.bankAccount, s6.bankAccount, s7.bankAccount};

    kist.insert(0, 7, names, surnames, bankAccounts);
    kist.print();

    return kist;
} 

void help_for_function_5 (ofstream* file, LinkedList list, int i = 6) {
    if (i < 0) {
        file->close();
        return;
    }

    string tempName;
    string tempSurname;
    double tempMoney;
    list.get(i, tempName, tempSurname, tempMoney);

    string line = tempName + tempSurname + to_string(tempMoney);
    int n = line.length();
    char* chrLine = new char[n + 1];
    auto first = line.begin();
    auto last = line.end();

    copy(first, last, chrLine);

    file->seekp(0, ios::end);
    file->write(chrLine, strlen(chrLine));

    delete[] chrLine;


    help_for_function_5(file, list, i - 1);
    
}

void help_for_function_5 (LinkedList list, int i = 7) {
    if (i < 0) {
        return;
    }

    ofstream file("LIST_IN_FILE.txt", ios::binary);

    string tempName;
    string tempSurname;
    double tempMoney;
    list.get(i, tempName, tempSurname, tempMoney);

    string line = tempName + tempSurname + to_string(tempMoney);
    int n = line.length();
    char* chrLine = new char[n + 1];
    auto first = line.begin();
    auto last = line.end();

    copy(first, last, chrLine);

    file.seekp(0, ios::end);
    file.write(chrLine, strlen(chrLine));

    delete[] chrLine;


    help_for_function_5(list, i - 1);

    file.close();
    
}

void function_5 (LinkedList kist) {
    ofstream outFile("LIST_IN_FILE.txt", ios::binary);
    if (!outFile) {
        cerr << "unable to open file for writing";
    }

    help_for_function_5(&outFile, kist);

    ifstream readFile("LIST_IN_FILE.txt", ios::binary);

    char* chrLine = new char[1024];

    while (readFile.read(chrLine, strlen(chrLine)) || readFile.gcount() > 0) {
        cout << chrLine;
    }

    readFile.close();

} 

int main () {
    double x = 0;
    x = function_1(x);
    double tower[5][5];
    function_2(x, tower);
    double ass[5];
    function_3(tower, ass);
    LinkedList list;
    list = function_4(ass, list);
    function_5(list);




    
    return 0;
}
// i identify as kilometers per second because i want to km/s