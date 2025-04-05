/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include<limits.h>
class BST {
    // Define the data members
    BinaryTreeNode<int>* node;
   public:
    BST() { 
        // Implement the Constructor
        node=NULL;
    }
    ~BST()
    {
        delete node;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
     bool search(int data,BinaryTreeNode<int>* root)
     {
         if(root==NULL)
           return false;
          if(root->data==data)
           return true;
          if(data<root->data)
          return search(data,root->left);
         else
           return search(data,root->right);    
     }
     void print(BinaryTreeNode<int>* root)
     {
         if(root==NULL)
           return;
        cout<<root->data<<":";
        if(root->left)
          cout<<"L:"<<root->left->data<<",";
        if(root->right)
         cout<<"R:"<<root->right->data;
         cout<<endl;
         print(root->left);
         print(root->right);    
     }
     BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* root)
     {
         if(root==NULL)
         {
            BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(data);
            node1->right=NULL;
            node1->left=NULL;
            return node1;
         }
         if(root->data==data)
             root->left=insert(data, root->left);
         else if(data<root->data)
           root->left=insert(data,  root->left);
         else
           root->right=insert(data, root->right);
           return root;  
     }
     int Minimum(BinaryTreeNode<int>* root)
     {
         if(root==NULL)
           return INT_MAX;
           return min(root->data,min(Minimum(root->left),Minimum(root->right))); 
     }
     BinaryTreeNode<int>* remove(int data,BinaryTreeNode<int>* root)
     {
           if(root==NULL)
              return NULL;
           if(root->data==data)
           {
               if(root->left==NULL && root->right==NULL)
                  {
                    delete root;
                    return NULL;
                  } 
              else  if (root->left != NULL && root->right == NULL)
               {
                   BinaryTreeNode<int>* temp=root->left;
                   root->left=NULL;
                   delete root; //deletes whole tree
                    return temp;
               }
              else  if (root->left == NULL && root->right != NULL)
               {
                 BinaryTreeNode<int> *temp = root->right;
                 root->right = NULL;
                 delete root; // deletes whole tree
                 return temp;
                 
               }
               else
               {
                 BinaryTreeNode<int>* Minimum=root->right;
                 while(Minimum->left!=NULL)
                      Minimum=Minimum->left;
                    int Min=Minimum->data;
                      root->data=Min;
                      root->right=remove(Min,root->right);
                      return root;
                   /*int Min=Minimum(root->right);
                   BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(Min);
                   node1->left=root->left;
                   if(root->right->data==node1->data)
                     node1->right=root->right->right;
                   else  
                     node1->right=root->right;
                   remove(Min,root->right);
                   root->right=NULL;
                   root->left=NULL;
                   delete root;
                     return node1;*/
               }
           }
           else if(data<root->data)
           {
               root->left=remove(data,root->left);
               return root;
           }
           else
            {
             root->right = remove(data, root->right);
             return root;
            }
     }
 public:
    void remove(int data) { 
        // Implement the remove() function 
     node=remove(data,node);
    }

    void print() { 
        // Implement the print() function
        print(node);
    }

    void insert(int data) { 
        // Implement the insert() function 
         node=insert(data,node);
    }

    bool search(int data) {
		// Implement the search() function 
        return search(data,node);
    }
};