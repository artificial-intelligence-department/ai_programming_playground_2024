#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;



struct Student {
public:
    string first_name;
    string last_name;
    float bank_money;
    Student* next;
    Student* prev;

    Student(string f_name, string l_name, float b_money) {
        first_name = f_name;
        last_name = l_name;
        bank_money = b_money;
        next = nullptr;
        prev = nullptr;
    }
};


struct StudentList {

    public:
    Student* head;
    Student* tail;
    int size;
    StudentList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }



    void create(int listSize, string f_name[], string l_name[], float b_money[]) {
        for(int i=0; i<listSize; i++){
            Student* newSt = new Student(f_name[i], l_name[i], b_money[i]);
            if(!head){
                head = newSt;
                head->next = tail;
            } else {
                Student* tmp = head;
                while(tmp->next){
                    tmp = tmp->next;
                }
                tmp->next = newSt;
                newSt->prev = tmp;
                tail=newSt;
            }
        }
    }

    void print(){
        Student* curr = head;
        while(curr){
            cout << "Ім'я : " << curr->first_name << 
            ";  Прізвище : " << curr->last_name <<
            ";  Рахунок : " << curr->bank_money << "\n";
            curr = curr->next;
        }
    }


};




float buublesort(float** &tower, int n, int l){
    bool swapped; // для перевірки, чи закінчилась перестановка
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (tower[j][l] > tower[j+1][l]) {
                swap(tower[j+1][l], tower[j][l]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return tower[0][l];
}

float sortt(float** &tower, int n, int l){
    for (int i = 0; i < n - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tower[j][l] < tower[smallestIndex][l])
				smallestIndex = j;
		}
		swap(tower[i][l], tower[smallestIndex][l]);
	}
    return tower[0][l];
}



float function_1(){
    int n=6;
    int a, b;
    float c, d, e, ans;
    double f, max[3], min[3], sum_max=0, sum_min=0;
    std::cin >> a >> b >> c >> d >> e >> f;
    double numbers[] = {(double)a, (double)b, c, d, e, f};
    for (int i = 0; i < n - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (numbers[j] < numbers[smallestIndex])
				smallestIndex = j;
		}
		swap(numbers[i], numbers[smallestIndex]);
	}
    while(n>3){
        sum_max+=numbers[n-1];
        n--;
    }
    do{
        sum_min+=numbers[n-1];
        n--;
    }while(n>0);

    if(sum_max > sum_min*2){
        ans = sum_max*sum_min;
    }
    if(sum_max > sum_min*3){
        if(sum_min!=0){
            ans = sum_max/sum_min;
        } else {
            ans = 0;
        }
    }
    if(sum_max > sum_min*4){
        ans = sum_max+sum_min;
    }

    const float x = ans/32;

    return x;
}

float** function_2(float &x){
    const int n=5;
    float** array = new float*[n];
    for(int i =0; i<n; i++){
        array[i] = new float[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            array[i][j]=x;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            array[i][j] = (array[i][j]+32+(double)j-(double)i)*(double)(rand()% 100 + 1);
            std::cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    return array;
}


float* function_3(float** &tower){
    float* arr = new float[5];
    for(int l=0; l<5; l++){
        float min_bub = buublesort(tower, 5, l);
        float min_sort = sortt(tower, 5, l);
        if(min_sort == min_bub){
            arr[l] = min_sort;
        } else {
            cerr << "Найменші значення не збіглись";
            return 0; // повеертає 0, щоб закінчилось виконання функції
        }
    }
    return arr;
}


StudentList function_4(float* min_el){
    StudentList list;
    int n=7;
    float bank_money[n];
    bank_money[0]=*max_element(min_el, min_el+5);
    bank_money[n-1]=*min_element(min_el, min_el+5);
    float sum[5];
    sum[0] = min_el[0];                //перший елемент однаковий
    for(int i=1; i<5; i++){
        sum[i] = sum[i-1]+min_el[i];   //всі наступні - суми попередніх
    }
    for(int i=1; i<n-1; i++){
        bank_money[i]=sum[i-1];
    }
    string first_name[n] = {"Anya", "Solomiia", "Stanley", "Asley", "Yaroslaw", "Alya", "Star"};
    string last_name[n] = {"Forger", "Chrowey", "Pines", "Corney", "Kob", "Sesar", "Butterfly"};
    list.create(n ,first_name, last_name, bank_money);
    list.print();
    return list;
}

//мій варіант
void help_for_function_5(Student* current, int v, FILE* f){
    if(current){
        fputs((current->first_name).c_str(), f);
        fputs(" ", f);
        fputs((current->last_name).c_str(), f);
        fputs(" ", f);
        fputs((to_string(current->bank_money)).c_str(), f);
        fputs("\n", f);
        help_for_function_5(current->prev, v, f);
    }
}

void help_for_function_5(Student* current, float v, FILE* f){
    while(current->prev){
        current = current->prev;
    }
    while(current){
        fputs((current->first_name).c_str(), f);
        fputs(" ", f);
        fputs((current->last_name).c_str(), f);
        fputs(" ", f);
        fputs((to_string(current->bank_money)).c_str(), f);
        fputs("\n", f);
        current = current->next;
    }

}


void function_5(StudentList list, int v){
    FILE* f = fopen("SomeFile.txt", "w");
    if(!f){
        cerr << "Файл не створено";
        return;
    }
    Student* current = list.tail;
    if(v%2==0){
        help_for_function_5(current, v, f);
    } else {
        help_for_function_5(current, (float)v, f);
    }
    fclose(f);
    FILE* nf = fopen("SomeFile.txt", "r");
    if(f==0){
        cerr << "Файл не відкрито";
        return;
    }
    char str[50];
    while(fgets(str, 50, f)){
        cout << str;
    }
    fclose(nf);
}




int main(){
    int variant = 32;
    float x = function_1();
    cout << "\n";
    float** tower = function_2(x);
    float* min_elements = function_3(tower);
    cout << "\n";
    StudentList list = function_4(min_elements);
    cout << "\n";
    function_5(list, variant);
    for(int i=0; i<5; i++){
        delete[] tower[i];
    }
    delete[] tower;
    delete[] min_elements;
    return 0;
}