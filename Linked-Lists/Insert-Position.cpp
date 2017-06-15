/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/


Node* InsertNth(Node *head, int data, int position)
{
    Node *newNode = (Node*)malloc(sizeof(Node)); // allocate memory and create new node
    newNode->data = data;

    if (head == NULL) { // single element linked list
    newNode->next = NULL;
    return newNode;
    }

    if (position == 0) { // inserting at beginning
       newNode->next = head;
       return newNode;
    }

    Node *currentNode = head; // traversing to insertion position
    while (position - 1 > 0) {
        currentNode = currentNode->next;
        position--;
    }

    newNode->next = currentNode->next; // splice in node by rearranging pointers
    currentNode->next = newNode;

    return head;
 }
