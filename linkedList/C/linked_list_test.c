#include "linked_list_def.h"

int main()
{
	struct Node*head=NULL;
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,4);
	display(head);
	insert_first(&head,0);
	display(head);
	insert_before(&head,4,3);
	insert_before(&head,0,-2);
	insert_after(&head,-2,-1);
	insert_after(&head,4,5);
	display(head);
	del_node(&head,-2);
	del_node(&head,5);
	del_node(&head,2);
	display(head);
	return 0;
}
