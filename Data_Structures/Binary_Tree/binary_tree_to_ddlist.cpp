#include<bits/stdc++.h>

using namespace std;

struct TreeNode{int data;struct TreeNode*left,*right;};

struct TreeNode* create_node(int data)
{
    struct TreeNode*temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void insert_list(struct TreeNode**head, int data)
{
    struct TreeNode*temp=(struct TreeNode*)malloc(sizeof(struct TreeNode*));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    struct TreeNode*p=*head;
    while(p->right)
        p=p->right;
    p->right=temp;
    temp->left=p;
}

void convert(struct TreeNode*root, struct TreeNode**head)
{
    if(root==NULL)
        return;
    convert(root->left,head);
    insert_list(head,root->data);
    convert(root->right,head);
}

void display(struct TreeNode*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
}
void inorder(struct TreeNode**root)
{
    struct TreeNode*current=*root;
    stack<struct TreeNode*>s;
    queue<struct TreeNode*>q;
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
                q.push(current);
                s.pop();
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
    struct TreeNode*prev=NULL;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        if(prev==NULL)
        {
            *root=current;
            current->left=NULL;
            current->right=NULL;
            prev=current;
        }
        else
        {
            prev->right=current;
            current->left=prev;
            current->right=NULL;
            prev=current;
        }
    }
}

int main()
{
    struct TreeNode*root=NULL,*head=NULL;
    root=create_node(1);
    root->left=create_node(2);
    root->right=create_node(3);
    (root->left)->left=create_node(4);
    (root->left)->right=create_node(5);
    (root->right)->left=create_node(6);
    (root->right)->right=create_node(7);
    convert(root,&head);
    cout<<"inorder:- ";
    inorder(&root);
    cout<<"\n";
    display(head);
    cout<<"\n";
    display(root);
    return 0;
}

