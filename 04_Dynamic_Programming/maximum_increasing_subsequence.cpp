#include<bits/stdc++.h>

using namespace std;

int max_increasing_subseq(int val[], int n)
{
    int i,j,table[n],maximum=1;
    table[0]=1;
    for(i=1;i<n;i++)
    {
        table[i]=1;
        for(j=0;j<i;j++)
        {
            if(val[j]<val[i])
            {
                table[i]=max(table[i],table[j]+1);
                if(table[i]>maximum)
                    maximum=table[i];
            }
        }
    }
    return maximum;
}

int main()
{
    int n,i;
    cin>>n;
    int val[n];
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<max_increasing_subseq(val,n)<<endl;
    return 0;
}
