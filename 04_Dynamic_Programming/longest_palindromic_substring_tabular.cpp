#include<bits/stdc++.h>

using namespace std;

int longest_palindromic_substring(string str)
{
    int len=str.length(),i,gap,max_len=0;
    bool is_palin[len][len];
    for(gap=0;gap<len;gap++)
    {
        for(i=0;i<len-gap;i++)
        {
            if(str[i]==str[i+gap])
            {
                if(gap>1)
                    is_palin[i][i+gap]=is_palin[i+1][i+gap-1];
                else
                    is_palin[i][i+gap]=true;
                if(is_palin[i][i+gap]==true)
                    max_len=max(gap+1,max_len);
            }
            else
                is_palin[i][i+gap]=false;
        }
    }
    return max_len;
}

int main()
{
    string str;
    cin>>str;
    cout<<longest_palindromic_substring(str)<<endl;
    return 0;
}
