#include <iostream>
#include <algorithm>//для сортування масиву в function_1()
#include <cstdlib>//для rand() в function_2()
#include <iomanip>//для зручності виведення матриці в function_2()
#include <fstream>//для роботи з файлами в function_5()
#include <string>
using namespace std;
const int VARIANT = 76;//Цілочисельна константа

int function_1() {
    float a, b;//Дійсні змінні
    int c, d, e;//Цілочисельні змінні
    double f;//Дійсна змінна з подвійною точністю

    cout << "Enter float a, b: ";
    cin >> a >> b;//Використано оператори введення та виведення даних

    cout << "Enter int c, d, e: ";
    cin >> c >> d >> e;

    cout << "Enter double f: ";
    cin >> f;

    //конвертація в один тип данних.Використано одновимірний масив
    double array[6] = { static_cast<double>(a),static_cast<double>(b),
                       static_cast<double>(c),static_cast<double>(d),
                       static_cast<double>(e), f };

    sort(array, array + 6);//Сортуємо масив. 3 останні елементи найбільші, а 3 перші найменші

    double min_sum = array[0] + array[1] + array[2];
    double max_sum = array[3] + array[4] + array[5];

    double result;
    if (max_sum > min_sum * 4) { //Умовний оператор
        result = max_sum + min_sum;
    }
    else if (max_sum > min_sum * 3) {
        result = max_sum / min_sum;
    }
    else {
        result = max_sum * min_sum;
    }

    double new_result = result / VARIANT;

    cout << "Result in function_1: " << new_result;

    return new_result;
}

void function_2(double matrix[5][5], double& x) {

    //Заповнення матриці значенням з function_1()
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    //Оновлення матриці за заданою формулою
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }

    //Вивід онолвненої матриці
    cout << "\nResult in function_2:\n";
    cout << "\nUpdated matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(10) << fixed << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void function_3(double min_value_array[5], const double matrix[5][5]) {

    //Перший спосіб пошуку
    for (int j = 0; j < 5; j++) {
        double min_value = matrix[0][j];
        for (int i = 1; i < 5; i++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
        }
        min_value_array[j] = min_value;
    }

    //Другий спосіб пошуку

    double min1_value_array[5];

    for (int j = 0; j < 5; j++) {
        double temp[5];
        for (int i = 0; i < 5; i++) { //Копіюємо стовпець в тимчасовий масив
            temp[i] = matrix[i][j];
        }

        double min1_value = *min_element(temp, temp + 5); //Використано вказівник
        min1_value_array[j] = min1_value;

    }

    //Порівнюємо 
    cout << "\nResult in function_3:\n";
    cout << "\nComparing arrays:\n";
    cout << "\nFirst array:\n";
    for (int i = 0; i < 5; i++) {
        cout << min_value_array[i] << fixed << setprecision(2) << " ";
    }
    cout << "\nSecond array:\n";
    for (int i = 0; i < 5; i++) {
        cout << min1_value_array[i] << fixed << setprecision(2) << " ";
    }
    //Виводимо результат
    cout << "\nThe least number of each column\n";
    for (int i = 0; i < 5; i++) {
        cout << "Column " << i + 1 << ": " << min_value_array[i] << endl;
    }
}

struct Node
{
    double data;
    string name;
    string surname;


    Node* next;
    Node* prev;


    Node(double money, string& Name, string& Surname)
    {
        data = money;
        name = Name;
        surname = Surname;
    }
};

//Двонапрямлений список
struct LinkedList
{
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}


    void AddToList(double m, string n, string s) {
        Node* newNode = new Node(m, n, s);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList(Node* head) {
        while (head != NULL) { //Використано цикл while
            cout << "Name: " << head->name
                << ", Surname: " << head->surname
                << " , Balance: " << head->data << endl;

            head = head->next;
        }
    }

    //Виведеня реверснутого списку
    void reverseList() {
        if (head == NULL) return;

        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {

            temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            if (temp == NULL) {
                head = current;
                break;
            }
            current = temp;
        }
    }

};


void function_4(LinkedList& Student, const double min_value_array[5]) {

    double max_num = min_value_array[0];
    double min_num = min_value_array[0];

    //Знаходимо найбільше і найменше значення з масиву
    for (int i = 0; i < 5; i++) {
        if (max_num < min_value_array[i]) {
            max_num = min_value_array[i];
        }
        if (min_num > min_value_array[i]) {
            min_num = min_value_array[i];
        }
    }

    //Знаходимо послідовну суму
    double sum[5] = { 0 };
    int i;
    for (i = 1; i < 5; i++) { //Використано цикл for
        sum[i - 1] = min_value_array[i - 1] + min_value_array[i];
    }
    cout << "\nResult in function_4:\n";

    Student.AddToList(max_num, "Steve", "Godbout");
    Student.AddToList(sum[0], "Chris", "Lloyd");
    Student.AddToList(sum[1], "Ming", "Tanguay");
    Student.AddToList(sum[2], "Isabelle", "Gibson");
    Student.AddToList(sum[3], "Omar", "Payne");
    Student.AddToList(sum[4], "Nelson", "Cameron");
    Student.AddToList(min_num, "Alison", "Cameron");

    Student.printList(Student.head);

}

//Рекурсивний запис у файл
void help_for_function_5(Node* head, ofstream& file) {

    if (head == NULL) {
        return;
    }
    else {
        file << "Name: " << head->name
            << ", Surname: " << head->surname
            << " , Balance: " << head->data << endl;
        help_for_function_5(head->next, file);
    }
}

//Тут список записується в реверснутому вигляді
void function_5(LinkedList& Student) {
    cout << "\nResult in function_5:\n";
    ofstream file("students_list.txt");//Запис у файл
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    Node* temp = Student.head;

    Student.reverseList();

    help_for_function_5(Student.head, file);

    file.close();

    ifstream InputFile("students_list.txt");//Зчитування з файлу
    if (!InputFile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    cout << "Content from this file\n";
    string line;
    while (getline(InputFile, line)) {
        cout << line << endl;
    }
    InputFile.close();
}


int main() {

    double x = function_1();
    //Використано двовимірний масив
    double matrix[5][5];
    function_2(matrix, x);

    double min_value_array[5];
    function_3(min_value_array, matrix);

    LinkedList Student;
    function_4(Student, min_value_array);

    function_5(Student);

    return 0;
}
