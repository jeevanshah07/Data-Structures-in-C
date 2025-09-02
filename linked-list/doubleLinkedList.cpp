#include <iostream>
using namespace std;

struct Node {
  int data;

  Node* next;
  Node* prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
  Node* head;

public:
  DoubleLinkedList(): head(nullptr) {}

  void insert(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;

    if (head != nullptr) {
      head->prev = newNode;
    }

    head = newNode;
  }

  void insertAt(int key, int data) {
    Node* temp = head;

    if (temp != nullptr && temp->data == key) {
      insert(data);
      return;
    }

    Node* newNode = new Node(data);
    Node* prev = nullptr;

    while (temp!= nullptr && temp->data != key) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == nullptr) return;

    newNode->next = temp;
    newNode->prev = prev;

    temp->prev = newNode;
    prev->next = newNode;
  }

  void insertAtTail(int data) {
    Node* temp = head;
    Node* prev = nullptr;
    Node* newNode = new Node(data);

    while (temp->next != nullptr) {
      prev = temp;
      temp = temp->next;
    }

    if (temp->next == nullptr) {
      temp->next=newNode;
      newNode->prev = temp;
    }

    return;
  }

  void deleteNode(int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // check if head is the node to be deleted
    if (temp != nullptr && temp->data == key) {
      head = temp->next; // adjust pointers accordingly
      temp->prev = nullptr;

      delete temp;
      return;
    }

    while (temp != nullptr && temp-> data != key) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == nullptr) return; 

    prev->next = temp->next;
    prev->prev = temp->prev;

    delete temp;
  }

  void deleteLast() {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp->next != nullptr) {
      prev = temp;
      temp = temp->next;
    }

    if (temp->next == nullptr) {
      prev->next = nullptr;
      delete temp;
      return; 
    }

    return;
  }

  void printList() {
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp-> data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};


int main() {
  DoubleLinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);

  list.printList();

  list.deleteNode(3);

  list.printList();

  list.insertAt(5, 0);

  list.printList();

  list.deleteLast();

  list.printList();

  list.insertAtTail(99);

  list.printList();

  return 0;
}
