#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node{int data;struct Node*next;}Node;

struct Node* search(struct Node*head,int data)
{
	assert(head);
	struct Node*temp=NULL;
	if(head->data==data)
	{
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->next=NULL;
		return temp;
	}
	while(head->next!=NULL)
	{
		if((head->next)->data==data)
		{
			temp=(struct Node*)malloc(sizeof(struct Node));
			temp->next=head;
			return temp;
		}
		head=head->next;
	}
	return temp;
}


struct Node* del_node(struct Node**head,int data)
{
	assert(*head);	
	struct Node*temp,*srch=search(*head,data);
	if(srch==NULL)
		return NULL;
	if(srch->next==NULL)
	{
		temp=*head;
		*head=(*head)->next;
		return temp;
	}
	temp=(srch->next)->next;
	(srch->next)->next=((srch->next)->next)->next;
	return temp;
}

void display(struct Node*head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	puts("");
}


void insert_first(struct Node**head,int data)
{
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=*head;
	*head=temp;
}

void insert_end(struct Node**head,int data)
{
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	struct Node*p=*head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}

int insert_before(struct Node**head,int tar,int val)
{
	struct Node*srch=search(*head,tar);
	if(srch==NULL)
		return 0; // NOT FOUND
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=val;
	if(srch->next==NULL)
	{
		temp->next=*head;
		*head=temp;
		return 1;
	}
	temp->next=(srch->next)->next;
	(srch->next)->next=temp;
	return 1;
}

int insert_after(struct Node**head,int tar,int val)
{
	struct Node*srch=search(*head,tar);
	if(srch==NULL)
		return 0; // NOT FOUND
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=val;
	if(srch->next==NULL)
	{
		temp->next=(*head)->next;
		(*head)->next=temp;
		return 1;
	}
	temp->next=((srch->next)->next)->next;
	((srch->next)->next)->next=temp;
	return 1;
}

void rev(struct Node**head)
{
	if(*head==NULL || (*head)->next==NULL)
		return;
	struct Node*p=*head,*q=p->next,*r=q->next;
	p->next=NULL;
	while(r!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		r=r->next;
	}
	q->next=p;
	*head=q;
}




































