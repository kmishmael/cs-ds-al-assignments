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

    void recursePreOrder(Node *root)
    {

        if (root == NULL)
        {
            return;
        }
        else
        {
            cout << root->value << " ";
            recursePreOrder(root->left);
            recursePreOrder(root->right);
        }
    }

    void preOrder()
    {
        Node *root = this;
        recursePreOrder(root);
        cout << endl;
    }

    void recursePostOrder(Node *rootNode)
    {
        if (rootNode == NULL)
        {
            return;
        }
        else
        {
            recursePostOrder(rootNode->left);
            recursePostOrder(rootNode->right);
            cout << rootNode->value << " ";
        }
    }

    void postOrder()
    {
        Node *root = this;
        recursePostOrder(root);
        cout << endl;
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
    myTree->inOrder();
    myTree->postOrder();
    return 0;
}