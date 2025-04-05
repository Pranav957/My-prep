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
#include<limits.h>
class BSTPDM
{
	public:
      int Min;
      int Max;
      int Height;
      bool isBST;
	 BSTPDM()
	 {
		 Min=INT_MAX;
		 Max=INT_MIN;
		 Height=0;
		 isBST=true;
	 } 

};
BSTPDM largestBSTSubtree2(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)
	{
		BSTPDM b;
		return b;
	}
	BSTPDM leftoutput=largestBSTSubtree2(root->left);
	BSTPDM rightoutput=largestBSTSubtree2(root->right);
	BSTPDM k;
        k.isBST = leftoutput.Max<root->data && rightoutput.Min>=root->data && leftoutput.isBST && rightoutput.isBST;
		k.Max=max(root->data, max(leftoutput.Max,rightoutput.Max));
		k.Min=min(root->data,min(leftoutput.Min,rightoutput.Min));
		 k.Height = max(leftoutput.Height, rightoutput.Height) ;
		if(k.isBST)
                k.Height+=1; 
                return k;
		
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBSTSubtree2(root).Height;
}