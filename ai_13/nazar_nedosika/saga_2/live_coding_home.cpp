#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
const int var = 74;

float function_1(){
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b >> c >> d >> e >>f;

    float matrix[6] = {a, b, static_cast<int>(c), static_cast<int>(d), static_cast<int>(e), static_cast<double>(f)};
    int size = 6;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1 ; j > i; j--)
        {
            if (matrix[j] < matrix[j - 1])
            {
                swap(matrix[j], matrix[j - 1]);
            }
        }
    }

    float minSum = matrix[0] + matrix[1] + matrix[2];
    float maxSum = matrix[3] + matrix[4] + matrix[5];
    float result;

    if (maxSum > minSum * 4)
    {
       result = maxSum + minSum;
    }
    else if(maxSum > minSum * 3){
        result = maxSum / minSum;
    }
    else if(maxSum > minSum * 2){
        result = maxSum * minSum;
    }
    
    float answer = result / var;
    cout << "Відповідь: " << answer << endl;
    return answer;
}

void function_2(double& x, double matrix[5][5]){
    srand(time(0));

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            matrix[i][j] = (matrix[i][j] + var + j - i) * (rand() % 100 + 1);
        }
    }

    cout << "Матриця: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }   
        cout << endl;
    }
}

void function_3(double matrix[5][5], double result[5]){
    for (int j = 0; j < 5; ++j)
    {
        double min_value_1 = matrix[0][j];
        for (int i = 1; i < 5; ++i)
        {
            if (matrix[i][j] < min_value_1)
            {
                min_value_1 = matrix[i][j];
            }
        }

        double min_value_2 = matrix[0][j];
        for (int i = 0; i < 5; ++i)
        {
            for (int k = i + 1; k < 5; ++k)
            {
                if (matrix[k][j] < matrix[i][j])
                {
                    swap(matrix[k][j], matrix[i][j]);
                }
                min_value_2 = matrix[0][j];
            }
        }

        if (min_value_1 == min_value_2){
            cout << "Результати збігаються для стовця " << j << endl;
        }
        else{
            cout << "Результати не збігаються";
            break;
        }
        result[j] = min_value_1;
    }
}

struct Student{
    string firstName;
    string lastName;
    double balance;
};

struct Node{
    Student data;
    Node* next;
    Node* prev;
};

Node* function_4(double result[5]){
    string firstNames[] = {"Nazar", "Jared", "Jahseh", "Jordan", "Symere" ,"Thiago", "Neymar"};
    string lastNames[] = {"Nedosika", "Higgins", "Onfroy", "Carter", "Woods" ,"Silva", "Junior"};

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 7; ++i)
    {
        double money;
        if (i == 0){
            money = result[4];
        }
        else if(i > 0 && i < 6){
            money = result[i - 1];
        }
        else{
            money = result[0];
        }

        Student student = {firstNames[i], lastNames[i], money};
        Node* newNode = new Node{student, nullptr, nullptr};

        if(!head) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    Node* current = head;
    cout << "Список студентнів: " << endl;
    while (current){
        cout << current->data.firstName << " " << current->data.lastName << " " << current->data.balance << " грн"<< endl;
        current = current->next;
    }

    return head;
}

void help_for_function_5(Node* node, ofstream& file){
    if(!node) return;
    help_for_function_5(node->next, file);
    file << node->data.firstName << " " << node->data.lastName << " " << node->data.balance << " грн" << endl;
}

void function_5(Node* head){
    ofstream file("students.txt");
    if (!file)
    {
        cerr << "Помилка відкриття файлу";
        return;
    }

    help_for_function_5(head, file);
    file.close();
    cout << "Список збережено у файл" << endl;

    ifstream inputFile("students.txt");
    if(!inputFile){
        cerr << "Помилка відкриття файлу";
        return;
    }

    cout << "Вміст файлу: " << endl;
    string line;
    while(getline(inputFile, line)){
        cout << line << endl;
    }
    inputFile.close();
}

int main(){
    double x = function_1();
    double matrix[5][5];
    cout << endl;

    function_2(x, matrix);
    double tower[5];
    function_3(matrix, tower);
    cout << endl;
    
    cout << "Одновисірний масив: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << tower[i] << " ";
    }
    cout << endl;
    cout << endl;

    Node* studentList = function_4(tower);

    cout << endl;

    function_5(studentList);

    return 0;
}