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
#include<limits.h>
bool check(BinaryTreeNode<int>* root,int max,int i=0)
{
  if (root == NULL)
    return true;
	if(i%2==0)
	  {
		  if(root->data>=max)
		    return false;
	  } 
	  else
	   {
		   if(root->data<max)
		    return false;
	   }
	bool x= check(root->left,root->data,i=2);
	if(!x)
	 return false;
	 return check(root->right,root->data,i=1);

}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	return check(root,INT_MAX,0);

}
/*#include <limits.h>

bool isbst3(BinaryTreeNode<int> *root, int min, int max) {
  if (root == NULL)
    return true;
  if (root->data > max || root->data < min)
    return false;
  bool isleftok = isbst3(root->left, min, root->data);
  bool isrightok = isbst3(root->right, root->data, max);
  return isleftok && isrightok;
}
bool isBST(BinaryTreeNode<int> *root)
 { return isbst3(root, INT_MIN, INT_MAX); }*/