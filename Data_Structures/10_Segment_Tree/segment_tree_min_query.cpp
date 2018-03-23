#include<bits/stdc++.h>

#define MAX 1000000009

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
    seg_tree[ptr]=min(seg_tree[ptr*2],seg_tree[ptr*2+1]);
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
    seg_tree[ptr]=min(seg_tree[ptr*2],seg_tree[ptr*2+1]);
}

int range_min(int seg_tree[], int lb, int ub, int ptr, int l, int r)
{
    if(lb>ub)
        return MAX;
    if(l<=lb && r>=ub)
        return seg_tree[ptr];
    else if(l>ub || r<lb)
        return MAX;
    else
    {
        int mid=lb+(ub-lb)/2;
        return min( range_min(seg_tree, lb, mid, ptr*2, l, r),
                    range_min(seg_tree, mid+1, ub, ptr*2+1, l, r));
    }
}

int main()
{
    int n,q,i,l,r;
    cin>>n;
    int inp[n+1], seg_tree[4*n+1];
    for(i=1;i<=4*n;i++)
        seg_tree[i]=MAX;
    for(i=1;i<=n;i++)
        cin>>inp[i];
    create_tree(inp, seg_tree, 1, n, 1);
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<range_min(seg_tree, 1, n, 1, l, r)<<endl;
    }
    return 0;
}
