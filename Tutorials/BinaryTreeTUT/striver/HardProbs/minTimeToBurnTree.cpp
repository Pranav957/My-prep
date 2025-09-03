class Solution {
  public:
    Node* markParents(Node* root, unordered_map<Node*, Node*>& mp,int target)
    {
        queue<Node*> q;
        q.push(root);
        Node* res;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            if(node->data==target)res=node;

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
        return res;
    }
    int minTime(Node* root, int target) {
        // code here
         unordered_map<Node*, Node*> parentTrack;
         Node* tagNode=markParents(root,parentTrack,target);
         
         unordered_map<Node* ,bool> visited;
        queue<Node*> q;
        q.push(tagNode);
        visited[tagNode]=true;
        int count=0;

        while(!q.empty())
        {
            int size=q.size();
            int fl=0;
            
            for(int i=0;i<size;i++)
            {
               Node* node=q.front();
                q.pop();

                if(node->left && !visited[node->left])
                 {
                    q.push(node->left);
                    visited[node]=true;
                    fl=1;
                 }

                 if(node->right && !visited[node->right])
                 {
                    q.push(node->right);
                    visited[node]=true;
                    fl=1;
                 }

                 if(parentTrack[node] && !visited[parentTrack[node]])
                 {
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                    fl=1;
                 }
            }
            if(fl)count++;
            
        }
        return count;
         
    }
};
