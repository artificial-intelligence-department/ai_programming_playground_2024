#include <iostream>
using namespace std;

struct Node {
 int data;
 Node* next;

 Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
 while (head != nullptr) {
  cout << head->data << " ";
  head = head->next;
 }
 cout << endl;
}

Node* reverse(Node* head) {
 Node* prev = nullptr;
 Node* current = head;
 Node* next = nullptr;

 while (current != nullptr) {
  next = current->next;
  current->next = prev;
  prev = current;
  current = next;
 }
 return prev;
}

bool compare(Node* h1, Node* h2) {
 while (h1 != nullptr && h2 != nullptr) {
  if (h1->data != h2->data) {
   return false;
  }
  h1 = h1->next;
  h2 = h2->next;
 }
 return h1 == nullptr && h2 == nullptr;
}

Node* add(Node* n1, Node* n2) {
 Node* result = nullptr;
 Node* tail = nullptr;
 int carry = 0;

 while (n1 != nullptr || n2 != nullptr || carry > 0) {
  int sum = carry;

  if (n1 != nullptr) {
   sum += n1->data;
   n1 = n1->next;
  }

  if (n2 != nullptr) {
   sum += n2->data;
   n2 = n2->next;
  }

  carry = sum / 10;
  int digit = sum % 10;

  Node* newNode = new Node(digit);
  if (result == nullptr) {
   result = newNode;
   tail = result;
  } else {
   tail->next = newNode;
   tail = tail->next;
  }
 }
 return result;
}

int main() {
 Node* list1 = new Node(1);
 list1->next = new Node(2);
 list1->next->next = new Node(3);

 Node* list2 = new Node(1);
 list2->next = new Node(2);
 list2->next->next = new Node(3);

 cout << "Original list 1: ";
 printList(list1);
 list1 = reverse(list1);
 cout << "Reversed list 1: ";
 printList(list1);

 cout << "Comparison of lists: ";
 if (compare(list1, list2)) {
  cout << "Lists are equal." << endl;
 } else {
  cout << "Lists are not equal." << endl;
 }

 Node* num1 = new Node(9);
 num1->next = new Node(7);
 num1->next->next = new Node(3);

 Node* num2 = new Node(4);
 num2->next = new Node(6);
 num2->next->next = new Node(5);

 cout << "Number 1: ";
 printList(num1);
 cout << "Number 2: ";
 printList(num2);

 Node* sum = add(num1, num2);
 cout << "Sum of numbers: ";
 printList(sum);

 return 0;
}
