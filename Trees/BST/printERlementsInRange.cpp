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
//Binary tree implementation
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
	if(root==NULL)
	  return;
	  
	      elementsInRangeK1K2(root->left,k1,k2);
	  if(root->data>=k1 && root->data<=k2)
	      cout<<root->data<<" ";
            elementsInRangeK1K2(root->right, k1, k2);	  
}
//Binary search tree implementat
/*void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2) {
  // Write your code here
  if (root == NULL)
    return;
  if (root->data >= k2 || root->data > k1 && root->data < k2)
    elementsInRangeK1K2(root->left, k1, k2);
  if (root->data >= k1 && root->data <= k2)
    cout << root->data << " ";
  if (root->data <= k1 || root->data > k1 && root->data < k2)
    elementsInRangeK1K2(root->right, k1, k2);
}*/