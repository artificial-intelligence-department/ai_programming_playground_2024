#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    struct Node {
        int data;
        Node* next;
    };

void ya_hochu_spatu(int arik[],int index){
    if(index >= 5) {
        return;
    }

    ofstream file;
    file.open("koly_spaty.txt", ios::out | ios::app);
    file << arik[index] << " ";
    file.close();
    ya_hochu_spatu( arik, index + 1);
}

void ya_hochu_spatu(const char* filename){


    ifstream file;
    file.open(filename, ios::in);
    string s;

    while (getline(file, s))
        cout << s << endl;
    file.close();
}

Node* create(Node*& head, int value) {
    Node* current = head;

    while (current->next!=nullptr){
        current = current->next;
    } 
    Node* newNode = new Node{value};
    return head;
}

void multyply(int arr1[6][6],int arr2[6][6],int res[6][6]) {
    for (int i =0; i<6;i++) {
        for (int j = 0;j<6;j++) {
            res[i][j] = 0;
            for (int k = 0;k<6;k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int sumik(int arr3[3][3]) {
    int sum = 0;
        for (int i = 0; i < 3;i++) {
        for (int j = 0;j < 3; j++) {
            sum += arr3[i][j];
        }
    }
    return sum;
}

int main() {
    int arr3[3][3] = {
    1,2,3,
    7,1,8,
    6,8,9        
    };
   int arr1[6][6] = {
    1,2,3,4,5,6,
    7,1,8,9,0,6,
    6,8,19,1,0,6,
    5,9,1,1,2,6,
    5,9,1,1,2,6,
    4,0,0,2,1,6
   };
   int arr2[6][6] = {
    1,2,3,4,5,6,
    7,1,8,9,0,6,
    6,8,19,1,0,6,
    5,9,1,1,2,6,
    5,9,1,1,2,6,
    4,0,0,2,1,6
   };

    int res[5][6];

    for (int i = 0; i < 5;i++) {
        for (int j = 0;j < 6; j++) {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for (int i = 0; i < 5;i++) {
        for (int j = 0;j < 6; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    multyply(arr1, arr2, res);

    for (int i = 0; i < 5;i++) {
        for (int j = 0;j < 6; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
 
    cout << sumik(arr3);


    cout << endl;
    int arik[5] = {10,7,2,5,3};

        for (int i = 0; i < 5;i++) {
            for (int j = 4; j > i; j-- ) {
                if(arik[j] < arik[j-1]) {
                    int r = arik[j];
                    arik[j] = arik[j-1];
                    arik[j-1] = r;
                }
            }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arik[i] << " ";
    }
    cout << endl;


    Node* head = new Node{1};
    Node* second = new Node{2};
    head->next = second;
    Node* hea = create(head, 5);
    Node* current = hea;
    while(current != nullptr) {

        cout << current->data << " ";
        current = current->next;
    } 

ya_hochu_spatu(arik,0);
cout << endl;
ya_hochu_spatu("koly_spaty.txt");
    return 0;
}

