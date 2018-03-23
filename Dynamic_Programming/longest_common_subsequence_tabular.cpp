#include<bits/stdc++.h>

using namespace std;

int longest_common_subsequence(string str1, string str2)
{
    int i,j,len1=str1.length(),len2=str2.length();
    int table[len1+1][len2+1];
    for(i=0;i<=len2;i++)
        table[0][i]=0;
    for(i=0;i<=len1;i++)
        table[i][0]=0;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                table[i][j]=1+table[i-1][j-1];
            else
                table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[len1][len2];
}

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<longest_common_subsequence(str1,str2)<<endl;
    return 0;
}
