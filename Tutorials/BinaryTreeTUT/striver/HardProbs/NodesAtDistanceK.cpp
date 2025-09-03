/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node->left)
            {
                mp[node->left]=node;
                q.push(node->left);
            }

            if(node->right)
            {
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentTrack;
        markParents(root,parentTrack);

        unordered_map<TreeNode* ,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int count=0;

        while(!q.empty())
        {
            int size=q.size();
            if(count==k)break;
            count++;
            for(int i=0;i<size;i++)
            {
               TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited[node->left])
                 {
                    q.push(node->left);
                    visited[node]=true;
                 }

                 if(node->right && !visited[node->right])
                 {
                    q.push(node->right);
                    visited[node]=true;
                 }

                 if(parentTrack[node] && !visited[parentTrack[node]])
                 {
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                 }
            }
            
        }
        vector<int> ans;
            while(!q.empty())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }

            return ans;
    }
};
