#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

class LinkedList
{
  private:
    Node *head;
    int totalNode;
  public:
    LinkedList()
    {
      head = NULL;
      totalNode = 0;
    }

    void add(int _data)
    {
      Node *node = new Node();
      node->data = _data;
      node->next = NULL;

      if(head == NULL)
      {
        head = node;
      }
      else
      {
        Node *lastNode = head;
        while(lastNode->next != NULL)
        {
          lastNode = lastNode->next;
        }
        lastNode->next = node;
      } 
      totalNode++;
    }

    void AddAtPosition(int pos, int _data)
    {
      Node *node = new Node();
      node->data = _data;
      node->next = NULL;
      
      if(head == NULL && totalNode - pos == 0)
      {
          head = node;
      }
      else 
      {
        if(head == NULL && pos != totalNode - pos)
        {
          cout << "\nList is Empty "<<endl;
          cout << "\nAdding element At head" << endl;
          head = node;     
          pos = 0;
        }
        else 
        {
          Node *temp = head;
          int count = 0;
          
          while(totalNode - pos != count)
          {
            temp = temp->next;                 
            count++;
          }
  
          node->next = temp->next;
          temp->next = node;           
        }
      }
      cout <<"Entered Element in position "<< pos <<endl;
      totalNode++;
    }

    void RemoveAt(int pos)
    {
      Node *node = head;
      Node *prev = NULL;

      if(head == NULL)
      {
        cout <<"\nList is Empty"<<endl;
      }
      else
      {
        int count = 0;
        while(totalNode - pos - 1 != count)
        {
          prev = node;
          node = node->next;
          count++;
        }

        prev->next = node->next;
        delete node;
        cout <<"Node Deleted At position "<< pos <<endl; 
      }   
      totalNode--;           
    }

    void display()
    {
      Node *node = head;
      if(head == NULL)
      {
        cout <<"\nList is Empty "<<endl;
      }
      else
      {
        while(node != NULL)
        {
          cout << node->data << " ";
          node = node->next;
        }
        cout << endl;
      }      
    }
};

int main() 
{
  LinkedList *list = new LinkedList();

  list->display();
  list->add(10);
  list->add(20);
  list->add(30);
  list->add(40);
  list->add(50);
  list->display();
  
  list->RemoveAt(3);
  list->display();

  list->AddAtPosition(2,25);
  list->AddAtPosition(2,555);
  list->display();
}