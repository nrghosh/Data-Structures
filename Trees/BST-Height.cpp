/*

Height of a BST


The tree node has data, left child tree and right child tree
class Node {
    int data;
    Node* left;
    Node* right;
};
*/

int height(Node* root){
    if(root == NULL){
        return -1;
    } else {
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if(lHeight >= rHeight){
            return lHeight+1;
        } else {
            return rHeight+1;
        }
    }
}
