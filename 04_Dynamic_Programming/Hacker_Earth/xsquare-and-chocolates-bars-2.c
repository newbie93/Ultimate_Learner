#include<stdio.h>
#include<string.h>

char str[1000006];

int choco_1[1000006];
int choco_2[1000006];
int choco_3[1000006];

int compute(int n)
{
    int i,j,s,c;
    for(i=0;i<=n-3;i+=3)
    {
        if(str[i]==str[i+1] && str[i]==str[i+2])
            choco_1[i]=choco_1[i+1]=choco_1[i+2]=0;
        else
            choco_1[i]=choco_1[i+1]=choco_1[i+2]=1;

        if(i+3<n && str[i+1]==str[i+2] && str[i+1]==str[i+3])
            choco_2[i+1]=choco_2[i+2]=choco_2[i+3]=0;
        else if(i+3<n)
            choco_2[i+1]=choco_2[i+2]=choco_2[i+3]=1;

        if(i+4<n && str[i+2]==str[i+3] && str[i+2]==str[i+4])
            choco_3[i+2]=choco_3[i+3]=choco_3[i+4]=0;
        else if(i+4<n)
            choco_3[i+2]=choco_3[i+3]=choco_3[i+4]=1;
    }
}

int get_max(int n)
{

    compute(n);

    int i,j,max=0;

    /*for(i=0;i<n;i++)
        printf("%d ",choco_1[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",choco_2[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",choco_3[i]);
    printf("\n");*/

    for(i=0;i<=n-3;i++)
    {
        if(choco_1[i]==1)
        {
            for(j=i+1;j<n;j++)
            {
                if(choco_1[j]==0)
                    break;
            }
            if(max<(j-i))
                max=j-i;
            i=j;
        }
    }

    for(i=0;i<=n-3;i++)
    {
        if(choco_2[i]==1)
        {
            for(j=i+1;j<n;j++)
            {
                if(choco_2[j]==0)
                    break;
            }
            if(max<(j-i))
                max=j-i;
            i=j;
        }
    }

    for(i=0;i<=n-3;i++)
    {
        if(choco_3[i]==1)
        {
            for(j=i+1;j<n;j++)
            {
                if(choco_3[j]==0)
                    break;
            }
            if(max<(j-i))
                max=j-i;
            i=j;
        }
    }

    //printf("%d\n",max);

    return n-max;

}

int main()
{
    int i,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",str);
        n=strlen(str);
        for(i=0;i<n;i++)
            choco_1[i]=choco_2[i]=choco_3[i]=0;
        printf("%d\n",get_max(n));
    }
    return 0;
}
