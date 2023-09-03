#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  Node *partition(Node *head, int val) {
    // Write your code here
    if (!head) return nullptr;
    Node* lessHead = new Node();
    Node* greaterHead = new Node();
    Node* lessCurrent = lessHead;
    Node* greaterCurrent = greaterHead;
    Node* current = head;

    while (current)
    {
        if (current->data < val)
        {
            lessCurrent->next = current;
            lessCurrent = lessCurrent->next;
        }
        else
        {
            greaterCurrent->next = current;
            greaterCurrent = greaterCurrent->next;
        }
        current = current->next;
    } 

    greaterCurrent->next = nullptr;
    lessCurrent->next = greaterHead->next;
    delete greaterHead;
    head = lessHead->next;
    delete lessHead;
    return head;
  }
};

void printList(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

void push(Node **head_ref, int new_data) {
  Node *new_node = new Node();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

int main() {
  int n, value, val;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cin >> val;
  class Outscal s;
  Node *temp = s.partition(head, val);
  printList(temp);
  return 0;
}