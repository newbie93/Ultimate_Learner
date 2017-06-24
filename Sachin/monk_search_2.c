#include <stdio.h>
#include <stdlib.h>

int *a,**b;

inline int get_int()
{
    int n=0,c;
    while((c=getchar())>='0'&&c<='9')
        n=(n<<3)+(n<<1)+c-'0';
    return n;
}

int binary_search(int lb,int ub,int tar)
{
    if(lb>=ub)
    {
        if(a[lb]>=tar)
            return lb;
        return lb+1;
    }
    int mid=lb+(ub-lb)/2;
    if(a[mid]==tar)
        return mid;
    if(a[mid]>tar)
        return binary_search(lb,mid-1,tar);
    return binary_search(mid+1,ub,tar);
}

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int remove_duplicates(int n)
{
    qsort(&a[1],n,sizeof(int),comp);

    int i,ptr=1,k=a[1],count=1;

    b[ptr][0]=k;

    for(i=2;i<=n;i++)
    {
        if(a[i]!=k)
        {
            b[ptr][1]=count;
            ptr++;
            k=a[i];
            count=1;
            b[ptr][0]=k;
            //printf("k: %d\n",k);
        }
        else
            count++;
    }

    b[ptr][1]=count;

    for(i=1;i<=ptr;i++)
        a[i]=b[i][0];

    return ptr;
}

int main()
{
    int n,q,k,l,i,pos,sum;

    a=(int*)malloc(sizeof(int)*100001);
    b=(int**)malloc(sizeof(int*)*100001);

    if(a==NULL || b==NULL)
        return -1;

    for(i=0;i<100001;i++)
        b[i]=(int*)malloc(sizeof(int)*2);

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    n=remove_duplicates(n);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&k,&l);
        if(k==0)
        {
            pos=binary_search(1,n,l);
            sum=0;
            for(i=pos;i<=n;i++)
                sum+=b[i][1];
            printf("%d\n",sum);
        }
        else
        {
            pos=binary_search(1,n,l);
            sum=0;
            if(b[pos][0]==l)
                pos++;
            for(i=pos;i<=n;i++)
                sum+=b[i][1];
            printf("%d\n",sum);
        }
    }
    return 0;
}

