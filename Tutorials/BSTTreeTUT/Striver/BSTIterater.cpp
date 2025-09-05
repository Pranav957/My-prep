class BSTIterator {
    stack<TreeNode*> st;
public:
     void pushAll(TreeNode* root)
     {
       for(;root!=NULL;root=root->left)
        st.push(root);
     }
    BSTIterator(TreeNode* root) {
       pushAll(root);
    }
    
    int next() {
       TreeNode* temp=st.top();
       st.pop();
       pushAll(temp->right);
       return temp->val; 
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
