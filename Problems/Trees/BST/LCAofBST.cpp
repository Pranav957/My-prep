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

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
	if(root==NULL)
	   return -1;
	  if(root->data==val1 || root->data==val2)
	       return root->data;
	 if(val1<root->data && val2<root->data)
	     {
           return getLCA(root->left, val1, val2);
         }
	 else if(val1>root->data && val2>root->data)
	     return getLCA(root->right,val1,val2);
     else
	     	 {
				  int a=val1,b=val2;
       int x = getLCA(root->left, a, b);
       int y = getLCA(root->right, a, b);
       if (x == a && y == b || x == b && y == a)
         return root->data;
       if (x != -1)
         return x;
       if (y != -1)
         return y;
       if (x == -1 && y == -1)
         return -1;
         }
		 
		 
		 }