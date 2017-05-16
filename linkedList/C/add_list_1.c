/*
 * Hello
 *
 */


#include"linked_list_def.h"

int list_to_int(struct Node*head)
{
	int sum=0;
	while(head!=NULL)
	{
		sum=sum*10+head->data;
		head=head->next;
	}
	return sum;
}

int add(struct Node*head1,struct Node*head2)
{
	return list_to_int(head1)+list_to_int(head2);
}

int main()
{
	struct Node*head1=NULL,*head2=NULL;
	insert_end(&head1,1);
	insert_end(&head1,0);
	insert_end(&head1,0);
	insert_end(&head2,2);
	insert_end(&head2,0);
	insert_end(&head2,2);
	printf("%d\n",add(head1,head2));
	return 0;
}
