#include <iostream>
using namespace std;

// Node structure that represents each element in the list
struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {} // default constructor, the next is always a null pointer since we dont know where this node will be 
};

class LinkedList {
  private:
    Node* head; // start with a head node that points nowhere

  public:
    LinkedList() : head(nullptr) {}

    // inserts an element at the HEAD of the list
    void insert(int data) {
      Node* newNode = new Node(data);
      newNode->next = head;
      head = newNode;
    }

    // delete a node given a key
    void deleteNode(int key) {
      Node* temp = head;
      Node* prev = nullptr;

      // if the head contains the key
      if (temp != nullptr && temp->data == key) {
        head = temp->next; // move the head (pointer) the next node...
        delete temp; // ...and delete the head node
        return;
      }

      // otherwise, iterate through the linked list searching for key
      while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
      }

      if (temp == nullptr) return; // if we reach the end of the list without finding the  key, simply return

      prev->next = temp->next; // delete the found node and clean up the pointers
      delete temp;
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
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.printList();

  list.deleteNode(2);
  list.printList();

  return 0;
}
