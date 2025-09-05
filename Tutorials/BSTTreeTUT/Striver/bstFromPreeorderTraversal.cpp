class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& arr, int i, int bound)
    {
        if(i==arr.size()|| arr[i]>bound)return NULL;

        TreeNode* root=new TreeNode(arr[i++]);

        root->left=bstFromPreorder(arr,i,root->val);
        root->right=bstFromPreorder(arr,i,bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        return bstFromPreorder(arr,0,INT_MAX);
    }
};
********************************************************************
directly create binary tree for each node->o(n*n);
sort array and start constructing with in and pre order, nlogn+n;
******************************************************************
