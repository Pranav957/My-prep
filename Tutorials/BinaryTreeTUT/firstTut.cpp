#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
   T data;
   BinaryTreeNode* left;
   BinaryTreeNode* right;
   
   BinaryTreeNode(T data)
   {
       this->data=data;
       left=NULL;
       right=NULL;
   }
   ~BinaryTreeNode()
   {
       delete left;
       delete right;
   }
};

void printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
      return;
     
     cout<<root->data<<": ";
     if(root->left)
      cout<<"L"<<root->left->data;
      
      if(root->right)
       cout<<" R"<<root->right->data;
       cout<<endl;
     
     printTree(root->left);
     printTree(root->right);
      
}
void inOrderTrav(BinaryTreeNode<int>* root)
{
    if(root==NULL)
     return;
     
     inOrderTrav(root->left);
     cout<<root->data<<" ";
     inOrderTrav(root->right);
}
void preOrderTrav(BinaryTreeNode<int>* root)
{
    if(root==NULL)
     return;
      cout<<root->data<<" ";
     preOrderTrav(root->left);
     preOrderTrav(root->right);
}
void postOrderTrav(BinaryTreeNode<int>* root)
{
    if(root==NULL)
     return;
     
     postOrderTrav(root->left);
     postOrderTrav(root->right);
      cout<<root->data<<" ";
}
BinaryTreeNode<int>* takeInput()
{
   cout<<"Enter  data: ";
   int rootData;
   cin >> rootData;
   if(rootData==-1)
     return NULL;
   
   BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
   
   root->left=takeInput();
   root->right=takeInput();
   return root;
   
}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"enter data";
    cin >> rootData;
    if(rootData==-1)
      return NULL;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        
        cout<<"Enter the left child node for "<<front->data;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData!=-1)
        {
         BinaryTreeNode<int>* leftChild=new BinaryTreeNode<int>(leftChildData);
        front->left=leftChild;
        pendingNodes.push(leftChild);
        }
        cout<<"Enter the right child for"<<front->data;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData!=-1)
         {
             BinaryTreeNode<int>* rightChild=new BinaryTreeNode<int>(rightChildData);
             front->right=rightChild;
             pendingNodes.push(rightChild);
         }
        
    }
    return root;
    
}
int NumberOfNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
      return 0;
      
     int leftsubNodes=NumberOfNodes(root->left);
     int rightsubNodes=NumberOfNodes(root->right);
      
      return 1+leftsubNodes+rightsubNodes;
}

BinaryTreeNode<int>* constructTree(int* preOrder, int* inOrder,int inS,int inE,int preS,int preE)
{
    if(inE<inS || preE<preS)
      return NULL;
      
    int rootData=preOrder[preS];
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    
    int i=inS;
    while(inOrder[i]!=rootData)
     i++;
    
    int linS=inS;
    int linE=i-1;
    int lpreS=preS+1;
    int lpreE=linE-linS+lpreS;
    root->left=constructTree(preOrder,inOrder,linS,linE,lpreS,lpreE);
    
    int rinS=i+1;
    int rinE=inE;
    int rpreS=lpreE+1;
    int rpreE=preE;
    
    root->right=constructTree(preOrder,inOrder,rinS,rinE,rpreS,rpreE);
    
    return root;
}

int main()
{
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(10);// 10 20 30 40 50 6 2 5 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTreeNode<int>* left=new BinaryTreeNode<int>(20);
    // BinaryTreeNode<int>* right=new BinaryTreeNode<int>(30);
    // root->left=left;
    // root->right=right;
    // printTree(root);
    // BinaryTreeNode<int>* node=takeInputLevelWise();
    // printTree(node);
    // cout<<NumberOfNodes(node);
    // preOrderTrav(node);
    // cout<<endl;
    // postOrderTrav(node);
    // cout<<endl;
    // inOrderTrav(node); 
    int preOrder[8]={10,20,40,5,50,30,6,2};
    int inOrder[8]={5,40,20,50,10,6,30,2};
    BinaryTreeNode<int>* root=constructTree(preOrder,inOrder,0,7,0,7);
    printTree(root);
    return 0;
}
