#include <stdio.h>

#define SHIRTS 0
#define PANTS 1
#define SHOES 2

int a[100001][3];

int g[100001][3];

inline int minimum(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int get_min(int i,int type)
{
    if(i<0)
        return 0;
    if(i==0)
    {
        switch(type)
        {
            case SHIRTS:
                return minimum(a[0][SHOES],a[0][PANTS]);
            case PANTS:
                return minimum(a[0][SHOES],a[0][SHIRTS]);
            case SHOES:
                return minimum(a[0][SHIRTS],a[0][PANTS]);
        }
    }

    if(g[i][type]>0)
        return g[i][type];

    switch(type)
    {
        case SHIRTS:
            return (g[i][SHIRTS]=minimum(get_min(i-1,SHOES)+a[i][SHOES],get_min(i-1,PANTS)+a[i][PANTS]));
        case PANTS:
            return (g[i][PANTS]=minimum(get_min(i-1,SHOES)+a[i][SHOES],get_min(i-1,SHIRTS)+a[i][SHIRTS]));
        case SHOES:
            return (g[i][SHOES]=minimum(get_min(i-1,SHIRTS)+a[i][SHIRTS],get_min(i-1,PANTS)+a[i][PANTS]));
    }
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            g[i][SHIRTS]=g[i][PANTS]=g[i][SHOES]=0;
        for(i=0;i<n;i++)
            scanf("%d %d %d",&a[i][SHIRTS],&a[i][PANTS],&a[i][SHOES]);
        int shirt,pant,shoe,min;
        shirt=get_min(n-2,SHIRTS)+a[n-1][SHIRTS];
        pant=get_min(n-2,PANTS)+a[n-1][PANTS];
        min=minimum(shirt,pant);
        shoe=get_min(n-2,SHOES)+a[n-1][SHOES];
        min=minimum(min,shoe);
        printf("%d\n",min);
    }
    return 0;
}

