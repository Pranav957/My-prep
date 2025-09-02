 bool helper(TreeNode<int>* root,int x, vector<int>& ans)
 {
	 if(root==NULL)return false;

      ans.push_back(root->data);

	 if(root->data==x)
	 {
		 return true;
	 }
	  if(helper(root->left,x,ans)||helper(root->right,x,ans))
	   return true; 

	  ans.pop_back(); 
	  
	  return false;
 }
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	helper(root,x,ans);
	return ans;

}
*******************************************************rootTOLEAFALLPATHS***********************************************************
	void helper(Node* root,vector<vector<int>>& ans,vector<int> res)
    {
        if(root==NULL)return;
        
        if(!root->left && !root->right)
        {
           res.push_back(root->data);
           ans.push_back(res);
           return;
        }
        
        res.push_back(root->data);
        
        helper(root->left,ans,res);
        helper(root->right,ans,res);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> res;
         helper(root,ans,res);
        return ans;
    }
