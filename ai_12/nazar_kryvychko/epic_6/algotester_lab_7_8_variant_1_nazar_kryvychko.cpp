#include <iostream>
#include <vector>
#include <string>
#include <sstream>

enum class operationE {
    insert, erase, size, get, set, print, none
};

operationE parse(const std::string& str) {
    if (str == "erase") return operationE::erase;
    if (str == "insert") return operationE::insert;
    if (str == "size") return operationE::size;
    if (str == "get") return operationE::get;
    if (str == "set") return operationE::set;
    if (str == "print") return operationE::print;
    return operationE::none;
}

template <class T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(T value, Node* next = nullptr, Node* prev = nullptr)
            : value(value), next(next), prev(prev) {}
    };

    Node* head;
    Node* tail;
    std::size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    void insert(int index, int elCount, const std::vector<T>& els) {
        if (index < 0 || index > size || elCount <= 0) return;

        Node* newHead = new Node(els[0]);
        Node* current = newHead;

        for (int i = 1; i < elCount; ++i) {
            current->next = new Node(els[i], nullptr, current);
            current = current->next;
        }

        if (index == 0) {
            if (head) {
                current->next = head;
                head->prev = current;
            }
            head = newHead;
            if (size == 0) {
                tail = current;
            }
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            current->next = prev->next;
            if (prev->next) {
                prev->next->prev = current;
            }
            prev->next = newHead;
            newHead->prev = prev;

            if (index == size) {
                tail = current;
            }
        }
        size += elCount;
    }

    void erase(int index, int count) {
        if (index < 0 || index >= size || count <= 0) return;

        if (index == 0) {
            Node* temp = head;
            for (int i = 0; i < count && temp; ++i) {
                Node* next = temp->next;
                delete temp;
                temp = next;
                --size;
            }
            head = temp;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            Node* current = prev->next;
            for (int i = 0; i < count && current; ++i) {
                Node* next = current->next;
                delete current;
                current = next;
                --size;
            }
            prev->next = current;
            if (current) {
                current->prev = prev;
            } else {
                tail = prev;
            }
        }
    }

    std::size_t get_size() const {
        return size;
    }

    T get(std::size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        Node* tmpStep = head;
        for (size_t i = 0; i < index; ++i) {
            tmpStep = tmpStep->next;
        }
        return tmpStep->value;
    }

    void set(std::size_t index, T val) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        Node* tmpStep = head;
        for (size_t i = 0; i < index; ++i) {
            tmpStep = tmpStep->next;
        }
        tmpStep->value = val;
    }

    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
        Node* temp = list.head;
        while (temp != nullptr) {
            out << temp->value << ' ';
            temp = temp->next;
        }
        return out;
    }
};

int main() {
    LinkedList<int> list;
    unsigned int Q;
    std::cin >> Q;
    std::string tmpOpStr;

    for (size_t i = 0; i < Q; ++i) {
        std::cin >> tmpOpStr;

        operationE parseOp = parse(tmpOpStr);
        switch (parseOp) {
            case operationE::insert: {
                int index, n;
                std::cin >> index >> n;
                std::vector<int> N(n);
                for (int& num : N) {
                    std::cin >> num;
                }
                list.insert(index, n, N);
                break;
            }
            case operationE::size:
                std::cout << list.get_size() << std::endl;
                break;
            case operationE::get: {
                int index;
                std::cin >> index;
                std::cout << list.get(index) << std::endl;
                break;
            }
            case operationE::set: {
                int index, value;
                std::cin >> index >> value;
                list.set(index, value);
                break;
            }
            case operationE::print:
                std::cout << list << std::endl;
                break;
            case operationE::erase: {
                int index, count;
                std::cin >> index >> count;
                list.erase(index, count);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
