 void rightSideView(TreeNode* root,int level,vector<int>& ans)
    {
         if(root==NULL)
          return ;

          if(level==ans.size())
           ans.push_back(root->val);

           rightSideView(root->right,level+1,ans);
           rightSideView(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSideView(root,0,ans);
        return ans;
    }
