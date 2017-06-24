#include <stdio.h>

int remove_repeated_2(int*str,int n)
{
    char tmp_str[100];int i,j,k;
    for(i=0,j=0;i<n;i++)
    {
        tmp_str[j++]=str[i];
        if(str[i]==2)
        {
            for(k=i;str[k+1]==2;k++);
            i=k;
        }
    }
    for(i=0;i<j;i++)
        str[i]=tmp_str[i];
    return j;
}

int longest_zonsecutive_1(int*str,int n)
{
    int max=0,count=0,i;
    for(i=0;i<n;i++)
    {
        if(str[i]==1)
            count++;
        else
        {
            if(count>max)
                max=count;
            count=0;
        }
    }
    return max;
}

int main()
{
    int str[100];
    int n,i,seen_zero=0,no_of_ones=0,last_seen_zero,considering_zero,max,count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&str[i]);
    for(i=0;i<n;i++)
    {
        if(str[i]==0 && seen_zero==0)
        {
            seen_zero=1;
            if(i<n-1 && str[i+1]==0)
                str[i]=(str[i++]=2);
        }
        else if(str[i]==0 && seen_zero==1)
            str[i]=2;
        else if(str[i]==1)
        {
            no_of_ones++;
            if(seen_zero==1)
                seen_zero=0;
        }
    }
    n=remove_repeated_2(str,n);
    last_seen_zero=-1;
    count=max=0;
    for(i=0;i<n;i++)
    {
        if(str[i]==2)
        {
            if(count>max)
            {
                max=count;
                if(last_seen_zero>=0)
                    considering_zero=1;
                else
                    considering_zero=0;
            }
            count=0;
            last_seen_zero=-1;
        }
        else if(str[i]==1)
        {
            count++;
        }
        else
        {
            if(last_seen_zero>=0)
            {
                if(count>max)
                    max=count;
                count=i-last_seen_zero;
                last_seen_zero=i;
            }
            else
            {
                last_seen_zero=i;
                count++;
            }
        }
    }
    if(count>max)
    {
        max=count;
        if(last_seen_zero>=0)
            considering_zero=1;
        else
            considering_zero=0;
    }
    if(max<=no_of_ones && considering_zero==1)
        max++;
    else if(max>no_of_ones)
        max--;
    printf("%d\n",max);
    return 0;
}
