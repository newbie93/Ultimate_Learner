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

struct TreeNode* arrange_level_wise(struct TreeNode*root, int dir)
{
    if(root==NULL)
        return NULL;

}

int main()
{
    return 0;
}
