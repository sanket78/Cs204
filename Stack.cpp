#include <iostream>

using namespace std;

class Stack
{
    private:
        int capacity;
        int top;
        int* array;
    public:
        Stack(int capacity);
        void push(int x);
        void pop();
        void peek();
        void isEmpty();
        void size();
        void isFull();
};

Stack::Stack(int capacity)
{
    top = -1;
    Stack::capacity = capacity;
    array = new int[capacity];
}

void Stack::push(int x)
{
    if(top < capacity-1)
    {
        top = top+1;
        array[top] = x;
        cout << "Element " << x << " is pushed in" << endl;
    }
    else
        cout << "Stack Overflow" << endl;
}

void Stack::pop()
{
    if(top > -1)
    {
        cout << "Element " << array[top] << " is popped out" << endl;
        top = top-1;
    }
    else
        cout << "Stack Underflow" << endl;
}

void Stack::peek()
{
    if(top > -1)
        cout << "Element " << array[top] << " is at top" << endl;
    else
        cout << "Stack is empty" << endl;
}

void Stack::isEmpty()
{
    if(top > -1)
        cout << "Stack is not empty" << endl;
    else
        cout << "Stack is empty" << endl;
}

void Stack::size()
{
    cout << "Size of stack is " << top+1 << endl;
}

void Stack::isFull()
{
    if(top+1 == capacity)
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;
}

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.isFull();
    s.push(3);
    s.isFull();
    s.push(4);
    s.isFull();
    s.pop();
    s.peek();
    s.isEmpty();
    s.pop();
    s.isEmpty();
    s.isFull();
    s.pop();
    s.isEmpty();
    s.peek();
    s.pop();
    s.isFull();
    s.isEmpty();
    s.peek();
    return 0;
}