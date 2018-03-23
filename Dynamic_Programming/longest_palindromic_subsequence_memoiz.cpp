#include<bits/stdc++.h>

#define SIZE 10005

using namespace std;

int memo[SIZE][SIZE];

int max_palin_seq(string str, int i, int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return (memo[i][j]=1);
    if(memo[i][j]>0)
        return memo[i][j];
    if(str.at(i)==str.at(j))
        return (memo[i][j]=max_palin_seq(str,i+1,j-1)+2);
    return (memo[i][j]= max(max_palin_seq(str,i+1,j),max_palin_seq(str,i,j-1)));
}

int main()
{
    string str;
    cin>>str;
    int i,j,len=str.length();
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
            memo[i][j]=0;
    }
    cout<<max_palin_seq(str,0,len-1)<<endl;
    return 0;
}
