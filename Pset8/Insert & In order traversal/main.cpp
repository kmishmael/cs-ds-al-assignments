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

    int insert(int fruit)
    {
        Node *root = this;

        Node *ptr = root;

        Node *newNode = new Node(fruit);

        while (ptr != NULL)
        {
            if (fruit > ptr->value)
            {

                if (ptr->right == NULL)
                {
                    ptr->right = newNode;
                    return;
                }
                ptr = ptr->right;
            }

            if (ptr->left == NULL)
            {
                ptr->left = newNode;
                return;
            }
            ptr = ptr->left;
        }
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
};

int main()
{

    int newElement = 4;
    // First node of the tree
    Node *myTree = new Node(newElement);

    // Additional nodes for the tree
    myTree->insert(2);
    myTree->insert(6);
    myTree->insert(1);
    myTree->insert(3);
    myTree->insert(5);
    myTree->insert(7);

    // carry out the traversal
    myTree->inOrder(); // output should be: 1 2 3 4 5 6 7

    return 0;
}