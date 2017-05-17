/*
 *      linked_list_test.c
 *
 *      This file is written to test all the functions written in linked_list_def.h
 *
 *      Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */

#include"../Linked_List_Header/linked_list_def.h"

int main()
{
	struct Node*head=NULL;
	/*
	 * Insert your own data...
	 */
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,4);
	display(head);
	insert_first(&head,0);
	display(head);
	/*
	 * Insert your own data...
	 */
	insert_before(&head,4,3);
	insert_before(&head,0,-2);
	insert_after(&head,-2,-1);
	insert_after(&head,4,5);
	display(head);
	/*
	 * Insert your own data...
	 */
	del_node(&head,-2);
	del_node(&head,5);
	del_node(&head,2);
	display(head);
	/*
	 * Insert your own data...
	 */
	rev(&head);
	display(head);
	return 0;
}