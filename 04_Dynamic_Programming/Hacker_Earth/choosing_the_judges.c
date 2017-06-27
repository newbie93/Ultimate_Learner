#include <stdio.h>

unsigned long long int ref[10002];

int a[10002];

inline int max(unsigned long long int a, unsigned long long int b)
{
    if(a>b)
        return a;
    return b;
}

unsigned long long int get_max(int n)
{
    if(n==1)
        return (unsigned long long int)a[1];
    if(n==2)
        return max((unsigned long long int)a[1],(unsigned long long int)a[2]);
    int i;
    ref[1]=(unsigned long long int)a[1];
    ref[2]=max((unsigned long long int)a[1],(unsigned long long int)a[2]);
    for(i=3;i<=n;i++)
        ref[i]=max(ref[i-1],(unsigned long long int)a[i]+ref[i-2]);
    return ref[n];
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %llu\n",get_max(n));
    }
    return 0;
}

