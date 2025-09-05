class Solution {
public:
   int kthSmallest1(TreeNode* root, int k, int &cnt) {
        if (!root) return -1;

        // search in left subtree
        int left = kthSmallest1(root->left, k, cnt);
        if (left != -1) return left;

        cnt++;
        if (cnt == k) return root->val;

        // search in right subtree
        return kthSmallest1(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return kthSmallest1(root, k, cnt);
    }
};
*********************************kth largest****************************
   int countNodes(Node*root)
    {
        if(root==NULL)
         return 0;
         
         int a=countNodes(root->left);
         int b=countNodes(root->right);
         
         return 1+a+b;
         
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int n=countNodes(root);
        return kthSmallest(root,n-k+1);
    }
*********************************************************************************8888
   int kthLargest(TreeNode* root, int k, int &cnt) {
        if (!root) return -1;

        // search in left subtree
        int right = kthLargest(root->right, k, cnt);
        if (right != -1) return right;

        cnt++;
        if (cnt == k) return root->val;

        // search in right subtree
        return kthLargest(root->left, k, cnt);
    }

    int kthLargest(Node *root, int k) {
        // Your code here
        int cnt = 0;
        return kthSmallest1(root, k, cnt);
    }
