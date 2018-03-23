#include<bits/stdc++.h>

using namespace std;

int min_edit_required(string str1, string str2)
{
    int len1=str1.length(),len2=str2.length(),i,j;
    int table[len1+1][len2+1];
    for(i=0;i<=len1;i++)
    {
        for(j=0;j<=len2;j++)
        {
            if(i==0)
                table[i][j]=j;
            else if(j==0)
                table[i][j]=i;
            else if(str1.at(i-1)==str2.at(j-1))
                table[i][j]=table[i-1][j-1];
            else
                table[i][j]=min(min(table[i-1][j-1],table[i-1][j]),table[i][j-1])+1;
        }
    }
    return table[len1][len2];
}

int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    cout<<min_edit_required(str1,str2)<<endl;
    return 0;
}
