#include<bits/stdc++.h>

using namespace std;

typedef struct Node{int data; struct Node*left,*right;}Node;

Node* create_Node(int data)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void pre_order(Node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node*root)
{
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

void in_order(Node*root)
{
    if(root==NULL)
        return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void level_order(Node*root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        cout<<(root=q.front())->data<<" ";
        q.pop();
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
}

void pre_order_iter(Node*root)
{
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        cout<<(root=s.top())->data<<" ";
        s.pop();
        if(root->right)
            s.push(root->right);
        if(root->left)
            s.push(root->left);
    }
}

void post_order_iter(Node*root)
{
    stack<Node*>s;
    stack<int>ans;
    s.push(root);
    while(!s.empty())
    {
        ans.push((root=s.top())->data);
        s.pop();
        if(root->right)
            s.push(root->right);
        if(root->left)
            s.push(root->left);
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

void in_order_iter(Node*root)
{
    Node*current=root;
    stack<Node*>s;
    while(current!=NULL || !s.empty())
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        cout<<(current=s.top())->data<<" ";
        s.pop();
        current=current->right;
    }
}

int main()
{
    Node*root=create_Node(1);
    root->left=create_Node(2);
    root->right=create_Node(3);
    (root->right)->left=create_Node(4);
    (root->right)->right=create_Node(5);
    ((root->right)->left)->right=create_Node(7);
    ((root->right)->right)->left=create_Node(6);
    ((root->right)->right)->right=create_Node(8);
    cout<<"pre_order\n";
    pre_order(root);
    cout<<endl;
    cout<<"pre_order_iter\n";
    pre_order_iter(root);
    cout<<endl;
    cout<<"post_order\n";
    post_order(root);
    cout<<endl;
    cout<<"post_order_iter\n";
    post_order_iter(root);
    cout<<endl;
    cout<<"in_order\n";
    in_order(root);
    cout<<endl;
    cout<<"in_order_iter\n";
    in_order_iter(root);
    cout<<endl;
    cout<<"level_order\n";
    level_order(root);
    cout<<endl;
    return 0;
}
