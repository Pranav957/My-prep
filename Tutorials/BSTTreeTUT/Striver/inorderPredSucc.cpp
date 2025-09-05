class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* succ=NULL,*pred=NULL;
        Node* temp=root;
        
        while(temp!=NULL)
        {
            if(key<=temp->data)
              temp=temp->left;
            else
             {
                 pred=temp;
                 temp=temp->right;
             }
        }
       temp=root;
        while(temp!=NULL)
        {
            if(key>=temp->data)
             temp= temp->right;
            else
            {
                succ=temp;
                temp=temp->left;
            }
        }
        
        vector<Node*> v;
        v.push_back(pred);
        v.push_back(succ);
        return v;
    }
};
