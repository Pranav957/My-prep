// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
TreeNode<int> *removeLeafNodes(TreeNode<int> *root)
{
  if (root == NULL)
    return NULL;
  int n = root->numChildren();
  if (n == 0) {
    delete root;
    return NULL;
  }

  for (int i = n - 1; i >= 0; i--) {
    TreeNode<int> *child = root->getChild(i);
    child = removeLeafNodes(child);
    if (child == NULL)
      root->removeChild(i);
    else
      root->setChild(i, child);
  }
  return root;
}

    /*TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
        // Write your code here
            if(root->numChildren()==0)
                 return NULL;
      for(int i=0;i<root->numChildren();i++)
      {
              TreeNode<int>* temp=removeLeafNodes(root->getChild(i));
              if(temp==NULL)
                 root->removeChild(i);
      }
      return root;
    }*/
   
