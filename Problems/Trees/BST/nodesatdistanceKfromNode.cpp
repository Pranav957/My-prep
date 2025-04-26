/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/
void search(BinaryTreeNode<int>* root, int k)
{
        if(root==NULL)
          return;
        if(k==0)
        {
                cout<<root->data<<endl;
                return;
        }  
        search(root->left, k-1);
        search(root->right, k-1); 

}
int nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    if(root==NULL)
      return -1;
   if(root->data==node)
   {
           search(root,k);
           return 0;
   }  
    int ld=nodesAtDistanceK(root->left,node,k);
    if(ld!=-1)
    {
            if(ld+1==k)
                 cout<<root->data<<endl;
            else
               search(root->right,k-(ld+1)-1);
               return ld+1;
    }
    int rd= nodesAtDistanceK(root->right,node,k);
    if (rd != -1) {

      if (rd + 1 == k)
        cout << root->data << " ";
      else
        search(root->left, k - (rd + 1) - 1);

      return rd + 1;
    }
    return -1;
    /*if(rd==-1)
      return -1;
    if(rd+1==k)
        cout<<root->data<<" ";
     else
        search(root->left,k-(ld+1)-1);*/
    }

/*

void search(BinaryTreeNode<int>* root, int k)
{
        if(root==NULL)
          return;
        if(k==0)
        {
                cout<<root->data<<endl;
                return;
        }  
        search(root->left, k-1);
        search(root->right, k-1); 

}
int nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k, int x)
{
   if(root==NULL)
     return -1;
     if(root->data==node)
     {
             search(root, k);
             return x;
     }
     x+=1;
     int d=nodesAtDistanceK(root->left,node,k,x);
        if(d!=-1)
        {
                if(k-d==0)
                  cout<<root->data<<endl;
                else  
                   search(root->right,k-d-1);
               return x; 
        }
     int p=nodesAtDistanceK(root->right,node,k,x);
     if (p != -1) {
          if (k-p == 0)
           cout << root->data << endl;
         else
            search(root->left, k - p-1);
        return x;
     }
}
 void nodesAtDistanceK(BinaryTreeNode<int> *root,int node, int k) {
  // Write your code herez
   int p=nodesAtDistanceK(root, node, k,0);
}*/