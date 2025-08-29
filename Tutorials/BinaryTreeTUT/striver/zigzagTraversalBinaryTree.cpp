class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
    if(root == NULL) return res;

    queue<TreeNode*> q;
    bool leftToRight = true;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        res.push_back(level);
        leftToRight = !leftToRight;  
    }

    return res;
    }
};
