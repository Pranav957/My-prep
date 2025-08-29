class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* top=st.top();
            st.pop();

            preorder.push_back(top->val);

            if(top->right)
            st.push(top->right);

           if(top->left)
             st.push(top->left); 
        }

        return preorder;

    }
};
