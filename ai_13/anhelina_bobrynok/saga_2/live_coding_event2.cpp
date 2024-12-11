//+-1 годину я переробила те, що встигра на лайв кодінгу (в мене немає файлу локально, а пул реквест з сагою був видален)
//+-1,5 годин я доробила інші завдання

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <ctime>
#include <fstream>


using namespace std;

struct Student{
    string name;
    string surname;
    double money;
};

list<Student> function_4(double arr[5]){
    list<Student> students;
    string names[]={"Марія", "Єва", "Марк", "Олександр", "Вікторія","Тимофій","Данило"};
    string surnames[]={"Мельник", "Шевченко", "Коваленко", "Бойко", "Ткаченко","Кравченко","Ковальчук"};
    
    for (size_t i = 0; i < 7; i++){
        Student student;
        student.name = names[rand()%7];
        student.surname = surnames[rand()%7];
        students.push_back(student);
    }

    auto it = students.begin();
    (*it).money = arr[4];
    ++it;

    for (size_t i = 1; i <= 5; i++, ++it){
        (*it).money = arr[i-1];
    }
    (*it).money = arr[0];

    cout<< "список студентів:"<<endl;
    for (const auto &student : students){
        cout<<student.name<<""<<student.surname<<" - гроші"<<student.money<<endl;
    } 
    
    return students;
}

void help_for_function_5(ofstream &file, const list<Student> &students){
    for (const auto &student : students){
        file << student.name <<""<<student.surname<<" - гроші"<<student.money<<endl;
    }
    
}
void help_for_function_5(ofstream &file, list<Student>::const_reverse_iterator it, list<Student>::const_reverse_iterator end){
    if (it == end) return;
    file << it->name << " " << it->surname << " - гроші " << it->money << endl;
    auto next_it = it;
    ++next_it;
    help_for_function_5(file, next_it, end);
}

void function_5(const list<Student> &students, int variant){
    
    ofstream file("students.txt");
    if(!file.is_open()){
        cerr<<"error"<<endl;
        return;
    }

    if (variant % 2 == 0){
        help_for_function_5(file, students.rbegin(), students.rend());
    }else{
        help_for_function_5(file, students);
    }
    file.close();
}
const int variant = 63;

void function_1(){

    int c, d, e;
    float a, b;
    double f;

    cout<<"введіть a"<<endl;
    cin>>a;
    cout<<"введіть b"<<endl;
    cin>>b;
    cout<<"введіть c"<<endl;
    cin>>c;
    cout<<"введіть d"<<endl;
    cin>>d;
    cout<<"введіть e"<<endl;
    cin>>e;
    cout<<"введіть f"<<endl;
    cin>>f;

    double num[6];
    num[0] = a;
    num[1] = b;
    num[2] = c;
    num[3] = d;
    num[4] = e;
    num[5] = f;

    sort(num, num+6);

    double min1 = num[0];
    double min2 = num[1];
    double min3 = num[2];

    double max1 = num[3];
    double max2 = num[4];
    double max3 = num[5];

    double sum_max = max1+max2+max3;
    double sum_min = min1+min2+min3;

    double result;
    double x;

    if (sum_max>sum_min*2){
        result = sum_min*sum_max;
    }else if(sum_max>sum_min*3){
        result = sum_min/sum_max;
    }else if(sum_max>sum_min*4){
        result = sum_min+sum_max;
    }else{
        cout<<"error"<<endl;
    }
    
    x = result/variant;
    cout<<"x:"<<x<<endl;

    return;
}

void function_2(double &x){
    double matrix [5][5];
    srand(time(0));

    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 5; j++){
            matrix [i][j] = x;
        }
    }

    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 5; j++){
            int random = rand()%100+1;
            matrix [i][j] = (matrix [i][j] + variant + j - i)*random;
        }
    }
    
    cout<<"матриця:"<<endl;
    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 5; j++){
            cout << matrix [i][j] <<"\t";
        }
        cout<<endl;
    }

}
void function_3(double tower[5][5]){
    double arr[5];
    for (size_t j = 0; j < 5; j++){
        
        double min1 = INT_MAX;
        for (size_t i = 0; i < 5; i++){
            if (tower[i][j]<min1){
                min1 = tower[i][j];
            }
        }

        double min2 = *min_element(&tower[0][j], &tower[0][j]+5 * sizeof(tower[0]))/ sizeof(double);
        
        if (min1 != min2){
            cout<<"помилка для "<<j<<endl;
        }else{
            cout<<"результати збігаються для "<<j<<endl;
        }
        
    }
    
    return;
}

void function_6(){
    const string filename="students.txt";
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"error"<<endl;
        return;
    }

    cout<<"вміст файлу"<<filename<<":"<<endl;
    string line;
    while (getline(file, line)){
        cout<< line <<endl;
    }
    file.close();
}


int main() {
    
    double x;
    double tower[5] [5];
    double min2[5];

    function_1();
    if (x ==0){
        return 0;
    }

    function_2(x);
    function_3(tower);

    list<Student> students = function_4(min2);

    function_5(students, variant);
    function_6();
    
    return 0;
}