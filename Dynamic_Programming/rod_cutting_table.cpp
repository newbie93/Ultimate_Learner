#include<bits/stdc++.h>

using namespace std;

int get_max_profit(int val[], int n)
{
    int i,j,table[n+1][n+1];
    for(i=0;i<=n;i++)
        table[0][i]=table[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<i)
                table[i][j]=table[i-1][j];
            else
                table[i][j]=max(table[i-1][j],table[i][j-i]+val[i]);
        }
    }
    return table[n][n];
}

int main()
{
    int n;
    cin>>n;
    int val[n+1];
    for(int i=1;i<=n;i++)
        cin>>val[i];
    cout<< get_max_profit(val,n) <<endl;
    return 0;
}
