#include <iostream>

using namespace std;

class Node
{
public:
    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
    int value;
    Node *left;
    Node *right;

    int counter;

    Node *insertRecursive(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }

        if (value > node->value)
        {
            node->right = insertRecursive(node->right, value);
        }
        else
        {
            node->left = insertRecursive(node->left, value);
        }

        return node;
    }

    void insert(int fruit)
    {
        insertRecursive(this, fruit);
    }

    void recurseInOrder(Node *rootNode)
    {
        if (rootNode == NULL)
        {
            return;
        }
        else
        {
            recurseInOrder(rootNode->left);
            cout << rootNode->value << " ";
            recurseInOrder(rootNode->right);
        }
    };

    void inOrder()
    {

        Node *root = this;

        recurseInOrder(root);

        cout << endl;
    }

    int search(int fruit)
    {
        Node *rootNode = this;

        Node *ptr = rootNode;

        this->counter = 0;
        while (ptr != NULL)
        {
            if (ptr->value == fruit)
            {
                return this->counter;
            }

            if (fruit > ptr->value)
            {
                ptr = ptr->right;
                this->counter++;
            }
            else
            {
                ptr = ptr->left;
                this->counter++;
            }
        }

        return -1;
    }
};

int main()
{
    Node *myTree = new Node(4); // NB: we begin with myTree having one element

    // insert some elements
    myTree->insert(2);
    myTree->insert(6);
    myTree->insert(1);
    myTree->insert(3);
    myTree->insert(5);
    myTree->insert(7);
    myTree->insert(8);

    /*
        DRAW THE TREE THAT RESULTS FROM THE INSERTIONS ABOVE IN ORDER TO VISUALIZE THE EXAMPLES GIVEN BELOW.
        REMEMBER IT IS A BST, SO FOLLOW THE BST RULES WHILE INSERTING.
        NB: A TREE DIFFERENT FROM THIS ONE WILL BE USED TO TEST YOUR CODE.
    */

    int numHops;

    numHops = myTree->search(4);
    cout << "Number of hops: " << numHops << endl; // numHops should be 0 since 4 is the root node

    numHops = myTree->search(2);
    cout << "Number of hops: " << numHops << endl; // numHops should be 1 since it takes just 1 hop to get to 2

    numHops = myTree->search(7);
    cout << "Number of hops: " << numHops << endl; // numHops should be 2 since it takes 2 hops to get to 7

    numHops = myTree->search(8);
    cout << "Number of hops: " << numHops << endl; // numHops should be 3 since it takes 3 hop to get to 8

    numHops = myTree->search(10);
    cout << "Number of hops: " << numHops << endl; // numHops should be -1 since 10 is not in the tree

    return 0;
}
