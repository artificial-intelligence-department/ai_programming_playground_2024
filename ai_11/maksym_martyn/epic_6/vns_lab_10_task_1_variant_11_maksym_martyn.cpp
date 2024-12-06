#include <iostream>
#include <cstring>
using namespace std;

struct Node {
 char* key;
 Node* prev;
 Node* next;

 Node(const char* k) : prev(nullptr), next(nullptr) {
  key = new char[strlen(k) + 1];
  strcpy(key, k);
 }

 ~Node() {
  delete[] key;
 }
};

class DoublyLinkedList {
private:
 Node* head;
 Node* tail;

public:
 DoublyLinkedList() : head(nullptr), tail(nullptr) {}

 void addAtPosition(const char* key, int position) {
  Node* newNode = new Node(key);

  if (position == 0) {
   newNode->next = head;
   if (head) {
    head->prev = newNode;
   }
   head = newNode;
   if (!tail) {
    tail = newNode;
   }
   return;
  }

  Node* current = head;
  for (int i = 0; i < position - 1 && current; ++i) {
   current = current->next;
  }

  if (!current) {
   cout << "Position " << position << " exceeds list size.\n";
   delete newNode;
   return;
  }

  newNode->next = current->next;
  newNode->prev = current;

  if (current->next) {
   current->next->prev = newNode;
  } else {
   tail = newNode;
  }

  current->next = newNode;
 }

 void deleteByKey(const char* key) {
  Node* current = head;
  while (current) {
   if (strcmp(current->key, key) == 0) {
    if (current->prev) {
     current->prev->next = current->next;
    } else {
     head = current->next;
    }
    if (current->next) {
     current->next->prev = current->prev;
    } else {
     tail = current->prev;
    }
    delete current;
    cout << "Element with key \"" << key << "\" deleted.\n";
    return;
   }
   current = current->next;
  }
  cout << "Element with key \"" << key << "\" not found.\n";
 }

 void printList() {
  Node* current = head;
  cout << "List: ";
  while (current) {
   cout << current->key << " ";
   current = current->next;
  }
  cout << endl;
 }

 ~DoublyLinkedList() {
  Node* current = head;
  while (current) {
   Node* nextNode = current->next;
   delete current;
   current = nextNode;
  }
 }
};

int main() {
 DoublyLinkedList list;

 list.addAtPosition("first", 0);
 list.addAtPosition("second", 1);
 list.addAtPosition("third", 2);
 list.printList();

 list.deleteByKey("second");
 list.printList();

 list.addAtPosition("new", 1);
 list.printList();

 return 0;
}
