#include<bits/stdc++.h>

using namespace std;

int count_palindromic_substrings(string str)
{
    int len=str.length(),gap,i,count_palin=0;
    bool is_palin[len][len];
    for(gap=0;gap<len;gap++)
    {
        for(i=0;i<len-gap;i++)
        {
            if(str[i]==str[i+gap])
            {
                if(gap<=1)
                    is_palin[i][i+gap]=true;
                else
                    is_palin[i][i+gap]=is_palin[i+1][i+gap-1];
                if(is_palin[i][i+gap]==true)
                    count_palin++;
            }
            else
                is_palin[i][i+gap]=false;
        }
    }
    return count_palin;
}

int main()
{
    string str;
    cin>>str;
    cout<<count_palindromic_substrings(str)<<endl;
    return 0;
}
