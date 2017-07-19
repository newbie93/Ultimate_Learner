#include<bits/stdc++.h>

#define MAX 1000000009

using namespace std;

int val[10]={0, 1, 2, 5, 10, 20, 50, 100, 500, 1000};

int table[10][100001];

int min_coins(int k, int num)
{
    int i,j;
    for(i=1;i<=9;i++)
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
    for(i=k;i>=1;i--)
    {
        if(num>=table[9][i])
            break;
    }
    return k-i;
}

int main()
{
    int t,n,k;
    for(int i=0;i<=100000;i++)
        table[0][i]=MAX;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<min_coins(n,k)<<endl;
    }
    return 0;
}

