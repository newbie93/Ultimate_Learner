#include<stdio.h>

int main()
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=i+1;j<=9;j++)
        {
            for(k=j+1;k<=9;k++)
            {
                if(i+j+k==15)
                {
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
    return 0;
}
