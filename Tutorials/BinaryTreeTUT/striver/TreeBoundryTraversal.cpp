 bool isLeaf(Node* node)
 {
     if(node->left==NULL && node->right==NULL)
      return true;
      
      return false;
 }
void addLeftBoundry(Node* curr,vector<int>& res)
{
    while(curr)
    {
        if(!isLeaf(curr))
          res.push_back(curr->data);
        if(curr->left)
          curr=curr->left;
        else
         curr=curr->right;
    }
}

void addLeavses(Node* root, vector<int>& res)
{
    if(!root)
     return;
     
     if(root->left==NULL && root->right==NULL)
       res.push_back(root->data);
       
     addLeavses(root->left,res);
     addLeavses(root->right,res);
}

void addRightBoundry(Node* curr, vector<int>& res)
{
     vector<int> temp;
     while(curr)
    {
        if(!isLeaf(curr))
          temp.push_back(curr->data);
        if(curr->right)
          curr=curr->right;
        else
         curr=curr->left;
    }
    
    for(int i=temp.size()-1;i>=0;i--)
     res.push_back(temp[i]);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        
        if(!isLeaf(root))res.push_back(root->data);
        
        addLeftBoundry(root->left,res);
        addLeavses(root,res);
        addRightBoundry(root->right,res);
        
        return res;
        
    }
};
