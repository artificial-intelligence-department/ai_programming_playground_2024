#include <iostream>

using namespace std;
const int MY_VARIANT = 80;

template <typename T>
// bynary search tree
struct BSTNode
{
    T data;
    BSTNode *lchild;
    BSTNode *rchild;

    BSTNode(T value) : data(value), lchild(nullptr), rchild(nullptr) {};
};

template <class T>
class BST
{
private:
    BSTNode<T> *root;

public:
    int size;

    BST() : root(nullptr), size(0) {}

    T bMin(BSTNode<T> *current, BSTNode<T> *root)
    {
        if (current == nullptr)
            return 9999;
        if (current->lchild == nullptr)
        {
            root->lchild = nullptr;
            return current->data;
        }
        else
        {
            return bMin(current->lchild, current);
        }
    }
    T bMin()
    {
        return bMin(this->root, this->root);
    }

    T bMax(BSTNode<T> *current, BSTNode<T> *root)
    {
        if (current == nullptr)
            return 9999;
        if (current->rchild == nullptr)
        {
            root->rchild = nullptr;
            return current->data;
        }
        else
        {
            return bMax();
        }
    }

    T bMax()
    {
        return bMax(this->root, this->root);
    }

    BSTNode<T> *insert(BSTNode<T> *node, int value)
    {
        if (node == nullptr)
        {
            this->size++;
            return new BSTNode<T>(value);
        }
        if (value < node->data)
        {
            node->lchild = insert(node->lchild, value);
        }
        else if (value > node->data)
        {
            node->rchild = insert(node->rchild, value);
        }
        return node;
    }

    void insert(int value)
    {
        this->root = insert(this->root, value);
    }
    ///////////////////////////////////////////////////
    void setplace(BSTNode<T> *node, T value)
    {
        if (node->data > value)
        {
            if (node->lchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->lchild = newNode;
                this->size++;
                return;
            }
            else
                setplace(node->lchild, value);
        }
        else if (node->data < value)
        {
            if (node->rchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->rchild = newNode;
                this->size++;
                return;
            }
            else
                setplace(node->rchild, value);
        }
        else
            return;
    }

    void setplace(T value)
    {
        if (this->data == -999 && this->lchild == nullptr && this->rchild == nullptr)
        {
            this->data = value;
            this->size++;
        }
        else
            setplace(this, value);
    };
};
// ВЗЯВ ЗІ СВОГО СЕЛФ ПРАКТІС В 6 ЕПІКУ (ДЛЯ ПОШУКУ БІНАРНОГО)



struct student
{
    string name;
    string surname;
    float money;
};//представляє студента: ім'я (рядок),прізвище (рядок),кількість
//грошей на рахунку (дійсне число).




template <class T>
class DCL
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };

    Node *first;
    Node *last;

public:
    int size;

    class Inode
    {
    private:
        Node *node;

    public:
        Inode(Node *node) : node(node) {};

        Node *operator*()
        {
            return this->node;
        }

        Inode operator+(int index)
        {
            while (index--)
                this->node = this->node->next;
            return *this;
        }
    };

    DCL() : first(nullptr), last(nullptr), size(0) {}

    Inode begin()
    {
        return Inode(first);
    }

    DCL &operator<<(string separator)
    {
        Node *node = this->first;
        while (node != nullptr)
        {
            cout << "name " << node->data.name << "surname " << node->data.surname << "money " << node->data.money << separator;
            node = node->next;
        }
        cout << endl;
        return *this;
    }

    //  position after witch and value
    void insert(int index, T data)
    {
        Node *node = new Node{data, nullptr, nullptr};
        if (this->size == 0)
        {
            this->first = this->last = node;
        }
        else if (index == 0)
        {
            node->next = this->first;
            first->prev = node;
            first = node;
        }
        else if (index == size)
        {
            node->prev = this->last;
            last->next = node;
            last = node;
        }
        else
        {
            Inode pointer = this->begin() + index;
            node->next = *pointer;
            node->prev = (*pointer)->prev;
            (*pointer)->prev->next = node;
            (*pointer)->prev = node;
        }
        ++size;
    }

    void delNodes(Inode pointer, int n)
    {
        for (int i = 0; i < n; i++)
        {
            Node *toDelete = *pointer;
            pointer = pointer + 1;
            if (toDelete->prev)
                toDelete->prev->next = toDelete->next;
            else
                first = toDelete->next;

            if (toDelete->next)
                toDelete->next->prev = toDelete->prev;
            else
                last = toDelete->prev;
            delete toDelete;
            --size;
        }
    }
};
















double function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    double arr[6] = {double(a), double(b), double(c), double(d), double(e), f};
    double *max = new double(3);
    double *min = new double(3);
    // 1 6 4 3 2 5
    for (size_t i = 0; i < 6; i++)
    {

        bool acc = true;
        bool acc2 = false;
        for (size_t i1 = 0; i1 < 3; i1++)
        {
            if (arr[i] > max[i1] && acc)
            {
                acc = false;
                if (i < 5)
                    max[i1 + 1] = max[i1];
                max[i1] = arr[i];
            }

            if (arr[i] < min[i1] && acc2)
            {
                acc2 = false;
                if (i < 5)
                    min[i1 + 1] = min[i1];
                min[i1] = arr[i];
            }
        }
    }

    double sum_max = max[0] + max[1] + max[2];
    double sum_min = min[0] + min[1] + min[2];
    double some_value;
    if (sum_max > sum_min * 2)
    {
        some_value = sum_max * sum_min;
    }
    else if (sum_max > sum_min * 3)
    {
        some_value = sum_max / sum_min;
    }
    else if (sum_max > sum_min * 3)
    {
        some_value = sum_max + sum_min;
    }
    else
    {
        some_value = 0; // :(
    }

    double result = some_value / MY_VARIANT;
    cout << result << endl;
    return result;
}

double **function_2(double x)
{
    double **matrix = new double *[5];
    for (int i = 0; i < 5; ++i)
    {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; ++j)
        {
            matrix[i][j] = x;
        }
    }

    {
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i1 = 0; i1 < 5; i1++)
            {
                double new_value = (matrix[i][i1] + MY_VARIANT + i1 - i) * (rand() % 100);
                matrix[i][i1] = new_value;

                cout << matrix[i][i1] << " ";
            }
            cout << endl;
        }
    }

    return matrix;

    // нове_значення=(поточне_значення+номер_варіанту+індекс_стовбця−індекс_стрічки)∗rand(1,100)
}

double* function_3(double **matrix)
{
    double *arr = new double(5);
    double *min1 = new double(5);
    double *min2 = new double(5);
    BST<double> tree;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i1 = 0; i1 < 5; i1++)
        {
            if (matrix[i][i1] < min1[i])
            {
                min1[i] = matrix[i][i1];
                tree.insert(matrix[i][i1]);
            }
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        min2[i] = tree.bMin();
    }

    bool acc = true;
    for (size_t i = 0; i < 5; i++)
    {
        if (min1[i] != min2[i])
            acc = false;
    }

    if (acc)
    {
        cout << "Algorithm works correctly\n";
    }
    else
    {
        cout << "Not works :(\n";
    }
    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = min1[i];
    }
    return arr;
}





string RANDOMIZER(const int len) {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}//вкрав на stackoverflow


DCL<student> function_4(double* arr){
    double max = -999999;     
    for (size_t i = 0; i < 5; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    double min = 999999;     
    for (size_t i = 0; i < 5; i++)
    {
        if(arr[i] < min){
            max = arr[i];
        }
    }
    
    double el_sum = 0;
    for (size_t i = 0; i < 5; i++)
    {
        el_sum += arr[i];
    }
    
    

    DCL<student> list;
    

    student student1 = {RANDOMIZER(5), RANDOMIZER(5), max};
    student student2 = {RANDOMIZER(7), RANDOMIZER(5), el_sum};
    student student3 = {RANDOMIZER(5), RANDOMIZER(5), el_sum};
    student student4 = {RANDOMIZER(5), RANDOMIZER(15), el_sum};
    student student5 = {RANDOMIZER(4), RANDOMIZER(5), el_sum};
    student student6 = {RANDOMIZER(5), RANDOMIZER(5), el_sum};
    student student7 = {RANDOMIZER(9), RANDOMIZER(12), min};

    list.insert(0, student1);
    list.insert(1, student1);
    list.insert(2, student1);
    list.insert(3, student1);
    list.insert(4, student1);
    list.insert(5, student1);
    list.insert(6, student1);


    list << " \n";

    return list;
}



int main()
{
    double x = function_1();

    double **tower = function_2(x);

    double* arr = function_3(tower);

    DCL<student> list = function_4(arr);

    return 0;
}