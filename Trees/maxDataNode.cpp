/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
     TreeNode<int>* Max=root;
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>* temp=maxDataNode(root->children[i]);
        if(temp->data>Max->data)
           Max= temp;
    }
   // if(Max>root)
       return Max;
   // return root;
}