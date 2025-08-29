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
*******************************************************
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

    if(root == NULL)return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);

        if(root->left != NULL){
            st1.push(root->left);
        }

        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
        st2.pop();
    }    
    return postorder;

    }
};
**********************************************************************allTraversals*******************
    vector<vector<int>> preInPostTraversal(Node* root) {

    vector<int> pre, in, post;
    if (root == NULL) {
        return {};
    }
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it); 
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it); 
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
    
