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

void update_lazy(int seg_tree[], int lazy_tree[], int lb, int ub, int ptr, int l, int r, int val)
{
    if(lb>ub)
        return;
    if(lazy_tree[ptr]!=0)
    {
        seg_tree[ptr]+=lazy_tree[ptr];
        if(lb!=ub)
        {
            lazy_tree[ptr*2]+=lazy_tree[ptr];
            lazy_tree[ptr*2+1]+=lazy_tree[ptr];
        }
        lazy_tree[ptr]=0;
    }
    if(l>ub || r<lb)
        ;
    else if(l<=lb && r>=ub)
    {
        seg_tree[ptr]+=val;
        if(lb!=ub)
        {
            lazy_tree[ptr*2]+=val;
            lazy_tree[ptr*2+1]+=val;
        }
    }
    else
    {
        int mid=lb+(ub-lb)/2;
        update_lazy(seg_tree, lazy_tree, lb, mid, ptr*2, l, r, val);
        update_lazy(seg_tree, lazy_tree, mid+1, ub, ptr*2+1, l, r, val);
        seg_tree[ptr]=min(seg_tree[ptr*2],seg_tree[ptr*2+1]);
    }
}

int range_sum_lazy(int seg_tree[], int lazy_tree[], int lb, int ub, int ptr, int l, int r)
{
    if(lb>ub)
        return MAX;
    if(lazy_tree[ptr]!=0)
    {
        seg_tree[ptr]+=lazy_tree[ptr];
        if(lb!=ub)
        {
            lazy_tree[ptr*2]=lazy_tree[ptr];
            lazy_tree[ptr*2+1]=lazy_tree[ptr];
        }
        lazy_tree[ptr]=0;
    }
    if(l>ub || r<lb)
        return MAX;
    else if(l<=lb && r>=ub)
        return seg_tree[ptr];
    else
    {
        int mid=lb+(ub-lb)/2;
        return min(range_sum_lazy(seg_tree, lazy_tree, lb, mid, ptr*2, l, r),
                range_sum_lazy(seg_tree, lazy_tree, mid+1, ub, ptr*2+1, l, r)) ;
    }
}

int main()
{
    return 0;
}

