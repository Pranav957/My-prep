/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include<queue>
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
       TreeNode<int>* front=pending.front();
       pending.pop();
       cout<<front->data<<":";
       for(int i=0;i<front->children.size();i++)
       {
           cout<<front->children[i]->data;
           pending.push(front->children[i]);
           if(i!=front->children.size()-1)
             cout<<",";
       }
       cout<<endl;
    }


}