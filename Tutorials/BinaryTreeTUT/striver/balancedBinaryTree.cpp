class Solution {
public:
   int maxDepth(TreeNode* root) {
        if(root==NULL)
         return 0;

        int a= maxDepth(root->left);
         int b=maxDepth(root->right);
         return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
          return true;

       if(abs(maxDepth(root->left)-maxDepth(root->right))>1)
        return false;
        
       bool a= isBalanced(root->left);
       bool b= isBalanced(root->right);
       return a && b;

    }
};
********************************************************************************88
  class Solution {
public:
   int getHeight(TreeNode* root) {
        if(root==NULL)
         return 0;

        int a= getHeight(root->left);
         int b=getHeight(root->right);

         if(a==-1 || b==-1) return -1;

         if(abs(a-b)>1)return -1;
         return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root)!=-1;
    }
};
