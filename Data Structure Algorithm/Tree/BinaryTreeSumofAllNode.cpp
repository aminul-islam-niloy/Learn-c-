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

int SumOfAllNode(struct Node * root){
    int sum=0;
    if(!root){
      return 0;
    }
    sum= SumOfAllNode(root->left)+ SumOfAllNode(root->right)+ root->data;
    return sum;
}

int countNode(struct Node *root)
{
    if (!root)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
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
    //cout << countNode(root);

    cout<<SumOfAllNode(root);


    //         10
    //        /   \
    //       3     6
    //     /  \    / \
    //    1    2  4   5
}