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
#include<stack>

 int return_size(BinaryTreeNode<int>* root)
 {
 	if(root==NULL)
 	  return 0;
   
    int x=return_size(root->left);
    int y=return_size(root->right);
        return x+y+1;
 }
 void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
     // Write your code here
 	if(root==NULL)
 	  return;
   stack<BinaryTreeNode<int>*> inorder,reverse;
 	BinaryTreeNode<int>* temp=root;
 	BinaryTreeNode<int>* rtemp=root;
    while(temp!=NULL)
     {
 		inorder.push(temp);
         temp = temp->left;
         }
         temp=root;
     while(temp!=NULL)
 	  {
       reverse.push(temp); 
 	  temp = temp->right;
           }
 		  int size=return_size(root); 
       int count=0;
    
  while(count<size) 
  {
     int i=0;
     //cout<<inorder.size()<<" "<< reverse.size()<<endl;
     if (inorder.size()==0 || reverse.size()==0)
       break;
       // cout<<"\n"<<"in:"<<inorder.top()->data<<" "<<reverse.top()->data<<" ";
       if (inorder.top()->data + reverse.top()->data == s) // && inorder.top()->data!=reverse.top()->data)
       {
         count++;
         if (inorder.top()->data != reverse.top()->data)
           cout << inorder.top()->data << " " << reverse.top()->data<<endl;
        temp=inorder.top();
        rtemp=reverse.top();
          inorder.top()->data=0;
        reverse.top()->data=0;
 	 inorder.pop();
 	 reverse.pop();
     
 	BinaryTreeNode<int>* rnode=rtemp->left;
   while(rnode->left!=NULL)
     rnode=rnode->left;
    
 	while(rnode!=NULL)
 	 {
           reverse.push(rnode);
           //cout<<"reversestack: "<<rnode->data<<" "; 
 		  rnode = rnode->right;
       }
       BinaryTreeNode<int> *node = temp->right;
      while (node != NULL) {
         //cout<<"inorderstack:"<<node->data<<" ";
         inorder.push(node);
         node = node->left;
       }
       //cout<<"details: ";
         //cout<<inorder.top()->data<<" "<<reverse.top()->data;
    }
    else if(inorder.top()->data+reverse.top()->data>s)
    { count++;
     rtemp=reverse.top();
 	   reverse.pop();
      BinaryTreeNode<int> *rnode = rtemp->left;
      while (rnode != NULL) {
        reverse.push(rnode);
        rnode = rnode->right;
      }
    }
    else
      { 
        count++;
        temp=inorder.top();
 		 inorder.pop();
     BinaryTreeNode<int> *node = temp->right;
      while (node != NULL) {
        inorder.push(node);
        node = node->left;
      }
          }
          //cout<<++i<<" ";
        
  }
  
    
 }
/*void inOrder(BinaryTreeNode<int> *root, vector<int>* v) {
	// Write your code here
    if(root==NULL)return;
    inOrder(root->left, v);
    (*v).push_back(root->data);
    inOrder(root->right, v);
    
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    vector<int> v;
    inOrder(root, &v);
    int arr[v.size()];
    for(int i=0;i<v.size();i++)arr[i]=v[i];
    int si = 0;
    int ei = v.size()-1;
    while(si<ei){
        int temp = arr[si]+arr[ei];
	    if(temp==s){
            cout<<arr[si++]<<" "<<arr[ei--]<<endl;
        }
        else if(s<temp)ei--;
        else{si++;}
    }    
}
/*

int return_size(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	  return 0;
   
   int x=return_size(root->left);
   int y=return_size(root->right);
       return x+y+1;
}
#include<stack>
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
	if(root==NULL)
	  return;
  stack<int> inorder,reverse;
	BinaryTreeNode<int>* temp=root;
	BinaryTreeNode<int>* rtemp=root;
   while(temp!=NULL)
    {
		inorder.push(temp->data);
        temp = temp->left;
        }
        while (rtemp != NULL) {
          reverse.push(rtemp->data);
          rtemp = rtemp->right;
        }
        int size = return_size(root);
 while(inorder.size()!=size || reverse.size()!=size || inorder.empty() || reverse.empty() )
 {
   if (inorder.top()+reverse.top() == s)
    {
     cout << inorder.top() << " " << reverse.top();
	 inorder.pop();
	 reverse.pop();
	BinaryTreeNode<int>* rnode=rtemp->left;
	while(rnode!=NULL)
	 {
          reverse.push(rnode->data); 
		  rnode = rnode->right;
      }
      BinaryTreeNode<int> *node = temp->right;
      while (node != NULL) {
        reverse.push(node->data);
        node = node->left;
      }
   }
   else if(inorder.top()+reverse.top()>s)
   {
	   reverse.pop();
     BinaryTreeNode<int> *rnode = rtemp->left;
     while (rnode != NULL) {
       reverse.push(rnode->data);
       rnode = rnode->right;
     }
   }
   else
     { 
		 inorder.pop();
     BinaryTreeNode<int> *node = temp->right;
     while (node != NULL) {
       reverse.push(node->data);
       node = node->left;
     }
         }
}
}*/