#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {} // ініціалізація значення та пустого покажчика
};

// Функція порівняння двох списків
bool compare(Node* h1, Node* h2) {
    // Ітерація по обох списках
    while (h1 != nullptr && h2 != nullptr) {
        // Порівняння значень даних у кожному вузлі
        if (h1->data != h2->data) {
            return false; // Якщо значення не збігаються
        }
        h1 = h1->next;
        h2 = h2->next; // йдемо до наступного значення
    }

    // Якщо один з списків закінчився, а інший ще є, повертаємо false
    return h1 == nullptr && h2 == nullptr;
}

// Допоміжна функція для створення списку
Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Основна функція
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 9, 5};
    
    Node* list1 = createList(arr1, 5);
    Node* list2 = createList(arr2, 5);
    
    if (compare(list1, list2)) {
        std::cout << "Lists are equal." << std::endl;
    } else {
        std::cout << "Lists are not equal." << std::endl;
    }
    return 0;
}
