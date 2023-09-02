#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  bool detectpalindrome(Node *head) {
    // Write your code here
    if (!head || !head->next) return true;

    Node* first = head;
    Node* second = head;
    while (second && second->next)
    {
        first = first->next;
        second = second->next->next;
    }

    if (second && !second->next)
    {
        first = first->next;
    }

    Node* previous = nullptr;
    Node* temp = nullptr;
    while (first && first->next)
    {
        temp = first->next;
        first->next = previous;
        previous = first;
        first = temp;
    }
    if (first) first->next = previous;

    second = head;
    while (first && second)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
  }
};

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
  int n, value;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  class Outscal s;
  bool t = s.detectpalindrome(head);
  if (t)
    cout << "true";
  else
    cout << "false";
  return 0;
}