// Following is the Binary Tree node structure
/**************
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
***************/

 
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
        if (root == NULL) {
          vector<int> *temp =new vector<int>();
          return temp;
        }

        // Recursive call on root->right
        vector<int>* rightvect = longestPath(root->right);

        // Recursive call on root->left
        vector<int>* leftvect = longestPath(root->left);

        // Compare the size of the two vectors
        // and insert current node accordingly
        if (leftvect->size() > rightvect->size())
          leftvect->push_back(root->data);

        else
          rightvect->push_back(root->data);

        // Return the appropriate vector
        return (leftvect->size() > rightvect->size() ? leftvect : rightvect);
}
