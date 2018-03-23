#include<stdio.h>
#include<assert.h>

/*
    @tags array, insertion, deletion, insertion in random position, traversal
    @description this program shows all the array operations like insertion, deletion, traversal, insertion in random positions etc.
    @author riju ghosh
    @date 23/03/2018
*/

void insert_in_front(int*a, int *len, int x)
{
    int i;
    for(i=*len-1;i>=0;i--)
        a[i+1]=a[i];
    a[0]=x;
    *len=*len+1;
}

void insert_in_end(int*a, int*len, int x)
{
    a[*len]=x;
    *len=*len+1;
}

void insert_in_random_pos(int*a, int*len, int x, int index)
{
    assert(index<*len && index>=0);
    int i;
    for(i=*len-1;i>=index;i--)
        a[i+1]=a[i];
    a[index]=x;
    *len=*len+1;
}

void traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int delete_index(int*a, int*len, int index)
{
    assert(index<*len && index>=0);
    int i;
    for(i=index+1;i<=*len;i++)
        a[i-1]=a[i];
    *len=*len-1;
}

int main()
{
    int a[100001],n=0;
    insert_in_front(a,&n,5);
    insert_in_front(a,&n,4);
    insert_in_front(a,&n,3);
    insert_in_front(a,&n,2);
    insert_in_front(a,&n,1);
    insert_in_end(a,&n,7);
    insert_in_end(a,&n,8);
    insert_in_random_pos(a,&n,6,5);
    delete_index(a,&n,0);
    delete_index(a,&n,1);
    delete_index(a,&n,5);
    insert_in_end(a,&n,100);
    insert_in_front(a,&n,-1);
    traverse(a,n);
    return 0;
}
