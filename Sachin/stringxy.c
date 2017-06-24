#include<stdio.h>
#include<string.h>

inline void swap(char*a)
{
    if(*a=='x')
        *a='y';
    else
        *a='x';
}

int main()
{
    int t,i,j,len,chk;
    char str[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",str);
        len=strlen(str);
        chk=1;
        for(i=0;chk==1;i++)
        {
            chk=0;
            for(j=len-1;j>=0;j--)
            {
                if(str[j]=='y')
                {
                    chk=1;
                    for(;j>=0;j--)
                        swap(&str[j]);
                    break;
                }
            }
            /*For test*/
            puts(str);
        }
        printf("%d\n",(i-1));
    }
    return 0;
}
