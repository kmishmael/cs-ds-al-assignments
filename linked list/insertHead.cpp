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
    void insertTail(int newElement)
    {
        Node *rootNode = this;

        Node *ptr = rootNode;

        Node *newNode = new Node(newElement);

        while (ptr != NULL)
        {
            if (ptr->next == NULL)
            {
                ptr->next = newNode;
                return;
            }
            ptr = ptr->next;
        }
    }

    Node *insertHead(int newElement)
    {
        Node *newRootNode = new Node(newElement);

        newRootNode->next = this;

        return newRootNode;
    }
};

int main()
{
    // create the handle to the linked list
    Node *myList;

    // Intended size of list and array to use to populate the list
    int size = 5;
    int myArray[] = {20, 30, 40, 50};

    // Create the first node aka the head
    myList = new Node(10);

    // Insert the rest of the elements. Take careful note of the limits of the loop
    for (int i = 0; i < size - 1; i++)
    {
        myList->insertTail(myArray[i]);
    }

    // Print the list to confirm its status
    myList->printList();

    // insert two new elements at the front of the list
    myList = myList->insertHead(7);
    myList = myList->insertHead(4);

    myList->printList();
    
    return 0;
}