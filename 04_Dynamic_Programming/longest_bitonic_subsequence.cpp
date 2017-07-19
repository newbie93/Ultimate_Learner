#include<bits/stdc++.h>

using namespace std;

int longest_bitonic_subseq(int val[], int n)
{
    int i,j,table_inc[n],table_dec[n],maximum=0;
    for(i=0;i<n;i++)
    {
        table_inc[i]=1;
        for(j=0;j<i;j++)
        {
            if(val[i]>val[j])
                table_inc[i]=max(table_inc[i],table_inc[j]+1);
        }
    }
    for(i=n-1;i>=0;i--)
    {
        table_dec[i]=1;
        for(j=n-1;j>i;j--)
        {
            if(val[i]>val[j])
                table_dec[i]=max(table_dec[i],table_dec[j]+1);
        }
    }
    for(i=0;i<n;i++)
    {
        if(table_inc[i]>1 && table_dec[i]>1 && maximum<table_dec[i]+table_inc[i]-1)
            maximum=table_inc[i]+table_dec[i]-1;
    }
    return maximum;
}

int main()
{
    int n,i;
    cin>>n;
    int val[n];
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<longest_bitonic_subseq(val,n)<<endl;
    return 0;
}
