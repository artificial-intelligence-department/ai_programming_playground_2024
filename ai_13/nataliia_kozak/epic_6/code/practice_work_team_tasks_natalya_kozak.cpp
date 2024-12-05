#include <iostream>
#include <queue>
using namespace std;

// Структура вузла
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

//--------Reverse list-----------------
Node *reverse(Node *head)
{
    Node *prev = nullptr; // Попередній вузол
    Node *current = head; // Поточний вузол
    Node *next = nullptr; // Наступний вузол

    while (current != nullptr)
    {
        next = current->next; // Зберігаємо посилання на наступний вузол
        current->next = prev; // Змінюємо напрямок покажчика
        prev = current;       // Переміщуємо попередній вузол вперед
        current = next;       // Переходимо до наступного вузла
    }
    return prev; // Новий голова списку
}

// Функція для друку списку
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//-------Comparing lists-------------
bool compare(Node *h1, Node *h2)
{
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data != h2->data)
        {
            return false; // Невідповідність значень
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    // Якщо один список закінчився раніше іншого
    return h1 == nullptr && h2 == nullptr;
}
//------Adding-----------------
Node *add(Node *n1, Node *n2)
{
    Node *result = nullptr; // Результат (новий список)
    Node *tail = nullptr;   // Хвіст нового списку
    int carry = 0;          // Перенос

    // Ітерація, доки є цифри в обох списках або є перенос
    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum = carry; // Починаємо з переносу

        if (n1 != nullptr)
        {
            sum += n1->data; // Додаємо цифру з першого списку
            n1 = n1->next;
        }

        if (n2 != nullptr)
        {
            sum += n2->data; // Додаємо цифру з другого списку
            n2 = n2->next;
        }

        carry = sum / 10; // Обчислюємо перенос
        sum = sum % 10;   // Поточна цифра

        // Додаємо новий вузол до результату
        Node *newNode = new Node(sum);
        if (result == nullptr)
        {
            result = newNode; // Перший вузол
            tail = newNode;
        }
        else
        {
            tail->next = newNode; // Додаємо до хвоста
            tail = newNode;
        }
    }

    return result;
}

//--------Binary Tree-------------------------
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Рекурсивна функція для створення дзеркального дерева
TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    // Створюємо новий вузол із поточним значенням
    TreeNode *newRoot = new TreeNode(root->data);

    // Рекурсивно обмінюємо місцями ліву і праву гілки
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}
// Допоміжна функція для друку дерева
void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    // Черга для обходу дерева рівнями
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // Кількість вузлів на поточному рівні

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *current = q.front();
            q.pop();

            // Виводимо поточний вузол
            cout << current->data << " ";

            // Додаємо дочірні вузли до черги
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }

        // Завершуємо рівень і переходимо до наступного
        cout << endl;
    }
}
// Рекурсивна функція для обчислення суми підвузлів і оновлення батьківських вузлів
int tree_sum(TreeNode* root) {
    if (root == nullptr) return 0;

    // Обчислюємо суму для лівої та правої підгілки
    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    // Якщо вузол не є листком, оновлюємо його значення
    if (root->left != nullptr || root->right != nullptr) {
        root->data = leftSum + rightSum;
    }

    // Повертаємо суму підгілок і поточного вузла
    return root->data + leftSum + rightSum;
}

// Тестування
int main()
{
    //----------Reversing--------------------------
    // Створення списку: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Реверс списку
    head = reverse(head);

    cout << "Reversed list: ";
    printList(head);

    //------------Comparing--------------------------
    // Створення першого списку: 1 -> 2 -> 3
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Створення другого списку: 1 -> 2 -> 3
    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    // Створення третього списку: 1 -> 2 -> 4
    Node *head3 = new Node(1);
    head3->next = new Node(2);
    head3->next->next = new Node(4);

    // Порівняння списків
    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    cout << "List 3: ";
    printList(head3);

    cout << "Are List 1 and List 2 equal? " << (compare(head1, head2) ? "Yes" : "No") << endl;
    cout << "Are List 1 and List 3 equal? " << (compare(head1, head3) ? "Yes" : "No") << endl;

    //---------Adding------------------
    // Створення першого числа: 379 (у вигляді 9 -> 7 -> 3)
    Node *num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    // Створення другого числа: 846 (у вигляді 6 -> 4 -> 8)
    Node *num2 = new Node(6);
    num2->next = new Node(4);
    num2->next->next = new Node(8);

    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    // Додавання чисел
    Node *sum = add(num1, num2);

    cout << "Sum: ";
    printList(sum);

    //---------------Mirroring tree-------------------
    // Створення дерева
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree: " << endl;
    printTree(root);
    cout << endl;

    // Дзеркальне дерево
    TreeNode *mirrored = create_mirror_flip(root);

    cout << "Mirrored tree: " << endl;
    printTree(mirrored);
    cout << endl;

    // Оновлюємо дерево
    tree_sum(mirrored);

    cout << "Updated tree: " << endl;
    printTree(mirrored);
    cout << endl;


    return 0;
}
