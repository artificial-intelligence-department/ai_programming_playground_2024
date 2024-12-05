#include <iostream>
using namespace std;

// Структура для вузла списку
struct Node {
    int data;  //  якесь значення
    Node* next;  // Вказівник на наступний елемент
    Node(int x) : data(x), next(nullptr) {}  // ініціалізація значення та пустого покажчика
};

// Функція для додавання двох чисел, представлених списками
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;  // Головний елемент результату
    Node* temp = nullptr;    // Для тимчасових змінних
    Node* prev = nullptr;    // Для зв'язування результату
    int carry = 0;           // Перенос між розрядами

    // Проходимо обидва списки
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;  // Початкове значення суми 

        if (n1 != nullptr) {
            sum += n1->data;  // Додаємо цифру з першого числа
            n1 = n1->next;     // Переходимо до наступного розряду
        }

        if (n2 != nullptr) {
            sum += n2->data;  // Додаємо цифру з другого числа
            n2 = n2->next;     // Переходимо до наступного розряду
        }

        carry = sum / 10;      // Визначаємо перенос
        int digit = sum % 10;  // Отримуємо поточну цифру результату

        // Створюємо новий вузол зі знайденою цифрою
        temp = new Node(digit);

        // Перший вузол - це результат
        if (result == nullptr) {
            result = temp;
        } else {
            prev->next = temp;  // Зв'язуємо попередній вузол з новим
        }

        prev = temp;  // Оновлюємо попередній вузол
    }

    return result;
}

// Функція для виведення числа (списку)
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Основна функція для тестування
int main() {
    // Створення першого числа (379 = 9 -> 7 -> 3)
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);

    // Створення другого числа (245 = 5 -> 4 -> 2)
    Node* n2 = new Node(5);
    n2->next = new Node(4);
    n2->next->next = new Node(2);

    // Додавання чисел
    Node* result = add(n1, n2);

    // Виведення результату (624 = 4 -> 2 -> 6)
    cout << "Result: ";
    printList(result);

    return 0;
}
