
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int maxtrack=-1;
    while(node!=NULL){
        if(node->data==x) return node->data;
        else if (node->data > x) {
          maxtrack = node->data;
          node = node->left;
        } 
        else node = node->right;
    }
    return maxtrack;
}
