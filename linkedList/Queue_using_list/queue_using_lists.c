/*
 *	queue_using_lists.c
 *
 *	Here, a Queue has been implemented using Linked List, and enqueue and dequeue functions.
 *	read: https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
 *
 *	Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */

 #include"../Linked_List_Header/linked_list_def.h"


 /*
  *	This is a simple structure of a queue, containing a rear pointer.
  */
 struct Queue{struct Node*rear;};



 /*
  *	This function creates a new Queue, and returns the queue pointer.
  */
 struct Queue* create_queue()
 {
 	struct Queue*queue=(struct Queue*)malloc(sizeof(struct Queue));
 	queue->rear=NULL;
 	return queue;
 }



 /*
  *	We enqueue(or insert) the new element in the rear of the queue, or back of the list
  *   here front is there just for logical understanding, it is not implemented in that way.
  *	eg. if existing list is:
  *					rear -> 1 -> 2 -> 3 <- front
  *	we want to enqueue 100 then:
  *					rear -> 100 -> 1 -> 2 -> 3 <- front
  */
 void enqueue(struct Queue*queue,int data)
 {
 	insert_first(&(queue->rear),data);
 }



 /*
  *	We remove the front element, or the first entered element.
  *	eg. if the existing list is:
  *						rear -> 1 -> 2 -> 3 <- front
  *	on executing dequeue, it returns 3 & the list becomes
  *						rear -> 1 -> 2 <- front
  */
 struct Node*dequeue(struct Queue*queue)
 {
 	assert(!is_list_empty(queue->rear));
 	return rem_end(&(queue->rear));
 }



 /*
  *	This returns whether the Queue is empty
  */
 int is_queue_empty(struct Queue*queue)
 {
 	return is_list_empty(queue->rear); // 1 if Empty; 0 if NOT Empty.
 }



 /*
  *	Tests the Queue functionalities
  */
 int main()
 {
 	struct Queue*queue=create_queue();
 	/*
 	 * Insert your own data...
 	 */
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    enqueue(queue,50);
 	/*
 	 */
 	while(is_queue_empty(queue)!=1)
 			printf("%d\n",dequeue(queue)->data);

 	return 0;
 }
