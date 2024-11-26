#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Node{
    int val;
    Node* next;

    Node(){
        next = nullptr;
    }

    Node(int val, Node* node = nullptr){
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList{
    Node* head;
    int size;
    std::string fileName;
    

    public:

    LinkedList(){
        size = 0;
        head = nullptr;
        fileName = "";
        };

    LinkedList(int val){
        head = new Node(val);
        size = 1;
        fileName = "";
    }

    void const insert(int i, std::vector<int>& vec){
        Node* temp = head;
        int index = 1;
        int const SIZE = vec.size();
        if(i == 0 || size == 0){
            Node* newHead = new Node(vec[0]);
            temp = newHead;
            for(int i = 1; i < SIZE; i++){
                    temp->next = new Node(vec[i]);
                    temp = temp->next;
                }
            temp->next = head;
            head = newHead;
        }
        else{
            while(temp != nullptr){
                if(index == i){
                    Node* next = temp->next;
                    temp->next = new Node(vec[0]);
                    temp = temp->next;
                    for(int i = 1; i < SIZE; i++){
                        temp->next = new Node(vec[i]);
                        temp = temp->next;
                    }
                    temp->next = next;
                    break;
                }
                temp = temp->next;
                index++;
            }
        }
        size += vec.size();
    }

    void deleteElems(int i, int size = -1){
        size = i + size > this->size ? this->size - i : size;
        this->size -= size;
        if(size == -1) {
            i = 0;
            size = this->size;
        }
        Node* temp = head;
        Node* prev;
        if(this->size == 0) return;
        int index = 1;
        if(i == 0){
            while(size && temp != nullptr){
                prev = temp;
                temp = temp->next;
                delete prev;
                size--;
            }
            head = temp;
        }
        else {
            while(index != i){
                temp = temp->next;
                index++;

            }
            Node* cHead = temp;
            temp = temp->next;
            while(size && temp != nullptr){
                prev = temp;
                temp = temp->next;
                delete prev;
                size--;
            }
            cHead->next = temp;
        }
    }


    void const saveToFile(const std::string& fileName){
        this->fileName = fileName;
        std::ofstream file(fileName, std::ofstream::out | std::ofstream::binary);
        if(file){
            file.write(reinterpret_cast<char*> (&size), sizeof(size));
            Node* temp = head;
            while(temp != nullptr){
                file.write(reinterpret_cast<char*>(&temp->val), sizeof(temp->val));
                temp = temp->next;
            }
            deleteElems(0);
        }
        
        file.close();
    }

    void const getFromFile(const std::string& fName = ""){
        if(fName != "") fileName = fName;
        std::ifstream file(fileName, std::ifstream::in | std::ifstream::binary);
        deleteElems(0);
        if(file){
            file.read(reinterpret_cast<char*> (&size), sizeof(size));
            if(size != 0){
                head = new Node();
                file.read(reinterpret_cast<char*> (&head->val), sizeof(head->val));
                Node* temp = head;
                for(int i = 1; i < size; i++){
                    temp->next = new Node();
                    file.read(reinterpret_cast<char*>(&temp->next->val), sizeof(temp->next->val));
                    temp = temp->next;
                }
            }
            
        }
        file.close();
    }

    void const show(){
        if(size == 0){
            std::cout << "List is empty\n";
            return;
        }
        Node* temp =head;
        while(temp != nullptr){
            std::cout << temp->val << "  ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }



    ~LinkedList(){
        deleteElems(0);
    }
};

int main(){
    LinkedList linkedList;
    int q = -1;
    int i, size;
    std::vector<int> vals;
    std::string fileName;
    while(q != 0){
        std::cout << "[1] - to add elements\n[2] - to remove elements\n[3] - save list to file\n[4] - get list from file\n[5] - to show list\n[0] - to exit\n";
        std::cin >> q;
        vals.clear();
        switch (q)
        {
        case 1:
            std::cout << "Index at which to add elements: ";
            std::cin >>i;
            std::cout << "Enter number of elements you want to add: ";
            std::cin >> size;
            std::cout << "Enter values: ";
            for(int j = 0; j < size;j++){
                std::cin >> q;
                vals.push_back(q);
            }
            linkedList.insert(i, vals);
            break;
        case 2:
            std::cout << "Index at which to start deleting elements: ";
            std::cin >>i;
            std::cout << "Enter number of elements you want to delete: ";
            std::cin >> size;
            linkedList.deleteElems(i, size);
            break;
        case 3:
            std::cout << "Enter file name to save in: ";
            std::cin >> fileName;
            linkedList.saveToFile(fileName);
            break;
        case 4:
            std::cout << "Enter file name to get list from: ";
            std::cin >> fileName;
            linkedList.getFromFile(fileName);
            break;
        case 5:
            linkedList.show();
            break;
        case 0:
            break;
        default:
            std::cout << "Wrong input!\n";
            break;
        }
    }
}