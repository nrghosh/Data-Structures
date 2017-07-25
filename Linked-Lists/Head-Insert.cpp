/*
  Insert Node at the beginning of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked listf.
*/


Node* Insert(Node *head,int data){ // Constant O(1) cost operation
    return new Node{data, head} ;
}

// Create a new node n
// Point node n (n->next) to first element of linked list, establish positioning
// Make "head" refer to n (now first element)
