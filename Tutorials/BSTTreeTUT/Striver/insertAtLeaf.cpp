 TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root==NULL)
         {
            TreeNode* newNode=new TreeNode(val);
            return newNode;
         }

         if(val<root->val)
           root->left= insertIntoBST(root->left,val);
         else
            root->right= insertIntoBST(root->right,val);

          return root;  
    }
************************************************************************

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root==NULL)
         {
            TreeNode* newNode=new TreeNode(val);
            return newNode;
         }

         TreeNode* curr=root;
         while(true)
         {
            if(val>curr->val)
            {
                if(curr->right)curr=curr->right;
                else
                 {
                    curr->right=new TreeNode(val);
                    break;
                 }
            }
            else
            {
                if(curr->left)curr=curr->left;
                else
                {
                     curr->left=new TreeNode(val);
                     break;
                }
            }
         }
         return root;  
    }
};
