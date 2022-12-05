#include <iostream>

using namespace std;

class Stack
{

    int stack[5];
    int stackIndex;

public:
    Stack()
    {
        stackIndex = -1;
    }
    int size();
    bool isEmpty();
    bool push(int newElement);
    int pop();
    int peek();
    void printStack();
};

int main()
{
    Stack vanillaStack;

    // Print out the current size of vanillaStack
    cout << vanillaStack.size() << endl; // size should be 0

    if (vanillaStack.push(5))
        vanillaStack.printStack(); // output should be: 5
    if (vanillaStack.push(3))
        vanillaStack.printStack(); // output should be: 5 3
    if (vanillaStack.push(8))
        vanillaStack.printStack(); // output should be: 5 3 8
    if (vanillaStack.push(6))
        vanillaStack.printStack(); // output should be: 5 3 8 6
    if (vanillaStack.push(7))
        vanillaStack.printStack(); // output should be: 5 3 8 6 7
    if (vanillaStack.push(10))
        vanillaStack.printStack(); // no output due to stack overflow

    // Print out the current size of vanillaStack
    cout << vanillaStack.size() << endl; // size should be 5
    cout << vanillaStack.peek() << endl; // element at the top should be 7

    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3 8 6
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3 8
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: -1

    // Try to pop from an empty stack
    cout << vanillaStack.pop() << endl;

    return 0;
}

int Stack::size()
{
    return stackIndex + 1;
}

bool Stack::isEmpty()
{
    if (stackIndex < 0)
    {
        return true;
    }
    return false;
}

bool Stack::push(int newElement)
{
    if (stackIndex < 4 && newElement != -1)
    {
        stackIndex++;
        stack[stackIndex] = newElement;
        return true;
    }
    return false;
}

int Stack::pop()
{
    if (stackIndex < 0)
    {
        return -1;
    }
    return stack[--stackIndex];
}

int Stack::peek()
{
    if (stackIndex < 0)
    {
        return -1;
    }
    return stack[stackIndex];
}
void Stack::printStack()
{
    if(stackIndex < 0 ){
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < stackIndex + 1; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}