#include<bits/stdc++.h>

#define MAX 1000000009

using namespace std;

int min_coins(int n, int k, int val[])
{
    int table[n+1][k+1],i,j;
    for(i=0;i<=k;i++)
        table[0][i]=MAX;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(val[i]>j)
                table[i][j]=table[i-1][j];
            else if(val[i]==j)
                table[i][j]=1;
            else if(table[i][j-val[i]]>0)
                table[i][j]=min(table[i-1][j],table[i][j-val[i]]+1);
            else
                table[i][j]=table[i-1][j];
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }*/
    return table[n][k];
}

int main()
{
    int n,k,i;
    cin>>n>>k;
    int val[n+1];
    for(i=1;i<=n;i++)
        cin>>val[i];
    sort(val+1,val+n+1);
    cout<<min_coins(n,k,val)<<endl;
    return 0;
}
