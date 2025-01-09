#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int variant = 13;

double function_1(){
    int c, d, e;
    double a, b, f;

    cin >> a >> b;
    cin >> c >> d >> e ;
    cin >> f;

    double numbers[6] = {a, b, f};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                double current = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers [j + 1] = current;
            }
            
        }
   
    } 

    double naymenshi_sum = numbers[0] + numbers[1] + numbers[2];
    double naybilshi_sum = numbers[3] + numbers[4] + numbers[5];

    double result;

    if (naybilshi_sum > naymenshi_sum * 4)
    {
        result = naybilshi_sum + naymenshi_sum;
    }else if (naybilshi_sum > naymenshi_sum * 3)
    {
        result = naybilshi_sum / naymenshi_sum;
    }else if (naybilshi_sum > naymenshi_sum * 2)
    {
        result = naybilshi_sum * naymenshi_sum;
    }
    
    double x = result / variant;

    cout << "Результат: " << x << endl;

    return x;
    
}

void function_2(double &x, double tower[5][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tower[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tower[i][j] = (tower[i][j] + variant + j - i) * (rand() % 100 + 1);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << tower[i][j] << " ";
        }
        cout << endl;
    }
    
}

void function_3(double tower[5][5], double result[5]){
    for (int j = 0; j < 5; j++)
    {
        double naymesh = tower[0][j];
        for (int i = 1; i < 5; i++)
        {
            if (tower[i][j] < naymesh)
            {
                naymesh = tower[i][j];
            }
        }

        double naymesh_1 = tower[0][j];
        for (int i = 1; i < 5; i++)
        {
            naymesh_1 = (tower[i][j] < naymesh_1) ? tower[i][j] : naymesh_1;
        }
        
        if (naymesh != naymesh_1)
        {
            cout << "Результати не співпадають" << endl;
        }else{
            cout << "Результати співпадають" << endl;
        }
        
        result[j] = naymesh;
    }
    
}

struct Node
{   
    string first_name;
    string last_name;
    double cash;
    Node* prev;
    Node* next;
};

Node* create_node(const string& first_name, const string& last_name, double cash){
    Node* new_node = new Node;
    new_node->first_name = first_name;
    new_node->last_name = last_name;
    new_node->cash = cash;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    return new_node;
}

Node* function_4(double result[5]){
    string first_name[] = {"Богдан", "Арсен", "Остап", "Павло", "Роман", "Микола", "Тарас"};
    string last_name[] = {"Дмитрович", "Ігорович", "Фарина ", "Іваник", "Кутельмах", "Лазаревич", "Стефанович"};
    double naymenshi = result[0];
    double naybilshi = result[0];
    for (int i = 1; i < 5; i++)
    {
        if (result[i] > naybilshi)
        {
            naybilshi = result[i];
        }
        if (result[i] < naymenshi)
        {
            naymenshi = result[i];
        }
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    head = create_node(first_name[rand() % 7], last_name[rand() % 7], naybilshi);
    tail = head;

    for (int i = 0; i < 5; i++)
    {
        Node* new_node = create_node(first_name[rand() % 7], last_name[rand() % 7], result[i]);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    
    Node* last_node = create_node(first_name[rand() % 7], last_name[rand() % 7], naymenshi);
    tail->next = last_node;
    last_node->prev = tail;
    tail = last_node;

    
}

void help_for_function_5(Node* node, ofstream& file){
    while (node != nullptr)
    {
        file << node->first_name << " " << node->last_name << " " << node->cash << endl;
        node = node->next;
    }
}

void  help_for_function_5_rec(Node* node, ofstream& file){
    if (node == nullptr)
    {
        return;
    }
   
    file << node->first_name << " " << node->last_name << " " << node->cash << endl;
    help_for_function_5_rec(node->next, file);
}

void  function_5(Node* head){
    ofstream file("student.txt");
    if (!file.is_open())
    {
        cerr << "ERORR" << endl;
        return;
    }
    
    if (variant % 2 == 0)
    {
        help_for_function_5_rec(head, file);
    }else{
        help_for_function_5(head, file);
    }

    file.close();
}

void function_6(){
    ifstream file("student.txt");
    if (!file.is_open())
    {
        cerr << "ERORR" << endl;
        return;
    }

    string list;

    while (getline(file, list))
    {
        cout << list << endl;
    }
    file.close();
}
int main(){
    double x = function_1();
    double tower[5][5];
    function_2(x, tower);
    double result[5];
    function_3(tower, result);

    Node* student = function_4(result);

    function_5(student);

    function_6();

    return 0;
}