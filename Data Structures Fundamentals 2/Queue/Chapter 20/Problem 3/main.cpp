#include <iostream>
#include <queue>

int main()
{
    std::queue<int>* q = new std::queue<int>();
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    std::cout << "...Printing Queue..." << std::endl;
    while (!q->empty())
    {
        std::cout << q->front() << std::endl;
        q->pop();
    }
    delete q;
    return 0;
}