#include <iostream>
using namespace std;


class My_List{
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head = nullptr;

public:
    My_List(): head(nullptr) { }
    ~My_List() {
        while (head) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void Push_front(const int& value){
        if(head == nullptr){
            head = new Node{value, nullptr};
        }else{
            Node* temp = head;
            head = new Node{value, temp};
        }
    }

    void Show(){
        if(head == nullptr){
            cout << "List is empty\n";
        }
        else{
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
    int Size(){
        Node* temp = head;
        int size = 0;
        while(temp){
            size += 1;
            temp = temp->next;
        }
        return size;
    }     
    Node* Index(const int index){ 
        if(!head){
            return nullptr;
        }
        Node* temp = head;
        int n = Size();
        for(int i = 0; i<n; i++){
            if(i != index){
                temp = temp->next;
            } else return temp;
        }
    }

    void Swap(Node* l1, Node* l2){
        if(l1 && l2){
            int a = l1->data;
            l1->data = l2->data;
            l2->data = a;
        }
        
    }

    void list_bubble_sort(){
        int size = Size();
        bool swapped;

        for(int i = 0; i<size-1; i++){
            swapped = false;
            for(int j = 0; j<size-i-1; j++){
                Node* node1 = Index(j);
                Node* node2 = Index(j + 1);
                if(node1->data > node2->data){
                    Swap(node1, node2);
                    swapped = true;

                }
            }
            if (!swapped) break;
        }
    }

};




int main() {
    My_List List;
    List.Push_front(1);
    List.Push_front(5);
    List.Push_front(6);
    List.Push_front(3);
    List.Push_front(4);

    cout << "Original List: ";
    List.Show();

    List.list_bubble_sort();

    cout << "Sorted List: ";
    List.Show();

    return 0;
}
