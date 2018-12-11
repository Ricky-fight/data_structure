#include "List.h"
class Stack
{
private:
    List list;
    int  stackSize;
public:
    Stack();
    ~Stack();
    int pop();
    int top() const;
    int size() const;
    void push(int const e);
    bool empty() const;
};
Stack::Stack()
{
    stackSize = 0;
}
Stack::~Stack()
{
}
int Stack::pop()
{
    if (list.empty())
    {
        throw underflow();
    }
    --stackSize;
    return list.pop_front();
}
int Stack::top() const
{
    if (list.empty())
    {
        throw underflow();
    }
    return list.front();
}
int Stack::size() const
{
    return stackSize;
}
bool Stack::empty() const
{
    return stackSize==0;
}
void Stack::push(int const e)
{   
    stackSize++;
    list.push_front(e);
}