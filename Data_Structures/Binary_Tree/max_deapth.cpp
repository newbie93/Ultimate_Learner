#include<bits/stdc++.h>

using namespace std;

struct TreeNode{int data; struct TreeNode*right,*left;};

struct TreeNode* create_node(int data)
{
    struct TreeNode*temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

int find_deapth(struct TreeNode*root)
{
    if(root==NULL)
        return -1;
    return max(find_deapth(root->left),find_deapth(root->right))+1;
}

int find_deapth_iter(struct TreeNode*root)
{
    queue< pair<struct TreeNode*,int> >q;
    struct TreeNode*temp;
    int deapth,max_deapth=0;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        temp=q.front().first;
        deapth=q.front().second;
        if(deapth>max_deapth)
            max_deapth=deapth;
        q.pop();
        if(temp->left)
            q.push(make_pair(temp->left,deapth+1));
        if(temp->right)
            q.push(make_pair(temp->right,deapth+1));
    }
    return max_deapth;
}

int main()
{
    struct TreeNode*root=create_node(1);
    root->left=create_node(0);
    root->right=create_node(2);
    (root->right)->left=create_node(3);
    ((root->right)->left)->left=create_node(4);
    cout<<"recur :- "<<find_deapth(root)<<endl;
    cout<<"iter :- "<<find_deapth_iter(root)<<endl;
    return 0;
}
