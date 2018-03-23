#include<bits/stdc++.h>

using namespace std;

int memo[10005][10005];

int min_edit_distance(string str1, string str2, int i, int j)
{
    if(i<=0)
        return (memo[i][j]=j);
    if(j<=0)
        return (memo[i][j]=i);

    if(memo[i][j]>-1)
        return memo[i][j];

    if(str1.at(i-1)==str2.at(j-1))
        return (memo[i][j]=min_edit_distance(str1, str2, i-1, j-1));

    return (memo[i][j]=min( min( min_edit_distance(str1, str2, i-1, j-1),
                     min_edit_distance(str1, str2, i-1, j)),
                min_edit_distance(str1, str2, i, j-1)) + 1);
}

int main()
{
    string str1, str2;
    cin>>str1;
    cin>>str2;
    int i, j, len1=str1.length(), len2=str2.length();
    for(i=0;i<=len1;i++)
    {
        for(j=0;j<=len2;j++)
            memo[i][j]=-1;
    }
    cout<<min_edit_distance(str1, str2, len1, len2)<<endl;
    return 0;
}
