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

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root==NULL)
	  return NULL;
	  if(root->data==data)
	  {
		  vector<int>* v=new vector<int>;
		  v->push_back(root->data);
          return v;
	  }
   if(data<root->data)
     {
     vector<int> *leftop = getPath(root->left, data);
         if (leftop != NULL) {
            leftop->push_back(root->data);
            return leftop;
        }
   }
   else
   {
     vector<int> *rightop = getPath(root->right, data);
     if (rightop != NULL) {
       rightop->push_back(root->data);
       return rightop;
      }
     }
	 return NULL;
}