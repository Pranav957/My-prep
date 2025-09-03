class Solution {
  public:
    int isSumProperty(Node *root) {
    if (root == NULL) return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftVal = (root->left ? root->left->data : 0);
    int rightVal = (root->right ? root->right->data : 0);

    if (root->data != leftVal + rightVal)
        return 0;

    return isSumProperty(root->left) && isSumProperty(root->right);
}
};
