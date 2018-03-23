#include<bits/stdc++.h>

using namespace std;

void create_tree(int inp[], int seg_tree[], int lb, int ub, int ptr)
{
    if(lb>ub)
        return;
    if(lb==ub)
    {
        seg_tree[ptr]=inp[lb];
        return;
    }
    int mid=lb+(ub-lb)/2;
    create_tree(inp, seg_tree, lb, mid, ptr*2);
    create_tree(inp, seg_tree, mid+1, ub, ptr*2+1);
    seg_tree[ptr]=seg_tree[ptr*2]+seg_tree[ptr*2+1];
}

void update(int inp[], int seg_tree[], int lb, int ub, int ptr, int index, int val)
{
    if(lb>ub)
        return;
    if(lb==ub)
    {
        inp[lb]=val;
        seg_tree[ptr]=val;
        return;
    }
    int mid=lb+(ub-lb)/2;
    if(index<=mid)
        update(inp, seg_tree, lb, mid, ptr*2, index, val);
    else
        update(inp, seg_tree, mid+1, ub, ptr*2+1, index, val);
    seg_tree[ptr] = seg_tree[ptr*2] + seg_tree[ptr*2+1] ;
}

int range_sum(int seg_tree[], int lb, int ub, int ptr, int l, int r)
{
    if(lb>ub)
        return 0;
    if(l<=lb && r>=ub) // total
        return seg_tree[ptr];
    else if(l>ub || r<lb) // no
        return 0;
    else // partial
    {
        int mid=lb+(ub-lb)/2;
        return range_sum(seg_tree, lb, mid, ptr*2, l, r)+
                range_sum(seg_tree, mid+1, ub, ptr*2+1, l, r);
    }
}

int main()
{
    int n,i,q,l,r;
    cin>>n;
    int input[n+1],seg_tree[4*n+1];
    for(i=1;i<=4*n;i++)
        seg_tree[i]=0;
    for(i=1;i<=n;i++)
        cin>>input[i];
    cin>>q;
    create_tree(input, seg_tree, 1, n, 1);
    while(q--)
    {
        cin>>l>>r;
        cout<<range_sum(seg_tree, 1, n, 1, l, r)<<endl;
    }
    return 0;
}
