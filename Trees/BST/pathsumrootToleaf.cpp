/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<vector>
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root,int k, vector<int> v) 
{
if(root==NULL)
   return;
  if(root->left==NULL && root->right==NULL)
  {
	 
	  if(k==root->data)
	    {
            v.push_back(root->data);
            for (int i = 0; i < v.size(); i++)
              cout << v.at(i) << " ";
            cout << endl;
                } 
		 
	  return;
  }
  
    v.push_back(root->data);
   rootToLeafPathsSumToK(root->left,k-root->data,v);
   rootToLeafPathsSumToK(root->right,k-root->data,v);

}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
  // Write your code here
  vector<int> v;
  rootToLeafPathsSumToK(root,k,v);
}