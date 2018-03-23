#include<bits/stdc++.h>

using namespace std;

int max_palin_seq(string str)
{
    int len=str.length(),i,j,gap;
    int table[len][len];
    for(i=0;i<len;i++)
        table[i][i]=1;
    for(gap=1;gap<len;gap++)
    {
        for(i=0;i<len-gap;i++)
        {
            if(str.at(i)==str.at(i+gap))
                table[i][i+gap]=table[i+1][i+gap-1]+2;
            else
                table[i][i+gap]=max(table[i][i+gap-1],table[i+1][i+gap]);
        }
    }
    return table[0][len-1];
}

int main()
{
    string str;
    cin>>str;
    cout<<max_palin_seq(str)<<endl;
    return 0;
}
