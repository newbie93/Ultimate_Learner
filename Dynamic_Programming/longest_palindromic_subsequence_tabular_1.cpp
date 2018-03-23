#include<bits/stdc++.h>

using namespace std;

int max_palin_seq(string str)
{
    int i,j,len=str.length();
    string str_tmp;
    for(i=len-1;i>=0;i--)
        str_tmp.push_back(str[i]);
    int table[len+1][len+1];
    for(i=0;i<=len;i++)
        table[i][0]=table[0][i]=0;
    for(i=1;i<=len;i++)
    {
        for(j=1;j<=len;j++)
        {
            if(str.at(i-1)==str_tmp.at(j-1))
                table[i][j]=1+table[i-1][j-1];
            else
                table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }
    return table[len][len];
}

int main()
{
    string str;
    cin>>str;
    cout<<max_palin_seq(str)<<endl;
    return 0;
}
