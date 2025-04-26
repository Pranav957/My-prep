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
#include<bits/stdc++.h>

/*#include<queue>
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	int *a=new int[1000000];
  queue<BinaryTreeNode<int>*> pendingnodes;
  pendingnodes.push(root);
  int k=0;
  while(pendingnodes.size()!=0)
  {
    BinaryTreeNode<int>* front=pendingnodes.front();
    pendingnodes.pop();
    a[k]=front->data;
    k++;
    if(front->left)
       pendingnodes.push(front->left);
    if(front->right)
    pendingnodes.push(front->right);   
  }
  sort(a,a+k);
  int i=0,j=k-1;
  while(i<j)
  {
    if(a[i]+a[j]==sum)
    {
      cout<<min(a[i],a[j])<<" ";
      cout<<max(a[i],a[j])<<endl;
      i++;
      j--;
    }
    if(a[i]+a[j]>sum)
      --j;
     if(a[i]+a[j]<sum)
       ++i; 
  } 
	

}
*/bool Find(BinaryTreeNode<int>* root,int x)
{
	if(root==NULL)
	  return false;
	  if(root->data==x)
	    return true;
	bool a =Find(root->left,x);
	if(a)
	 return a;
	 return Find(root->right,x);

}
#include<limits.h>
void pairSum(BinaryTreeNode<int> *root,BinaryTreeNode<int>* node, int sum) {
    // Write your code here
	if(root==NULL)
	   return;
	   pairSum(root->left, node, sum);
	   //if(root->data!=INT_MAX)
	  // {
		   int x=sum-root->data;
		    bool check=Find(node,x);
			if(root->data!=x)
			{
				   
			   if(check)
			   {
				cout<<min(x,root->data)<<" "<<max(root->data,x)<<endl;
				root->data=INT_MAX;
		    	}
			}

	  // } 
	   pairSum(root->right,node,sum); 

}
void pairSum(BinaryTreeNode<int>* root,int sum)
{
	pairSum(root,root,sum);
}
/*
#include<queue> 
int SearchFor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, int sum) {
  if (node == NULL)
    return 0;
  if (node->data != root->data) {
    if (root->data + node->data == sum) {
      if (root->data > node->data)
        return node->data;
      else
        return 0;
    }
  }
  int x= SearchFor(root, node->left, sum);
  if(x!=0)
    return x;
  return SearchFor(root, node->right, sum);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
  // Write your code here
  BinaryTreeNode<int> *node = root;
  if (root == NULL)
    return;
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0) {
    BinaryTreeNode<int> *temp = pendingNodes.front();
    pendingNodes.pop();
    int data = SearchFor(temp, node, sum);
    if (data != 0)
      cout << data << " " << temp->data << endl;
    if (temp->left)
      pendingNodes.push(temp->left);
    if (temp->right)
      pendingNodes.push(temp->right);
  }
}
#include<queue>
int SearchFor(BinaryTreeNode<int> *temp, BinaryTreeNode<int> *root, int sum) {
  if (root == NULL)
    return 0;
  if (temp->data == 5)
    //cout << root->data << " }";
	 if (root->data != temp->data) {
      if (temp->data + root->data == sum) {
        // if(root->data>temp->data)
        //  return 0;
        return root->data;
      }
    }
  int a= SearchFor(temp, root->left, sum);
  if(a!=0)
    return a;
  return SearchFor(temp, root->right, sum);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	BinaryTreeNode<int>* node=root;
	if(root==NULL)
	  return;
	 queue<BinaryTreeNode<int>*> pendingNodes;
	 pendingNodes.push(root);
	 while(pendingNodes.size()!=0)
	 {
		 BinaryTreeNode<int>* temp=pendingNodes.front();
		 pendingNodes.pop();
		 //cout<<"temp->data: "<<temp->data<<"|";
		 int data=SearchFor(temp,node,sum);
		 if(data!=0)
		   cout<<data<<" "<<temp->data<<endl;
		 if(temp->left)
		   pendingNodes.push(temp->left);
		 if(temp->right)
		   pendingNodes.push(temp->right);    
	 }
}*/