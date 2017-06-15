/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void Print(Node *head)
{
    int curnodenum = 0;
    Node *curnode;
    
    for (curnode = head; curnode; curnode = curnode->next){
        curnodenum++;
        /* 
        printf("curnodeno = %d, curnode val = %d \n", curnodenum, curnode->data );
        */
        printf("%d\n", curnode->data);
    }
/*
printf("List traversal done. total num elements = %d\n", curnodenum);
*/
}

/**************************************************************************************/

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  if(head != NULL){
      ReversePrint(head->next) ; // recursive definition
      printf("%d\n", head->data) ;
  }
  return ;
}
