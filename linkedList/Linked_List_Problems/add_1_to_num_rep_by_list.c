/*
 *	add_1_to_num_rep_by_list.c
 *
 *    Here an integer is represented as a linked list, where each node carries 1 digit.
 *    eg. 931 is represented as: head -> 9 -> 3 -> 1 -> NULL
 *    Our task is to add 1 at the end of the integer and modify the representation accordingly.
 *
 *    eg. 931 + 1 = 932 : head-> 9 -> 3 -> 1 -> NULL; will become head-> 9 -> 3 -> 2 -> NULL
 *    eg. 999 + 1 = 1000: head-> 9 -> 9 -> 9 -> NULL; will become head-> 1 -> 0 -> 0 -> 0 -> NULL
 *
 *	Written by- Riju Ghosh | Ultimate_Learner | www.rijughosh.com | mail@rijughosh.com
 */


#include"../Linked_List_Header/linked_list_def.h"



/* Method 1: Recursively going to the last element adding 1 to it, getting the remainder*/
int add_1(struct Node*head)
{
      if(head==NULL)
            return 1;
      int sum=head->data+add_1(head->next);
      if(sum>9)
      {
            head->data=sum-10;
            return 1;
      }
      head->data=sum;
      return 0;
}

void do_add_1(struct Node**head)
{
      if(add_1(*head)>0)
            insert_first(head,1);
}
/* end of Method 1*/



/* Method 2: We reverse the list, head -> 1 -> 9 -> NULL becomes head -> 9 -> 1 -> NULL*/
int do_add_1_rev(struct Node**head)
{
      rev(head);
      struct Node*p=*head;
      int sum,rem=1;
      while(p!=NULL)
      {
            sum=p->data+rem;
            if(sum>9)
            {
                p->data=sum-10;
                rem=1;
            }
            else
            {
                p->data=sum;
                rem=0;
            }
            p=p->next;
      }
      if(rem>0)
            insert_end(head,1);
      rev(head);
}

/* end of Method 2*/



int main()
{
      struct Node*head=NULL;

      /*    Insert your own data...
      */
      insert_end(&head,9);
      insert_end(&head,9);
      insert_end(&head,9);
      do_add_1_rev(&head);
      display(head);

      return 0;
}
