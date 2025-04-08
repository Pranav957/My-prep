
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
     T data;
     vector<TreeNode<T>*> children;
    
    TreeNode(T data)
    {
        this->data=data;
    }
    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
          delete children[i];
    }
};

void printTree(TreeNode<int>* root)
{
    cout<<root->data<<": ";
    
    for(int i=0;i<root->children.size();i++)
      cout<<root->children[i]->data<<" ";
      
      cout<<endl;
      
      for(int i=0;i<root->children.size();i++)
        printTree(root->children[i]);
}


void postOrder(TreeNode<int>* root)
{
      for(int i=0;i<root->children.size();i++)
        postOrder(root->children[i]);
        
         cout<<root->data<<": ";
    
    for(int i=0;i<root->children.size();i++)
      cout<<root->children[i]->data<<" ";
      
      cout<<endl;
}

TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"enter root data:";
    cin >> rootData;
    
    TreeNode<int>* root=new TreeNode<int>(rootData);
    
    int n;
    cout<<"Enter number of childrens for "<<rootData<<"? ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLW()
{
    int rootData;
    cout<<"Enter root data";
    cin >> rootData;
    
    TreeNode<int>* root=new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes ;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        
        cout<<"Enter number of childrens for:"<<front->data<<"? ";
        int numChilds;
        cin >> numChilds;
        for(int i=0;i<numChilds;i++)
        {
            int childData;
            cout<<"Enter child data: ";
            cin >> childData;
            TreeNode<int>* childnode=new TreeNode<int>(childData);
            front->children.push_back(childnode);
            pendingNodes.push(childnode);
        }
    }
    return root;
}

int countNodes(TreeNode<int>* root)
{
    int n=1;
    for(int i=0;i<root->children.size();i++)
       n+=countNodes(root->children[i]);
    return n;  
}
int sumOfNodes(TreeNode<int>* root)
{
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
      sum+=sumOfNodes(root->children[i]);
    return sum;  
}
int maxDataNode(TreeNode<int>* root)
{
    int max=root->data;
    for(int i=0;i<root->children.size();i++)
     {
          int data=maxDataNode(root->children[i]);
          if(data>max)
           max=data;
     }
     return max;
      
}
void printAtLevelK(TreeNode<int>* root,int k)
{
    if(k==0)
     {
          cout<<"level "<<k<<": "<<root->data<<" ";
          return;
     }
      
      for(int i=0;i<root->children.size();i++)
      {
          printAtLevelK(root->children[i],k-1);
      }
}
int getLeafNodeCount(TreeNode<int>* root)
{
    if(root==NULL)
      return 0;
    if(root->children.size()==0)
      return 1;
      
      int count=0;
     
     for(int i=0;i<root->children.size();i++)
        {
           count+=getLeafNodeCount(root->children[i]); 
        }
        return count;
}
int getHeight(TreeNode<int>* root)
{
    if(root==NULL)
       return 0;
    int maxHeight=0;
    for(int i=0;i<root->children.size();i++)
     {
         int childH=getHeight(root->children[i]);
         if(childH > maxHeight)
          maxHeight=childH;
     } 
     return 1+maxHeight;
}

int main()
{
    TreeNode<int>* root=takeInputLW();
    
    printTree(root);
   int n= countNodes(root);
   int sum=sumOfNodes(root);
   int max=maxDataNode(root);
   int h=getHeight(root);
   cout<<"height is: "<<h<<endl;
//   cout<<"num of nodes: "<<n<<" sum of Nodes "<<sum<<" max"<< max<<endl;
//   printAtLevelK(root,2); //10 2 20 30 3 5 4 3 1 1 0 0 0 0 
//   int c=getLeafNodeCount(root);
//   cout<<"count: "<<c;
//   postOrder(root);
    

    return 0;
}