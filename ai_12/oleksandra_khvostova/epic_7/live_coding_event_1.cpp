#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

int const num = 5; //4. цілочисельна константа

struct Struct{ //19. структура даних
    float matrix[5][5];
};

struct Array{
    float array[5];
};

class List {
    private:
        struct Node {
            int data;
            Node* previous;
            Node* next;
             };

        Node* head;
        Node* tail;
        size_t size;

    public:
        List() : head(nullptr), tail(nullptr), size(0) {}

        void Show() const {
            if (size == 0) {
                cout << "List is empty" << endl;
                return;
            }
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void Clear() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        void PushBack(const int& value) {
            if (size == 0) {
                head = new Node {value, nullptr, nullptr};
                tail = head;
            } else {
                tail->next = new Node {value, tail, nullptr};
                tail = tail->next;
            }
            size++;
        }
};
          

float function_1 (){
    float x;
    float a, b; //2. дійсна змінна
    int c, d, e; //1. цілочисельна змінна
    double f; //3. дійсна з подвійною точністю
    cout<<"Введіть два дійсних значення "; //18. виведення даних
    cin>>a>>b; //18. введення даних
    cout<<"Введіть три цілих значення ";
    cin>>c>>d>>e;
    cout<<"Введіть дійсне значення з подвійною точністю ";
    cin>>f;
    double array[6];
    array[0]=a; array[1]=b; array[2]=c; array[3]=d; array[4]=e; array[5]=f;
    sort(array, array+6);
    double sumM=array[3]+array[4]+array[5];
    double summ=array[0]+array[1]+array[2];
    double sum;
    if(sumM>4*summ){ //5. умовні оператори та розгалуження
        sum = sumM+summ; //15. математичні операції
    }
    if(sumM>3*summ){
        sum = sumM/summ;
    }
    if(sumM>2*summ){
        sum = summ*sumM;
    }
    x = sum/num;
    return x;
}

Struct function_2(float x){ //14. параметр функції
    Struct matr;
    for(int i=0; i<5; i++){ //10ю for цикл
        for(int j=0; j<5; j++){
            matr.matrix[i][j]=x; //7. двовимірний масив
            if(j<0){break;} //11. оператор break   
        }
    }
    
    int n=0;
    do{ //8. do while цикл
        for(int j=0; j<5; j++){
            matr.matrix[n][j]+=(num+j+n)*(1+rand()%100);        
        }
        n++;
    }
    while(n<5);

    int k=0;
    while(k<5){ //9. while цикл
        for(int j=0; j<5; j++){
            cout<<matr.matrix[k][j]<<" ";     
        }
        cout<<endl;
        k++;
    }
    return matr;
}

Array function_3 (Struct matrix){
    Array array1;
    for(int j=0; j<5; j++){
        double min;
        for(int i=0; i<5; i++){
            min=matrix.matrix[i][j];
            if(matrix.matrix[i][j] < min)
                {
                    min = matrix.matrix[i][j];
            }
        }
        array1.array[j]=min; //6. одновимірний масив
    }

    // float array2[5];
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){

    //     }
    // }

    return array1;
}

// 17. Зчитування з файлу
string ReadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening " << filename << endl;
        return "";
    }
    string surname;
    inFile >> surname;
    inFile.close();
    return surname;
}

int main(){
    float x = function_1();
    cout<<x<<endl;
    Struct tower;
    tower = function_2(x); //14. аргумент функції
    Array array=function_3(tower);
    for (int i=0; i<5; i++){
        cout<<array.array[i]<<" ";
    }

    ofstream OutFile("result.txt"); //16. запис у файл
    if (!OutFile) {
        cerr << "Error opening " << "result.txt" << endl;
        exit(1);
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            OutFile<<tower.matrix[i][j]<<" "; 
        }
    }
    OutFile.close();


    return 0;

}