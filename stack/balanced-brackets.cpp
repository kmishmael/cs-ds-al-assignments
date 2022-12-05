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

int balancedBrackets(Stack stack, string brackets)
{
    for (int i = 0; i < (int)brackets.length(); i++)
    {
        char current = brackets[i];
        if (current == '<' || current == '{' || current == '[' || current == '(')
        {
            // opening brackets
            stack.push(current);
        }
        else
        {
            // closing brackets

            if(stack.isEmpty()){
                return i;
            }
            int opening = stack.peek();
            switch (opening)
            {
            case 40:
                if (int(current) != 41)
                {
                    return i;
                }
                break;
            case 91:
                if (int(current) != 93)
                {
                    return i;
                }
                break;
            case 123:
                if (int(current) != 125)
                {
                    return i;
                }
                break;
            case 60:
                if (int(current) != 62)
                {
                    return i;
                }
                break;
            default:
                break;
            }
            stack.pop();
        }
    }

    if (stack.isEmpty())
    {
        return -1;
    }

    return 0;
}

int main()
{
    Stack myStack;
    int result;
    string brackets = "{[(>)}";
    result = balancedBrackets(myStack, brackets);
    cout << result;
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
