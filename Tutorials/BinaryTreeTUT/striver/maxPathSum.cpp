class Solution {
public:
     int maxPathSum(TreeNode* root,int &pathSum) {
        if(root==NULL)
          return 0;

        int a=max(0,maxPathSum(root->left,pathSum));
        int b=max(0,maxPathSum(root->right,pathSum));
      
        pathSum=max(pathSum,root->val+a+b);
        
        return root->val+max(a,b);  
    }
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
         maxPathSum(root,pathSum);
        return pathSum;
    }
};
