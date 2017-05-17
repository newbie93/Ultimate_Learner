/*
 *      stack_using_lists.c
 *
 *      Here, a Stack has been implemented using Linked List.
 *
 *      Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */

#include"linked_list_def.h"

void push(struct Node**top,int data)
{
	insert_first(top,data);
}

struct Node*pop(struct Node**top)
{
	assert(!is_list_empty(*top));
	return rem_first(top);
}

int is_stack_empty(struct NOde*top)
{
	return is_list_empty(top); // 1 if Empty; 0 if NOT Empty.
}

int main()
{
	struct Node*top=NULL;
	/*
	 * Insert your own data...
	 */
	push(&top,5);
	push(&top,4);
	push(&top,3);
	push(&top,2);
	push(&top,1);
	/*
	 */
	while(is_stack_empty(top)!=1)
			printf("%d\n",pop(&top)->data);

	return 0;
}
