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
***********************************************************

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> inorder;
        while(true)
        {
            if(node)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty())break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};
