#include <iostream>
#include <vector>

template <typename T>
class Node
{
public:
    Node() : next(nullptr) {}
    T data;
    Node* next;
};

template <typename P>
class LinkedList
{
private:
    Node<P>* head;
public: 
    LinkedList() : head(nullptr){}
    void Append(P value)
    {
        Node<P>* node = new Node<P>();
        node->data = value;
        if (head == nullptr)
        {
            head = node;
            return; 
        }
        Node<P>* lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = node;
    }

    Node<P>* GetHead()
    {
        return head;
    }

    void Print()
    {
        if (head == nullptr) 
        {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }
        Node<P>* node = head;
        while (node != nullptr)
        {
            std::cout << "Node -> " << node->data << std::endl;
            node = node->next;
        }
    }
};

template <typename R>
class LinkedListSolution
{
private:
    Node<R>* MergeTwoLists(Node<R>* list1, Node<R>* list2)
    {
        if (!list1) return list2;
        if (!list2) return list1;
        Node<R>* temp = new Node<R>();
        temp->next = list1;
        Node<R>* tail = temp;
        Node<R>* p1 = list1;
        Node<R>* p2 = list2;
        Node<R>* head;
        while (p1 && p2)
        {
            if (p1->data <= p2->data)
            {
                tail->next = p1;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        tail->next = p1 ? p1 : p2;
        head = temp->next;
        delete temp;
        return head;
    }

    Node<R>* Merge (std::vector<Node<R>*> &lists, int i, int j)
    {
        if (j - i == 0)
            return lists[i];
        
        int mid = i + (j - i) / 2;
        Node<R>* leftMerge = Merge(lists, i , mid);
        Node<R>* rightMerge = Merge(lists, mid + 1, j);
        return MergeTwoLists(leftMerge, rightMerge); 
    }
public:
    Node<R>* MergeLists(std::vector<Node<R>*>& lists)
    {
        int n = lists.size();
        if (n == 0)
            return nullptr;

        Node<R>* head = Merge(lists, 0, n - 1);
        return head;
    }

    void PrintMergedLists(std::vector<Node<R>*>& lists)
    {
        Node<R>* mergedHead = MergeLists(lists);

        LinkedList<R>* mergedList = new LinkedList<R>();
        Node<R>* node = mergedHead;
        while (node != nullptr)
        {
            mergedList->Append(node->data);
            node = node->next;
        }
        mergedList->Print();
    }
};

int main()
{
    LinkedList<int> *ll1 = new LinkedList<int>();
    LinkedList<int> *ll2 = new LinkedList<int>();
    LinkedList<int> *ll3 = new LinkedList<int>();
    std::cout << "Linked List-1:" << std::endl;
    ll1->Append(10);
    ll1->Append(20);
    ll1->Append(30);
    ll1->Print();
    std::cout << "Linked List-2:" << std::endl;
    ll2->Append(1);
    ll2->Append(5);
    ll2->Append(7);
    ll2->Print();
    std::cout << "Linked List-3:" << std::endl;
    ll3->Append(15);
    ll3->Append(25);
    ll3->Append(35);
    ll3->Print();

    LinkedListSolution<int>* merged = new LinkedListSolution<int>();
    std::vector<Node<int>*> lists = {ll1->GetHead(), ll2->GetHead(), ll3->GetHead()};
    std::cout << "Merged Linked List: " << std::endl;
    merged->PrintMergedLists(lists);

    delete ll1;
    delete ll2;
    delete ll3;
    delete merged;

    return 0;
}
