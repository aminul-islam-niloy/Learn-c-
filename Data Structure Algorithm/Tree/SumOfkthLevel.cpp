#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void PrintTree(struct Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int leavesize = q.size();

        for (int i = 0; i < leavesize; i++)
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int Sumofkth(struct Node *root, int K)
{
    if (!root)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == K)
            {
                sum += node->data;
            }

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int main()
{

    struct Node *root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(2);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    // PrintTree(root);
    cout << Sumofkth(root, 2);

    //         10
    //        /   \
    //       3     6
    //     /  \    / \
    //    1    2  4   5
}