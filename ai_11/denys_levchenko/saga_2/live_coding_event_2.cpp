#include <iostream>
#include <algorithm>
#include <fstream>

const int VARIANT = 15;
double function_1(){
    float a, b;
    int c,d,e;
    double f;

    std::cout << "Enter a b: ";
    std::cin >> a >> b;

    std::cout << "Enter c d e: ";
    std::cin >> c >> d >> e;

    std::cout << "Enter f: ";
    std::cin >> f;

    double numbs[6] = {static_cast<double>(a), static_cast<double>(b), static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    std::sort(numbs, numbs+6);

    double nmax[3]= {numbs[5], numbs[4], numbs[3]};
    double nmin[3]= {numbs[0], numbs[1], numbs[2]};



    double nmaxsum = 0;
    double nminsum = 0;
    double result = 0;

    for(int i = 0; i < 3; i++){
        nmaxsum += nmax[i];
    }

    for(int i = 0; i < 3; i++){
        nminsum += nmin[i];
    }

    if(nmaxsum > (nminsum * 4)){
        result = nmaxsum + nminsum;
    } else if(nmaxsum > (nminsum * 3)){
        result = nmaxsum/nminsum;
    } else if(nmaxsum > (nminsum * 2)){
        result = nmaxsum * nminsum;
    }

    result = result/VARIANT;
    std::cout << result << std::endl;

    return result;
}

double** function_2(double& x, double **matrix){

    for(int i=0; i<5; i++){
        matrix[i] = new double[5];
    }
    for(int i=0; i<5; i++){
        for(int j = 0; j<5; j++){
            matrix[i][j] = x;
        }
    }

    for(int i=0; i<5; i++){
        for(int j = 0; j<5; j++){
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i)*(rand()% 100);
        }
    }



    for(int i=0; i<5; i++){
        for(int j = 0; j<5; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return matrix;
}


double* function_3(double **matrix){
    double * newmatrix = new double[5];

    double* arr1 = new double[5];
    double* arr2 = new double[5];


    double min = 0;
    for(int i = 0; i<5; i++){
    double min = matrix[0][i];
    for(int j = 1; j < 5; j++){
        if(matrix[j][i] < min){
            min = matrix[j][i];
        }
        arr1[i] = min;
    }
    }

        for(int i = 0; i<5; i++){
    double min = matrix[0][i];
    for(int j = 1; j < 5; j++){
        if(matrix[j][i] < min){
            min = std::min(min, matrix[j][i]);
        }
        arr2[i] = min;
    }
    }

        for(int i = 0; i<5; i++){
            std::cout << arr1[i] << " ";
        }

    std::cout<<std::endl;

    for(int i = 0; i<5; i++){
        std::cout << arr2[i] << " ";
    }

    for(int i = 0; i < 5; i++){
        if(arr1[i] != arr2[i]){
            std::cout << "error";
            break;
        } else{
            newmatrix[i] = arr1[i];
        }
    } 

    return newmatrix;
}

struct Node{
    std::string name, surname;
    double money;
    Node* prev;
    Node* next;

    Node(std::string name, std::string surname, double money, Node* prev = nullptr, Node* next = nullptr): name(name), surname(surname), money(money), prev(prev), next(next) {}

};

class list {
    private:
        Node* head;
        Node* end;
    
    public: 
    list(): head(nullptr), end(nullptr) {}
    ~list(){
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

void moneyadd(const std::string& name, const std::string& surname, double money){
    Node* tempNode = new Node(name, surname, money);
    if(!head){
        head = end = tempNode;
    } else {
        head->next = tempNode;
        tempNode->prev = end;
        end = tempNode;
    }

}
void printNode(){
    Node* temp = head;
    while(temp){
        std::cout << temp->name << "   " << temp->surname << "   Balance:" << temp->money << std::endl;
        temp = temp->next;
    }
}

    Node* returnHead() const {
        return head;
    }

    Node* returnEnd() const {
        return end;
    }
};

list function_4(double* matrix){
    list students;
    std::string surnames[] = {"Sickbud", "Bagdan", "Revo", "Greenday", "Nemiroff", "Bryuhovichi", "15let"};
    std::string names[] = {"Nazar", "Denys", "Makson", "Danylka", "Alex", "Scammer", "Chinese"};

    for(int i = 0; i<7; i++){
        if(i == 0){
            students.moneyadd(names[i], surnames[i], matrix[4]);
    } else if(i == 6){
            students.moneyadd(names[i], surnames[i], matrix[0]);
    } else {
            students.moneyadd(names[i], surnames[i], matrix[i-1]);
    }
    }

    return students;
}

void help_for_function_5(std::ofstream& file, const list& students, bool reverse) {
    if(reverse){
        Node* tempend = students.returnEnd();
        while (tempend) {
            file << tempend->name << "   " << tempend->surname << "   Balance:" << tempend->money << std::endl;
            tempend = tempend->prev;
        }
    } else {
        Node* temphead = students.returnHead();
        while (temphead) {
            file << temphead->name << "   " << temphead->surname << "   Balance:" << temphead->money << std::endl;
            temphead = temphead->prev;
        }

    }

}

void function_5(const list& students){
    int VARIANT = 15;
    std::ofstream file("Students.txt");
    if(!file.is_open()){
        std::cout << "Error";
        return;
    }
    if (VARIANT % 2 ==  0){
        help_for_function_5(file, students, true);
    } else {
        help_for_function_5(file, students, false);
    }
    file.close();
}

void function_6() {
    std::ifstream file("Students.txt");
    if (!file.is_open()) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}


int main(){
    double x = function_1();
    double** matrix = new double*[5];

    double** tower = function_2(x, matrix);
    std::cout << std::endl;
    double *masiv = function_3(tower);
    std::cout << std::endl;
    std::sort(masiv,masiv+5);
    list students = function_4(masiv);
    students.printNode();
    std::cout << std::endl;

    function_5(students);
    std::cout << std::endl;
    function_6();
    return 0;
}   