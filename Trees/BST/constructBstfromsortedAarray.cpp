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
BinaryTreeNode<int> *constructTree(int input[],int si,int ei)
{
	if(si>ei)
	 return NULL;
	int mid=(si+ei)/2;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
	root->left=constructTree(input,si,mid-1);
	root->right=constructTree(input,mid+1,ei);
	return root; 
}
BinaryTreeNode<int> * constructTree(int *input, int n) {
  // Write your code here
  return constructTree(input, 0, n - 1);
}