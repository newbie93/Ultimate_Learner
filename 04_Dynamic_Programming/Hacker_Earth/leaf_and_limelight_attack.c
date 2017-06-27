#include<stdio.h>

#define MOD 1000000009

unsigned long long int a[10000001];


inline unsigned long long int sq_4(int n)
{
    unsigned long long int temp=(((unsigned long long int)n%MOD)*((unsigned long long int)n%MOD)%MOD);
    //printf("%d\n",n);
    return ((4llu*temp)%MOD);
}

inline void cal()
{
    int i;
    a[0]=0llu;
    a[1]=1llu;
    a[2]=10llu;
    for(i=3;i<=10000000;i++)
        a[i]=((sq_4(i)-6*(i-1))%MOD+a[i-2])%MOD;
}

int main()
{
    cal();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%llu\n",a[n]);
    }
    return 0;
}
