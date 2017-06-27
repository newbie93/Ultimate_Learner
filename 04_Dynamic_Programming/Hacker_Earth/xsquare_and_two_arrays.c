#include <stdio.h>

#define uul unsigned long long int

uul a[100005];
uul b[100005];
uul a_b[100005];
uul b_a[100005];

inline int is_odd(int a)
{
       return a%2;
}

int main()
{
    int n,q,i,c,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%llu",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%llu",&b[i]);
    a_b[0]=0llu;
    b_a[0]=0llu;
    for(i=1;i<=n;i++)
    {
        if(is_odd(i))
        {
            //printf("%d is odd\n",i);
            a_b[i]=a_b[i-1]+a[i];
            b_a[i]=b_a[i-1]+b[i];
        }
        else
        {
            //printf("%d is even\n",i);
            a_b[i]=a_b[i-1]+b[i];
            b_a[i]=b_a[i-1]+a[i];
        }
    }

    /*for(i=0;i<=n;i++)
        printf("%llu ",a_b[i]);
    printf("\n");

    for(i=0;i<=n;i++)
        printf("%llu ",b_a[i]);
    printf("\n");*/

    for(i=1;i<=q;i++)
    {
        scanf("%d %d %d",&c,&l,&r);
        if(c==1)
        {
            if(is_odd(l))
                printf("%llu\n",a_b[r]-a_b[l-1]);
            else
                printf("%llu\n",b_a[r]-b_a[l-1]);
        }
        else
        {
            if(is_odd(l))
                printf("%llu\n",b_a[r]-b_a[l-1]);
            else
                printf("%llu\n",a_b[r]-a_b[l-1]);

        }
    }
    return 0;
}
