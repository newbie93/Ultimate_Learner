#include"linked_list_def.h"

int cmp(struct Node*head1,struct Node*head2)
{
	while(1)
	{
		if(head1==NULL && head2==NULL)
			return 0;
		else if(head1==NULL && head2!=NULL)
			return 1;
		else if(head1!=NULL && head2==NULL)
			return -1;
		else
		{
			if(head1->data>head2->data)
				return -1;
			else if(head1->data<head2->data)
				return 1;
			else ;	
		}
		head1=head1->next;
		head2=head2->next;
	}	
	return 0;
}

int main()
{
	struct Node*head1=NULL,*head2=NULL;
	insert_end(&head1,'a');
	insert_end(&head1,'b');
	insert_end(&head1,'c');
	insert_end(&head1,'d');
	insert_end(&head1,'e');
	//insert_end(&head1,'f');
	//insert_end(&head1,'g');
	insert_end(&head2,'a');
	insert_end(&head2,'x');
	insert_end(&head2,'c');
	insert_end(&head2,'d');
	insert_end(&head2,'e');
	insert_end(&head2,'f');
	//insert_end(&head2,'g');
	printf("%d\n",cmp(head1,head2));
	return 0;
}
