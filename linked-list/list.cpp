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

    void insertAt(int key, int data) {
      Node* temp = head; 

      if (temp != nullptr && temp->data == key) { // if the data corresponds to the head, simply call the insert function
        insert(data);
        return;
      }

      Node* newNode = new Node(data);
      Node* prev = nullptr;

      // otherwise, iterate through the list to find the key

      while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
      }

      if (temp == nullptr) return; // if we don't find the key, don't modify the list

      // insert the new data and adjust the pointers accordingly
      newNode->next = temp;
      prev->next = newNode;
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

    void reverse() {
      Node* prev = nullptr;
      Node* current = head;
      Node* next = nullptr;

      while (current != nullptr) { 
        next = current->next;
        current->next = prev;
        prev=current;
        current=next;
      }
      head=prev;
      return;
    }
};

int main() {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);

  list.insertAt(3, 5);
  list.printList();

  list.insertAt(5, 0);

  list.printList();

  list.reverse();

  list.printList();

  return 0;
}
