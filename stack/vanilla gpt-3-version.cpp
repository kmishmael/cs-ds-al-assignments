
#include <iostream>

using namespace std;

class Stack {
private:
    int arr[5];
    int numElements;

public:
    Stack() {
        numElements = 0;
    }
    int size() {
        return numElements;
    }
    bool isEmpty() {
        return (numElements == 0);
    }
    bool push(int newElement) {
        if (numElements == 5) {
            return false;
        }
        arr[numElements] = newElement;
        numElements++;
        return true;
    }
    int pop() {
        if (numElements == 0) {
            return -1;
        }
        numElements--;
        return arr[numElements];
    }
    int peek() {
        if (numElements == 0) {
            return -1;
        }
        return arr[numElements - 1];
    }
    void printStack() {
        for (int i = 0; i < numElements; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
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