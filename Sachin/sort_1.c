#include <stdio.h>
#include <stdlib.h>

int a[100005][2];
char str[100005];

void heapify(int n,int i)
{
    if(i*2>n)
        return;
    int largest=i,temp_x,temp_y;
    if(a[i*2][0]>a[largest][0])
        largest=i*2;
    if(i*2+1<=n && a[i*2+1][0]>a[largest][0])
        largest=i*2+1;
    if(i!=largest)
    {
        temp_x=a[largest][0];
        temp_y=a[largest][1];
        a[largest][0]=a[i][0];
        a[largest][1]=a[i][1];
        a[i][0]=temp_x;
        a[i][1]=temp_y;
        heapify(n,largest);
    }
}

void heap_sort_x(int n)
{
    int i,temp_x,temp_y;
    for(i=n/2;i>=1;i--)
        heapify(n,i);
    for(i=1;i<n;i++)
    {
        temp_x=a[1][0];
        temp_y=a[1][1];
        a[1][0]=a[n-i+1][0];
        a[1][1]=a[n-i+1][1];
        a[n-i+1][0]=temp_x;
        a[n-i+1][1]=temp_y;
        heapify(n-i,1);
    }
}

void heapify_y(int n,int i)
{
    if(i*2>n)
        return;
    int largest=i,temp;
    if(a[i*2][1]>a[largest][1])
        largest=i*2;
    if(i*2+1<=n && a[i*2+1][1]>a[largest][1])
        largest=i*2+1;
    if(i!=largest)
    {
        temp=a[i][1];
        a[i][1]=a[largest][1];
        a[largest][1]=temp;
        heapify_y(n,largest);
    }
}

void heap_sort_y(int lb,int ub)
{
    int i,temp;
    for(i=ub/2;i>=lb;i--)
        heapify_y(ub,i);
    for(i=lb;i<ub;i++)
    {
        temp=a[i][1];
        a[i][1]=a[ub-i+lb][1];
        a[ub-i+lb][1]=temp;
        heapify_y(ub-i+lb-1,1);
    }
}

void sort(int n)
{
    heap_sort_x(n);
    int i,k=1;
    for(i=2;i<=n;i++)
    {
        if(a[i][0]!=a[k][0])
        {
            heap_sort_y(k,i-1);
            k=i;
        }
    }
    heap_sort_y(k,i-1);
}

int get_falls(int n)
{
    sort(n);

    int i,k=0,count=0,temp=0;

    FILE*f=fopen("OUTPUT.txt","w");
    for(i=0;i<n;i++)
        fprintf(f,"%d %d\n",a[i][0],a[i][1]);

    for(i=1;i<n;i++)
    {
        if(a[i][0]==a[k][0] && a[i][1]==a[k][1])
            temp++;
        else
        {
            if(temp>=1)
                count+=temp;
            k=i;
            temp=0;
        }
    }
    fprintf(f,"\n\n%d\n",count);
    fclose(f);
    return count;
}

int main()
{
    int x=0,y=0,i,ptr=0;

    str[0]='\0';

    FILE*f=fopen("INPUT.txt","r");

    fscanf(f," %s",str);

    fclose(f);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='L')
            x--;
        else if(str[i]=='R')
            x++;
        else if(str[i]=='U')
            y--;
        else
            y++;
        a[ptr][0]=x;
        a[ptr][1]=y;
        ptr++;
    }

    printf("%d\n",get_falls(ptr+1));


    return 0;
}
