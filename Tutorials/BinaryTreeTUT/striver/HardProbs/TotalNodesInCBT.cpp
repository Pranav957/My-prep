class Solution {
public:
   int getLeftHeight(TreeNode* root)
   {
      int ht=0;
      while(root!=NULL)
      {
        ht++;
        root=root->left;
      }
      return ht;
   }
   int getRightHeight(TreeNode* root)
   {
      int ht=0;
      while(root!=NULL)
      {
        ht++;
        root=root->right;
      }
      return ht;
   }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;

        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);

        if(lh==rh) 
         return (1<<lh)-1;

         return 1+countNodes(root->left)+countNodes(root->right);

    }
};
********************************************************************
class Solution {
public:
 void countNodes(TreeNode* root,int& cnt) {
        if(root==NULL)return ;
     
        cnt++;

        countNodes(root->left,cnt);
        countNodes(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        countNodes(root,cnt);
        return cnt;
    }
};
