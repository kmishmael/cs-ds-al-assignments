#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }

    bool push(int newElement)
    {
        if (isFull())
        {
            return false;
        }
        else
        {
            top++;
            arr[top] = newElement;
            return true;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            int popValue = arr[top];
            top--;
            return popValue;
        }
    }

    int size()
    {
        return (top + 1);
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void printStack()
    {
        // if the stack is empty print -1
        if (top < 0)
        {
            cout << -1 << endl;
            return;
        }
        // if not empty, print elements in the stack
        for (int i = 0; i < top + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
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
