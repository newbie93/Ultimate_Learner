#include"linked_list_def.h"

struct Node* add(struct Node**head1,struct Node**head2)
{
	rev(head1);
	rev(head2);

	struct Node*p=*head1,*q=*head2,*head3=NULL,*temp;
	int t_sum,rem=0;
	
	while(p!=NULL && q!=NULL)
	{
		t_sum=p->data+q->data+rem;
		if(t_sum>9)
		{
			insert_end(&head3,(t_sum-10));
			rem=1;
		}
		else
		{			
			insert_end(&head3,t_sum);
			rem=0;
		}		
		p=p->next;
		q=q->next;
	}
	while(p!=NULL)
	{
		t_sum=p->data+rem;
		if(t_sum>9)
		{
			insert_end(&head3,(t_sum-10));
			rem=1;
		}	
		else
		{
			insert_end(&head3,t_sum);
			rem=0;
		}
		p=p->next;	
	}
	while(q!=NULL)
	{
		t_sum=q->data+rem;
		if(t_sum>9)
		{
			insert_end(&head3,(t_sum-10));
			rem=1;
		}	
		else
		{
			insert_end(&head3,t_sum);
			rem=0;
		}
		q=q->next;	
	}
	if(rem==1)
		insert_end(&head3,1);
	rev(head1);
	rev(head2);
	rev(&head3);
	return head3;
}

int main()
{
	struct Node*head1=NULL,*head2=NULL;
	insert_end(&head1,9);
	insert_end(&head1,9);
	//insert_end(&head1,9);
	insert_end(&head2,9);
	insert_end(&head2,9);
	struct Node*a=add(&head1,&head2);
	display(head1);
	display(head2);
	display(a);
	return 0;
}
