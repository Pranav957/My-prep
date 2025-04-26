/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
int replaceWithLargerNodesSum2(BinaryTreeNode<int> * root,int sum)
{
	if(root==NULL)
	  return sum;
	  sum=replaceWithLargerNodesSum2(root->right,sum);
           sum+=root->data;
		   root->data=sum;
	sum=replaceWithLargerNodesSum2(root->left,sum);
	return sum;
}
 /*int replaceWithLargerNodesSum2(BinaryTreeNode<int> *root,int M)
{
	if(root==NULL)
	   return 0;
	 int x=replaceWithLargerNodesSum2(root->right,M);
	 int p=root->data+x;
	 root->data=root->data+M+x;
	  int y= replaceWithLargerNodesSum2(root->left,root->data);
	   return p+y;
	  // if(y>root->data)
	   //  return y;
		// else return root->data;
}*/
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
 int d=replaceWithLargerNodesSum2(root,0);

}