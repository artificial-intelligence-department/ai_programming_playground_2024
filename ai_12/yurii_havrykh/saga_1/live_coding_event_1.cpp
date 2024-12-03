#include<iostream>
#include<math.h>
#include<algorithm>
#include<fstream>
//в коді не можна використовувати вектори
using namespace std;
const int variant = 33;//цілочисельна константа
struct Student {//своя структуру даних
    string firstname;
    string lastname;
    float money;
};

struct Node{
    Student data;
    Node* next;
    Node* prev;

};

class LinkedList {
    Node *head;
    public:
    LinkedList() {
        head = nullptr;
    }
};

float function_1() {
    float a, b;//дійсна змінна
    cout << "Float a, b:";
    cin >> a >> b;

    int c, d, e;//цілочисельна змінна
    cout << "Int c, d, e:";
    cin >> c >> d >> e;

    double f;// дійсна з подвійною точністю змінна
    cout << "Double f:";
    cin >> f;
    auto max1 = variant;
    float x = rand() % 100 + 1;
}

float **function_2(float x) {
    float **matrix = new float *[5];//двовимірний масив, вказівники
    for (int i = 0; i < 5; i++)// for цикл
        matrix[i] = new float[5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + variant - i + j) * (rand() % 100 + 1);
        }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    float **pointer[5];//одновимірний масив, вказівники
    for (int i = 0; i < 5; i++) {
        //pointer[i]=**matrix[i];
    }
    return matrix;
}

float *function_3(float **matrix) {
    float array[5];
    for (int i = 0; i < 5; i++) {
        float minn = pow(10,5); //математичні операції та математичні функції == 1e5
        for (int j = 0; j < 5; j++) {
            minn = min(minn, matrix[j][i]);
            //if(minn > matrix[j][i]) minn=matrix[j][i];
        }
        array[i] = minn;
    }
    int i = 0, j = 0;
    bool flag = true;

    while (i < 5) {//while цикл
        float minn = 1e5;
        j = 0;
        do {
            minn = min(minn, matrix[j][i]);
            j++;
        }while(j<5);//do while цикл
        if (minn != array[i]) //умовні оператори та розгалуження
            flag = false;
        i++;
    }
    if (flag) cout << "Results is equal" << endl;
    else cout << "Results is not equal" << endl;
    return array;


}

void function_4(float *array) {
    //LinkedList list;
    Student list[7];
    list[0]={"Dgfgdfg", "gsdsdgs"};
    list[1]={"Dgfsdfdfg", "Khjdgs"};
    list[2]={"Dgfsfgdfg", "QEsdgs"};
    list[3]={"sdffgdfg", "gdfghjdgs"};
    list[4]={"Ddfg", "IPIPgs"};
    list[5]={"Lgjhg", "BFsdgs"};
    list[6]={"Nkljdlkfg", "wgs"};
    float maxx=0,minn=1e6;
    for(int i=0;i<5;i++){
        maxx=max(maxx,array[i]);
        minn=min(minn,array[i]);
    }
    list[0].money=maxx;
    list[6].money=minn;
    for(int i=1;i<6;i++){
        list[i].money=array[i];
    }
    for(int i=0;i<7;i++){
        cout<<list[i].firstname<<" "<<list[i].lastname<<" "<<list[i].money<<endl;
    }


}

void function_5(){

}

int main() {
    float x=function_1();

    auto tower = function_2(x);

    float *array = function_3(tower);

    function_4(array);
}