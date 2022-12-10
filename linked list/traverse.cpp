#include <iostream>

using namespace std;

class Node
{

private:
    int data;

public:
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
    void printList()
    {
        Node *currentNode = this;

        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";

            currentNode = currentNode->next;
        }

        cout << endl;
    }
};

int main()
{
    // create the handle to the linked list plus two other nodes
    Node *myList, *node2, *node3;

    // initialize pointer to the head node
    myList = new Node(10);

    // create another node
    node2 = new Node(20);
    // link then nodes
    myList->next = node2;

    // create a third node
    node3 = new Node(30);
    // link the nodes
    node2->next = node3;

    // Print the state of the linked list
    myList->printList();
    return 0;
}