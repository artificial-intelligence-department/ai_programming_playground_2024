#include <iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std;

const double variant = 22;

double function_1(){
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double arr[6] = {a, b, c, d, e, f};

    const int length = 6;

    for (int startIndex = 0; startIndex < length - 1; ++startIndex){
	    int smallestIndex = startIndex;
 
    	for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
	    {
			if (arr[currentIndex] < arr[smallestIndex])
    			smallestIndex = currentIndex;
   		}
    	swap(arr[startIndex], arr[smallestIndex]);
    }

    if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0]) * 4){
        return ((arr[3] + arr[4] + arr[5]) + (arr[2] + arr[1] + arr[0])) / variant;
    }else if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0]) * 3){
        return ((arr[3] + arr[4] + arr[5]) / (arr[2] + arr[1] + arr[0])) / variant;
    }else if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0]) * 2){
        return ((arr[3] + arr[4] + arr[5]) * (arr[2] + arr[1] + arr[0])) / variant;
    }else{
        return 0;
    }
}

double** function_2(double a){
    double** matrix = new double*[5];
    for (int i = 0; i < 5; i++){
        matrix[i] = new double[5];
    } 

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            random_device seed;
            mt19937 gen(seed());
            uniform_int_distribution<> dist(1, 100);
            matrix[i][j] = a + variant + i + j + dist(gen);
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

double* function_3(double** tower){
    double* result = new double[5];
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 5; i++){
            if(tower[i][j] < result[j]){
                result[j] = tower[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 5; i++){
        cout << result[i] << " ";
    }

    return result;
}

struct Student{
    string name;
    string second_name;
    double money;
    Student* prev;
    Student* next;
};

Student* function_4(double* result){
    string name[] = {"Bohdan", "Oleh", "Yura", "Volodia", "Vika", "Olena", "Olga"};
    string second_name[] = {"Borshch", "Saukh", "Yur", "Volod", "Vik", "Tkachuk", "Melnyk"};

    double max = result[0];
    double min = result[0];

    for (int i = 0; i < 5; i++){
        if (max < result[i]){
            max = result[i];
        }
        if (min > result[i]){
            min = result[i];
        }
    }

    Student* head = nullptr;
    Student* tail = nullptr;

    float sum = result[0];
    for (int i = 0; i < 7; i++){
        Student* student = new Student;
        student -> name = name[rand() % 7];
        student -> second_name = second_name[rand() % 7];
        student -> prev = tail;
        student -> next = nullptr;

        if (i == 0){
            student -> money = min;
        }else if (i == 7){
            student -> money = max;
        }else{
            student -> money = sum;
            sum += result[i];
        }

        if (head == 0){
            head = student;
        }else{
            tail -> next = student;
        }
        tail = student;
    }    

    Student* now = head;
    while (now != nullptr){
        cout << now -> name << " " << now -> second_name << " " << now -> money;
        now = now -> next;
    }
    cout << endl;
    return head;
}

void function_5(Student* head){
    ofstream file ("Live.txt");

    if (!file.is.open()){
        cerr << "Can't be opened";
    }

    Student* tail = head;
    while (tail != nullptr && tail -> next != nullptr){
        tail = tail -> next;
    }

    Student* now = tail;

    help_for_function_5(now, file);

    file.close();
    ifstream file ("Live.txt");
    while (file){
        string output;
        getline (file, output);
        cout << output << endl;
    }
}

void help_for_function_5(Student* now, ofsream& file){
    if (now != nullptr){
        file << "Name: " << now -> name << endl;
        file << "Second Name: " << now -> second_name << endl;
        file << "Money: " << now -> money << endl << endl;
        now = now -> prev;
        help_for_function_5(now, file);
    }
}

int main(){
    double x = function_1();
    cout << x << endl;
    double** tower = function_2(x);
    double* result = function_3(tower);
    Student* list = function_4(result);
    function_5(list);
    return 0;
}
