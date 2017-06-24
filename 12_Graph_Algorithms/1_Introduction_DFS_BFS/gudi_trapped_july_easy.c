#include <stdio.h>
#include <stdlib.h>

int g[1000001];

int a,h,len;

inline void to_char(int n,int len,char*str)
{
    int i=len,k=n;
    str[0]=str[1]=str[2]=str[3]=str[4]=str[4]='0';
    str[i]='\0';
    while(k!=0)
    {
        str[--i]=(k%10)+'0';
        k/=10;
    }
}

inline int sera(int n,int len,int h)
{
    if(h==0)
        return n;
    static char str[7],str_1[7];
    int i,j=len-h,count=0;
    to_char(n,len,str);
    for(i=0;i<len;i++)
    {
        str_1[i]=str[j];
        j=(j+1)%len;
    }
    str_1[len]='\0';
    for(i=0;i<len;i++)
        count=(count<<3)+(count<<1)+str_1[i]-'0';
    return count;
}

inline int xhaka(int n,int len,int a)
{
    static char str[7];
    int i,t,count=0;
    to_char(n,len,str);
    for(i=len;i>=1;i--)
    {
        if(i%2==0)
        {
            t=(str[i-1]-'0'+a)%10;
            str[i-1]=t+'0';
        }
    }
    for(i=0;i<len;i++)
        count=(count<<3)+(count<<1)+str[i]-'0';
    return count;
}

void dfs(int n,int len,int a,int h,int*min)
{
    g[n]=1;
    int x=sera(n,len,h);
    int y=xhaka(n,len,a);
    if(*min>x)
        *min=x;
    if(*min>y)
        *min=y;
    if(g[x]==0)
        dfs(x,len,a,h,min);
    if(g[y]==0)
        dfs(y,len,a,h,min);
}

int main()
{
    int power[7]={1,10,100,1000,10000,100000,1000000};
    int t,n,len,a,h,min,i;
    char str[7];
    scanf("%d",&t);
    while(t--)
    {

        scanf( "%s",str);
        len=strlen(str);
        scanf("%d %d",&a,&h);
        n=atoi(str);
        for(i=0;i<=power[len];i++)
            g[i]=0;
        min=1000000000;
        h=h%len;
        dfs(n,len,a,h,&min);
        to_char(min,len,str);
        puts(str);
    }
    return 0;
}

