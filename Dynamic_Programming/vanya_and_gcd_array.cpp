#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int gcd(int a, int b)
{
    if(a%b==b || a%b==0)
        return b;
    return gcd(b,a%b);
}

int max_increasing_gcd_1(int arr[], int n)
{
    int i,j,max_inc[n+1],count_seq=0;
    if(arr[0]==1)
        max_inc[0]=1;
    else
        max_inc[0]=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]==1)
            max_inc[i]=1;
        else
            max_inc[i]=0;
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && gcd(arr[i],arr[j])==1)
                max_inc[i]=max(max_inc[j]+1,max_inc[i]);
        }
        if(max_inc[i]>1)
            count_seq=((count_seq%MOD)+(max_inc[i]%MOD))%MOD;
    }
    return count_seq;
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<max_increasing_gcd_1(arr,n)<<endl;
    return 0;
}

