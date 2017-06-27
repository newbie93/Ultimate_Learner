#include <stdio.h>

int a[100005];
int b[100005][2];

unsigned long long int rem_consecutive(int n,int h)
{
    int k,i,ptr=0,count=1;

    k=a[0];
    b[ptr][0]=k;
    for(i=1;i<n;i++)
    {
        if(k!=a[i])
        {
            b[ptr++][1]=count;
            count=1;
            b[ptr][0]=(k=a[i]);
        }
        else
            count++;
    }
    b[ptr++][1]=count;

    unsigned long long int max=0llu,ans=0llu;

    for(i=0;i<ptr;i++)
    {
        if(b[i][0]<=h)
            ans+=(unsigned long long int)b[i][0]*(unsigned long long int)b[i][1];
        else
        {
            if(max<ans)
                max=ans;
            ans=0llu;
        }
    }

    if(max<ans)
        max=ans;

    return max;

}

int main()
{
    int t,n,k,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%llu\n",rem_consecutive(n,k));
    }
    return 0;
}
