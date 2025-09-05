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
