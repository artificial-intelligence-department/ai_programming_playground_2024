#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int var = 18;
const string FILENAME = "students.txt";

struct Person
{   
  string firstName;
  string lastName;
  double moneyCount;
};

struct Node
{
  Person data;
  Node* next;
  Node* prev;

  Node(const Person& value) : data(value), next(nullptr), prev(nullptr) {}
};

struct LinkedList {
  Node* head;

  LinkedList(): head(nullptr) {}
  ~LinkedList() {
    Node* current = head;
    while(current){
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
    }
  }

  void insert(const Person& person){
    Node* newNode = new Node(person);
    newNode->next = head;
    if(head) {
      head->prev = newNode;
    }
    head = newNode;
  }

  void print() const {
    Node* tmp = head;
    while(tmp){
      cout << tmp ->data.firstName << " " << tmp->data.lastName << " " << tmp->data.moneyCount << endl;
      tmp = tmp->next;
    }
  }

  void saveToFile(bool reverse) const {
    ofstream outFile(FILENAME);
    if(!outFile.is_open()){
      cout << "Error: Unable to open file for reading." << endl;
      return;
    }
    if(reverse){
      saveReverse(head, outFile);
    } 
    else {
      Node* current = head;
      while(current){
        outFile << current->data.firstName << " " << current->data.lastName << " " << current->data.moneyCount << endl;
        current = current->next;
      }
    }
    outFile.close();
  }
  private:
    void saveReverse (Node* node , ofstream& outFile) const {
      if(!node){
        return;
      }
      saveReverse(node->next , outFile);
      outFile << node->data.firstName << " " << node->data.lastName << " " << node->data.moneyCount << endl;
    }
};

double function_1(){
  double a,b,f;
  int c,d,e;

  cin >> a >> b;
  cin >> c >> d >> e;
  cin >> f;

  double arr [6] = {a, b,static_cast<double>(c),static_cast<double>(d),static_cast<double>(e),f};
  for (size_t i = 0; i < 5; i++)
  {
    for (size_t j = i+1; j < 6; j++)
    {
      if (arr[i] < arr[j])
      {
        swap(arr[i],arr[j]);
      }
    }
  }

  double sum_max = arr[0]+arr[1]+arr[2];
  double sum_min = arr[3]+arr[4]+arr[5];

  double result;

  if (sum_max > sum_min*2)
  {
    return sum_max*sum_min;
  }
  else if (sum_max>sum_min*3)
  {
    return sum_max/sum_min;
  }
  else if (sum_max>sum_min*4)
  {
    return sum_max+sum_min;
  }
  else
  {
    return sum_max - sum_min; //якщо жодна умова не виконалась
  }
  return result / var;
}

void function_2 (double x , double matrix[5][5]){
  const int size = 5;

  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      matrix[i][j] = x;
    }
  }

  srand(time(0));
  for (int i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      matrix[i][j]=(matrix[i][j] + var + j - i) * (rand() % 100 + 1);
    }
  }
  cout << "Updated matrix: " << endl;
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void function_3(double matrix [5][5], double tower[5]){
  const int size = 5;

  bool match = true;
  for (size_t j = 0; j < size; ++j)
  {
    double min_element1 = matrix[0][j];
    double min_element2 = matrix[0][j];

    for (size_t i = 1; i < size; ++i)
    {
      if(matrix[i][j]<min_element1){
        min_element1 = matrix [i][j];
      }
    }
    
    for (size_t i = 0; i < size; ++i)
    {
      if (matrix[i][j] < min_element2)
      {
        min_element2 = matrix[i][j];
      }
    }
    if(min_element1 != min_element2){
      match = false;
    }

    tower [j] = min_element1;
  }

  cout << "The smallest elements match in both mathods: " << (match ? "YES" : "NOPE") << endl;
}

LinkedList function_4(double tower[5]){
  LinkedList list;
  string randomNames[7] = {"Vovchyk", "Denchyk", "Sanichka" , "Nastia" , "Yura" , "Solya" , "Artem"};
  string randomSurnames[7] = {"Lopatin", "Bodnar", "Savkov" , "Humeniuk" , "Bubelnyk" , "Andrutsyshyn" , "Kornilov"};
  for (size_t i = 0; i < 7; ++i)
  {
    Person person;
    person.firstName = randomNames[i];
    person.lastName = randomSurnames[i];
    person.moneyCount =  (i == 0) ? tower[0] : ((i == 6) ? tower[4] : tower[i - 1]);
    list.insert(person);
  }

  list.print();
  return list;
}

void function_5(LinkedList& list){
  bool reverse = (var % 2 == 0);
  list.saveToFile(reverse);

  ifstream inFile(FILENAME);
  if (!inFile.is_open())
  {
    cout << "Error: Unable to open file for reading." << '\n';
    return;
  }
  cout << "Reading list from file: " << '\n';
  string line;
  while (getline(inFile, line)){
    cout << line << endl;
  }
  inFile.close();
}

int main (){
  double x = function_1();

  double matrix[5][5];
  function_2(x , matrix);

  double tower[5];
  function_3(matrix,tower);

  LinkedList res = function_4(tower);

  function_5(res);

  return 0;
}