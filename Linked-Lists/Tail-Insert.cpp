/*
Insert Node at the end of a linked list 
head pointer input could be NULL as well for empty list
 
Node is defined as 
 struct Node
 {
    int data;
    struct Node *next;
 }
*/

Node* Insert(Node *head,int data){
  
  // first create the new node
    Node *temp=new Node();
    temp->data = data;
    temp->next = NULL;

  // check status of preexisting linked list
    if(head == NULL){
        head = temp;
    } 
    else { // if there's already a linked list body
      Node *p;
      p = head;
  
      while(p->next != NULL){ // Traverse to end of linked list (O(n) cost)
        p = p->next ;
      }
      // insert at the endpoint
      p->next = temp;
    }
  return(head);
}
