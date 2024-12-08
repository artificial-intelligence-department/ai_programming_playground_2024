// 4 частина: це функції
// перевантаження функцій
// рекурсивні функції
// от спробуйте спершу написати рекурсивну функцію обходу списку і виводу його значень в консольку
// далі модифікуйте, щоб код записував дані у якомусь форматі у файл і буде вам частина завдання з лайв-кодінгу
// далі створіть функцію з такою ж назвою, але перепишіть код,  щоб в циклі виводились елементи списку в консольку
// далі модифікуйте, щоб код записував дані через цикл у файл і буде вам частина завдання з лайв-кодінгу
// щоб показати, що функція перевантажена цих два описи буде достатньо, а щоб викликати по-різному, то можна додати якийсь параметр
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// от спробуйте спершу написати рекурсивну функцію обходу списку і виводу його значень в консольку
void PrintList(Node* head)
{
    if(head == nullptr)
    {
        return;
    }

    cout << head->data << " ";
    PrintList(head->next);
}

// далі модифікуйте, щоб код записував дані у якомусь форматі у файл і буде вам частина завдання з лайв-кодінгу
void PrintList(Node* head, ofstream& toFile)
{
    if(head == nullptr)
    {
        return;
    }

    toFile << head->data << " ";
    PrintList(head->next);
}

// далі створіть функцію з такою ж назвою, але перепишіть код,  щоб в циклі виводились елементи списку в консольку
void PrintListConsol(Node* head)
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
}
// далі модифікуйте, щоб код записував дані через цикл у файл і буде вам частина завдання з лайв-кодінгу
void PrintListConsol(Node* head, ofstream& toFile)
{
    Node* current = head;
    while (current != nullptr) 
    {
        toFile << current->data << " ";
        current = current->next;
    }
}

int main()
{
 
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    cout << "Рекурсивний вивід у консоль: ";
    PrintList(head);
    cout << endl;

    ofstream outFile("text.txt");
    if (outFile.is_open())
    {
        PrintList(head, outFile);
        outFile.close();
        cout << "Дані записані у файл рекурсивно.\n";
    }
    else
    {
        cerr << "Помилка відкриття файлу для запису.\n";
    }

    cout << "Циклічний вивід у консоль: ";
    PrintListConsol(head);
    cout << endl;

    ofstream outFileLoop("text.txt");
    if (outFileLoop.is_open())
    {
        PrintListConsol(head, outFileLoop);
        outFileLoop.close();
        cout << "Дані записані у файл через цикл.\n";
    }
    else
    {
        cerr << "Помилка відкриття файлу для запису.\n";
    }

    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
