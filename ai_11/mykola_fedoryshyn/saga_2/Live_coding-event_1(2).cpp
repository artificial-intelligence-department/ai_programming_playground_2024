#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;
const int Variant = 26; 

struct Student{
    string name;
    string fname;
    int money;
};
struct Node {
    Student data;
    Node* prev;
    Node* next;
    Node(const Student& value) : data(value), prev(nullptr), next(nullptr) {}
};


double function1();
vector<vector<double>> function2(double& x);
vector<double> function3(vector<vector<double>> matrix);
Node* function4(vector<double> matrix);
void function5(Node*head);

///////////////////////////////////////////////////////My Functions////////////////////////////////////////////
void Print(vector<vector<double>> matrix);
vector<double> Min_colum(vector<vector<double>> matrix);
vector<double> Min_colum(vector<vector<double>> matrix, int i, vector<double> result);
void Show(Node* head);
void Clear(Node* head);
void write_to_file(const char *name, Student& content);
void read_file(const char *name);
///////////////////////////////////////////////////////My Functions////////////////////////////////////////////




int main(){
    double x;
    vector<vector<double>> tower;
    vector<double> matrix_4;

    x = function1();
    tower = function2(x);
    matrix_4 = function3(tower);
    Node* head = function4(matrix_4); 
    function5(head);
    Clear(head);


    return 0;
}





///////////////////////////////////////////////////////My Functions////////////////////////////////////////////
void Print(vector<vector<double>> matrix){
    for( int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << matrix[i][j] << "\t";
        }
    cout << endl;
    }
}

vector<double> Min_colum(vector<vector<double>> matrix){
    vector<double> result(5, INT_MAX);
    for( int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(matrix[j][i] < result[i]){
                result[i] = matrix[j][i];
            }
        }
    }
    return result;
}
vector<double> Min_colum(vector<vector<double>> matrix, int i, vector<double> result){
    if(i == 5) return result;
    else{
        for(int j = 0; j<5; j++){
            if(matrix[j][i] < result[i]){
                result[i] = matrix[j][i];
            }
        }

        return Min_colum(matrix, i+1, result);
    }
}

void Show(Node* head){
    Node* current = head->next;
    while(current != nullptr){
        cout << current->data.name << ", "<< current->data.fname << ", "<< current->data.money << endl;
        current = current->next;
    }
    cout << endl;
}
void Clear(Node* head) {
        while (head) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

void write_to_file(const char *name, Student& content) {
    if (name == nullptr) {
        exit(1);
    }
    std::ofstream file(name, std::ios::app);
    if (!file.is_open()) {
        exit(2);
    }

    file << content.name << " " << content.fname << " "<< content.money << ";\n"; 
    if (file.fail()) {
        exit(3);
    }

    file.close();
}
void read_file(const char *name){
    if (name == nullptr) {
        exit(1);
    }
    std::ifstream file(name);
    if (!file.is_open()) {
        exit(2);
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    if (!file.eof() && file.fail()){
        exit(3);
    }

    file.close();
}
///////////////////////////////////////////////////////My Functions////////////////////////////////////////////





double function1(){
    double a, b, f;
    int c, d, e;
    cin >> a >> b;
    cin >> c >> d >>e;
    cin >> f;

    vector<double> arr = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr.begin(), arr.end());
    double min_sum = arr[0] + arr[1] + arr[2];
    double max_sum = arr[3] + arr[4] + arr[5];
    double result;
    if(max_sum > min_sum*4){
        result = max_sum+min_sum;
    }
    else if(max_sum > min_sum*3){
        result = max_sum/min_sum;
    }
    else if(max_sum > min_sum*2){
        result = max_sum*min_sum;
    }
    else{
        result = 0;
    }
    return result / Variant;
}

vector<vector<double>> function2(double& x){


    vector<vector<double>> result(5, vector<double>(5, x));
    srand(time(0));
    int randomNum = rand() % 100 + 1;

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            result[i][j] = (result[i][j]+Variant+i-j)* randomNum;
        }
    }
    Print(result);
    return result;
}

vector<double> function3(vector<vector<double>> matrix){
    bool same = true;
    vector<double> temp(5, INT_MAX);
    vector<double> result1(5);
    vector<double> result2(5);
    result2 = Min_colum(matrix, 0, temp); // second algorithm
    result1 = Min_colum(matrix); // first algorithm
    
    for(int i = 0; i<5; i++){
        if(result1[i] != result2[i]){
            cout << "Smth went wrong. Differance in min_colum!\n";
            same = false;
            break;
        }
    }
    if(same){
        cout << "First algorithm and second algorithm gives the same result!\n";
    }
    return result1;
}

Node* function4(vector<double> matrix){

    srand(time(0));
    sort(matrix.begin(), matrix.end());

    Student s0, s1, s2, s3, s4, s5, s6, s7;
    Student student_list[7] = {s1, s2, s3, s4, s5, s6, s7};
    string names[7] = {"name1", "name2", "name3", "name4", "name5", "name6", "name7"};
    string fnames[7] = {"fname1", "fname2", "fname3", "fname4", "fname5", "fname6", "fname7"};
    for(int i = 0; i<7; i++){
        student_list[i].name = names[rand() % 7];
        student_list[i].fname = fnames[rand() % 7];
    }
    s1.money = matrix[4];
    s7.money = matrix[0];
    double sum = 0;
    for (int i = 0; i < 5; i++){
        sum += matrix[i];
        student_list[i+1].money = sum;
    }

    Node* head = new Node(s0);
    Node* current = head;

    for (int i = 0; i < 7; ++i) {
        Node* newNode = new Node(student_list[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    head->next->data.money = matrix[4];
    head->next->next->next->next->next->next->next->data.money = matrix[0];
    Show(head);
    return head;
}

void function5(Node*head){
    Node* current = head->next;
    for(int i = 0; i<7; i++){
        write_to_file("Students.txt", current->data);
        current = current->next;
    }
    cout << "\n Students info from file: \n";
    read_file("Students.txt");
    
}