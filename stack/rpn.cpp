#include <iostream>
#include <string>

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


int reversePolish(Stack myStack, string myExpression)
{
    for (int i = 0; i < myExpression.length(); i++)
    {
        char current = myExpression[i];

        if (isdigit(current))
        {
            myStack.push(current % 48);
        }

        else
        {
            int last = myStack.peek();
            myStack.pop();
            int root = myStack.peek();
            myStack.pop();
            int result;

            switch (current)
            {
            case '+':
                result = root + last;
                break;
            case '-':
                result = root - last;
                break;
            case '*':
                result = root * last;
                break;
            case '/':
                result = root / last;
                break;
            default:
                break;
            }

            myStack.push(result);
        }
    }

    return myStack.peek();
}

int main()
{
    Stack myStack; // this assumes you have already implemented the Stack class
    string expression;
    expression = "512+4*+3-";
    cout << reversePolish(myStack, expression);
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
    if (stackIndex < 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < stackIndex + 1; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}
