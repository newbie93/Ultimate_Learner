#include<bits/stdc++.h>

using namespace std;

int ways(int val[], int n, int k)
{
    int i, j, table[n+1][k+1];

    for(i=0;i<=n;i++)
        table[i][0]=0;

    for(i=0;i<=k;i++)
        table[0][i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(val[i]==j)
                table[i][j]=1+table[i-1][j];
            else if(val[i]>j)
                table[i][j]=table[i-1][j];
            else if(table[i][j-val[i]]>0)
                table[i][j]=table[i-1][j]+table[i][j-val[i]];
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
    sort(val+1,val+1+n);
    cout<<ways(val, n, k)<<endl;
    return 0;
}
