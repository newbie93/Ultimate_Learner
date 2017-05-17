/*
 *	stack_using_lists.c
 *
 *	Here, a Stack has been implemented using Linked List, and push and pop functions.
 *	read: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 *
 *	Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */

#include"../Linked_List_Header/linked_list_def.h"


/*
 *	This is a simple structure of a stack, containing only a Top pointer.
 */
struct Stack{struct Node*top;};



/*
 *	This function creates a new Stack, and returns the stack pointer.
 */
struct Stack* create_stack()
{
	struct Stack*stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=NULL;
	return stack;
}



/*
 *	We push the new element in the front of the list, or TOP of the list
 *	eg. if existing list is:
 *					top -> 1 -> 2 -> 3 -> NULL
 *	we want to push 100 then:
 *					top -> 100 -> 1 -> 2 -> 3 -> NULL
 */
void push(struct Stack*stack,int data)
{
	insert_first(&(stack->top),data);
}



/*
 *	We remove the top element, or the last entered element.
 *	eg. if the existing list is:
 *						top -> 1 -> 2 -> 3 -> NULL
 *	on executing pop, it returns 1 & the list becomes
 *						top -> 2 -> 3 -> NULL
 */
struct Node*pop(struct Stack*stack)
{
	assert(!is_list_empty(stack->top));
	return rem_first(&(stack->top));
}



/*
 *	This returns whether the Stack is empty
 */
int is_stack_empty(struct Stack*stack)
{
	return is_list_empty(stack->top); // 1 if Empty; 0 if NOT Empty.
}



/*
 *	Tests the Stack functionalities
 */
int main()
{
	struct Stack*stack=create_stack();
	/*
	 * Insert your own data...
	 */
	push(stack,5);
	push(stack,4);
	push(stack,3);
	push(stack,2);
	push(stack,1);
	/*
	 */
	while(is_stack_empty(stack)!=1)
			printf("%d\n",pop(stack)->data);

	return 0;
}
