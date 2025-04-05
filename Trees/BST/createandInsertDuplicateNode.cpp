/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)  //if NUll tree is given
     return;
     BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(root->data);
     BinaryTreeNode<int>* temp=root->left;
     root->left=newNode;
     newNode->left=temp;
     insertDuplicateNode(temp);
     insertDuplicateNode(root->right);
}