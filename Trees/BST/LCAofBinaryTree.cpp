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

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
	if(root==NULL)
	  return -1;
	  if(root->data==a|| root->data==b)
	    return root->data;
	 int x=getLCA(root->left,a,b);
	 int y=getLCA(root->right,a,b);
	 if(x==a && y==b || x==b && y==a)
	   return root->data;
	 if(x!=-1)
	   return x;
	 if(y!=-1)
	   return y;    	
	   if(x==-1 && y==-1)
	     return -1;
}