/******************************************************************************************************************************
In this problem we implement three types of traversal of a binary tree
  1. Pre-Order
  2. Post-Order
  3. In-Order
  
The operation we choose to carry out on each element in this case is simply printing the element's "data" (an integer),
but that is an arbitrary operation- they key concept distinguishing the methods from each other is the order in which 
we traverse the tree.
******************************************************************************************************************************/
/*******************
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};
*******************/

void preOrder(node *root) {
    if(root == NULL){
        return;
    }else{
        printf("%d ", root->data);
        if(root->left != NULL){
            preOrder(root->left);
        }
        if(root->right != NULL){
            preOrder(root->right);
        }
    }
}

void postOrder(node *root) {
    if(root == NULL){
        return;
    } else {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node *root) {
    if(root == NULL){
        return;
    } else {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

