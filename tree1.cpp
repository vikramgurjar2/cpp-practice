#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
       this->right = NULL;
    }
};
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

node *buildtree(node *root)
{
    cout << "enter the value of data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data of left of" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the data for incerting in right" << endl;
    root->right = buildtree(root->right);
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    postorder(root->left);
    postorder(root->right);
}
void buildfromlevelorder(node *root)
{
    queue<node *> q;
    cout << "enter the data for the root(**)" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter the data for left of" << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter the data for right  of" << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);

    buildfromlevelorder(root);
    levelordertraversal(root);
    /*
    //data:1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"level order traversal:"<<endl;

    cout<<"inorder tarversal:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder:"<<endl;
    postorder(root);*/

    return 0;
}