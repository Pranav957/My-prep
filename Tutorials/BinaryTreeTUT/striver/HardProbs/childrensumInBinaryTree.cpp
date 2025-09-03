class Solution {
  public:
    int isSumProperty(Node *root) {
    if (root == NULL) return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftVal = (root->left ? root->left->data : 0);
    int rightVal = (root->right ? root->right->data : 0);

    if (root->data != leftVal + rightVal)
        return 0;

    return isSumProperty(root->left) && isSumProperty(root->right);
}
};
********************************************maintainChildSumProperty*******************************************************
  void changeTree(BinaryTreeNode < int > * root) {
    
   
    if(root==NULL) return ;
    int x=root->left?root->left->data:0;
    int y=root->right?root->right->data:0;

    
   if(root->data>x+y)
   {
     if(root->left)root->left->data=root->data;
     if(root->right)root->right->data=root->data;  
   }
    

     changeTree(root->left);
     changeTree(root->right);

    int val=0;
    if(root->left)val+=root->left->data;
    if(root->right)val+=root->right->data;
    if(root->left || root->right)root->data=val;
    
}
