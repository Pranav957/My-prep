class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, long long>> q;  // use long long
    q.push({root, 0});
    int width = 0;

    while (!q.empty()) {
        int size = q.size();
        long long first = q.front().second;
        long long last = first;  // init with first index

        for (int i = 0; i < size; i++) {
            auto [node, idx] = q.front();
            q.pop();

            // normalize index
            long long normIdx = idx - first;
            last = idx;

            if (node->left)
                q.push({node->left, 2 * normIdx + 1});
            if (node->right)
                q.push({node->right, 2 * normIdx + 2});
        }

        width = max(width, (int)(last - first + 1));
    }

    return width;
}
};
***********************************************************************************************************************************8888888
  class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int width=0;

        while(!q.empty())
        {
            int size=q.size();
           int first=0,last=0;

           for(int i=0;i<size;i++)
           {
              auto x=q.front();
              q.pop();
              TreeNode* node=x.first;
             if(first==0)
             {
                first=x.second;
                last=x.second;
             }
             else
              last=x.second;

              if(node->left)
              {
                q.push({node->left,2*(x.second-1)+1});
              }

              if(node->right)
              {
                q.push({node->right,2*(x.second-1)+2});
              }
           }
           width=max(width,last-first+1);
        }
        return width;
    }
};
