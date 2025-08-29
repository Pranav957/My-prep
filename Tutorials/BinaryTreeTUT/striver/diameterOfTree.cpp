class Solution {
public:
     int getHeight(TreeNode* root) {
        if(root==NULL)
         return 0;

        int a= getHeight(root->left);
         int b=getHeight(root->right);

         return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL)
      return 0;
      
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    int leftD=diameterOfBinaryTree(root->left);
    int rightD=diameterOfBinaryTree(root->right);
    
    return max((leftHeight+rightHeight),max(leftD,rightD));
    }
};
**********************************************************************************
class Solution {
public:
     int getHeight(TreeNode* root, int& diameter) {
        if(root==NULL)
         return 0;

        int lh= getHeight(root->left,diameter);
         int rh=getHeight(root->right,diameter);

         diameter=max(diameter,lh+rh);

         return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        getHeight(root,diameter);
        return diameter;
    }
};
