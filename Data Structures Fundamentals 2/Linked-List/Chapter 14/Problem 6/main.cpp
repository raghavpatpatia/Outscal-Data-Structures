#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
private:
    int GetLength(Node* head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }

public:
  Node *reverse(Node *head, int k) {
    // Write your code here
    if (!head || k == 1) return head;
    
    int length = GetLength(head);
    Node* node = new Node();
    node->next = head;
    Node* prevGroupEnd = node;

    for (int i = 0; i < length / k; i++) 
    {
        Node* groupStart = prevGroupEnd->next;
        Node* current = groupStart;
        Node* prev = nullptr;
        Node* next = nullptr;

        for (int j = 0; j < k; j++) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        prevGroupEnd->next = prev;
        groupStart->next = current;
        prevGroupEnd = groupStart;
    }
    
    return node->next;
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
  int n, value, k;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cin >> k;
  class Outscal s;
  Node *temp = s.reverse(head, k);
  printList(temp);
  return 0;
}