/*
 *      linked_list_def.h
 *
 *      This header file, defines the structure used for Linked List, and also
 *      Some important functions to go with it, eg. insertion, removal, search, reversal etc.
 *
 *      Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>




/*
 *      This is the basic structure of the Node
 *      Contains a data part and a pointer to the next node
 *      The data is of type integer.
 */
struct Node{int data;struct Node*next;}Node;




/*
 *      The search function takes the head of the list and the
 *      data to be searched, and returns a pointer of struct Node
 *      Let the returned struct Node* be ptr
 *      if data is not present: ptr=NULL
 *      if data is in the head: ptr->next=NULL
 *      if data is any other node: (ptr->next)=prev node of the target
 */
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




/*
 *	This function searces for the data to be removed and removes the
 *	Node. It uses search() to search for the data to be removed.
 */
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




/*
 *	This function is used to display the entire list.
 */
void display(struct Node*head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	puts("");
}




/*
 *      Node is inserted in the beginning
 */
void insert_first(struct Node**head,int data)
{
	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=*head;
	*head=temp;
}




/*
 *      Remove first Node
 */
struct Node* rem_first(struct Node**head)
{
	assert(*head);
	struct Node*p=*head;
	*head=(*head)->next;
	return p;
}




/*
 *      Node is inserted at the end
 */
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




/*
 *      removing Node from the end
 */
struct Node* rem_end(struct Node**head)
{
	assert(*head);
	struct Node*p=*head,*temp;
	if(p->next==NULL)
	{
		*head=NULL;
		return p;
	}
	while((p->next)->next!=NULL)
		p=p->next;
	temp=p->next;
	p->next=NULL;
	return temp;
}




/*
 *      Node is inserted before a target
 */
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




/*
 *      Node is inserted after a target
 */
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




/*
 *      list is reversed
 */
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




/*
 *	Finds out whether a list is empty
 */
 int is_list_empty(struct Node*head)
 {
	 if(head==NULL)
	 	return 1; // yes, list is empty
	return 0; // No, list is NOT Empty
 }
