class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;

        inorder(root);

        if (first && last) {
            std::swap(first->val, last->val);
        } else if (first && middle) {
            std::swap(first->val, middle->val);
        }
    }
};

*****************************************************************************
class Solution {
    Node* prev=NULL;
    Node* first=NULL;
    Node*second=NULL;
  public:
   void inorder(Node* root)
   {
       if(root==NULL)
        return;
        
        inorder(root->left);
        
        if(prev!=NULL)
        {
            if(prev->data>root->data)
             {
                 if(first==NULL)
                  first=prev;
                  second=root;
             }
        }
        prev=root;
        
        inorder(root->right);
   }
    void correctBST(Node* root) {
        // add code here.
        inorder(root);
        int temp=first->data;
     first->data=second->data;
     second->data=temp;
    }
};
