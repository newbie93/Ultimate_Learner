#include<bits/stdc++.h>

using namespace std;

struct TreeNode{int data; struct TreeNode*left,*right;};

struct TreeNode* create_node(int data)
{
    struct TreeNode*temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void convert(struct TreeNode*root)
{
    if(root==NULL)
        return;
    struct TreeNode*temp=root->left;
    root->left=root->right;
    root->right=temp;
    convert(root->left);
    convert(root->right);
}

void inorder(struct TreeNode*root)
{
    struct TreeNode*current=root;
    stack<struct TreeNode*>s;
    int done=0;
    while(!done)
    {
        if(current)
        {
            s.push(current);
            current=current->left;
        }
        else
        {
            if(s.empty())
                done=1;
            else
            {
                current=s.top();
                s.pop();
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
    cout<<"\n";
}

int main()
{
    struct TreeNode*root=NULL;
    root=create_node(1);
    root->left=create_node(2);
    root->right=create_node(3);
    (root->left)->left=create_node(4);
    (root->left)->right=create_node(5);
    (root->right)->left=create_node(6);
    (root->right)->right=create_node(7);
    inorder(root);
    convert(root);
    inorder(root);
    return 0;
}
