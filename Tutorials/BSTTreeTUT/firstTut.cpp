/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTree{
    public:
     T data;
     BinaryTree<T>* left;
     BinaryTree<T>* right;
     
     BinaryTree(T data)
     {
         this->data=data;
         left= NULL;
         right=NULL;
     }
     ~BinaryTree()
     {
         delete left;
         delete right;
     }
    
};

void printTree(BinaryTree<int>* root)
{
    if(root==NULL)
      return;
      
      cout<<root->data<<": ";
      
      if(root->left)
      {
          cout<<root->left->data<<" ";
       
      } 
       
     if(root->right)
    {
        cout<<root->right->data<<" ";
    }  
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
      
}

int getHeight(BinaryTree<int>* root)
{
    if(root==NULL)
      return 0;
      
     int leftH= getHeight(root->left);
      int rightH=getHeight(root->right);
      return max(leftH,rightH)+1;
}

BinaryTree<int>* takeInput()
{
    int rootData;
    cout<<"enter  data ";
    cin >> rootData;
    if(rootData==-1)
      return NULL;
    
    BinaryTree<int>* root=new BinaryTree<int>(rootData);
    
    queue<BinaryTree<int>*> pendingNodes ;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty())
    {
        BinaryTree<int>* front=pendingNodes.front();
        pendingNodes.pop();
        
        int leftChildData;
        cout<<"enter left child for"<<front->data<<": ";
        cin >> leftChildData;
        
        if(leftChildData!=-1)
         {
             BinaryTree<int>* leftChild=new BinaryTree<int>(leftChildData);
             pendingNodes.push(leftChild);
             front->left=leftChild;
         } 
         
         int rightChildData;
         cout<<"enter right Child for"<<front->data<<": ";
         cin >> rightChildData;
         
         if(rightChildData!=-1)
         {
             BinaryTree<int>* rightChild=new BinaryTree<int>(rightChildData);
             pendingNodes.push(rightChild);
             front->right=rightChild;
         }
        
        
    }
    return root;
}

bool SearchInBST(BinaryTree<int>* root,int x)
{
    if(root==NULL)
      return false;
      
      if(root->data==x)
       return true;
       
       if(x<root->data)
         return SearchInBST(root->left,x);
       else
         return SearchInBST(root->right,x);
         
}

void printElementsInRange(BinaryTree<int>* root, int k1,int k2)
{
    if(root==NULL)
     return;
     
     if(root->data>=k2 || root->data > k1 && root->data < k2)
       printElementsInRange(root->left,k1,k2);
      
      if(root->data>=k1 && root->data<=k2)
       cout<<root->data<<" ";
       
      if(root->data<=k1 || root->data > k1 && root->data < k2)
        printElementsInRange(root->right,k1,k2);
}
int getMinimum(BinaryTree<int>* root)
{
   if(root==NULL)
       return INT_MAX;
     
     return min(root->data,min(getMinimum(root->left),getMinimum(root->right)))  ;
}

int getMaximum(BinaryTree<int>* root)
{
    if(root==NULL)
       return INT_MIN;
       
       return max(root->data,max(getMaximum(root->left),getMaximum(root->right)));
}
bool isBST(BinaryTree<int>* root)
{
    
       if(root==NULL)
        return true;
        
    int leftMax = getMaximum(root->left);    
    int rightMin= getMinimum(root->right) ;
    
    return (root->data>leftMax && root->data<=rightMin && isBST(root->left) && isBST(root->right));
       
      
}

class BSTReturn{
    public:
     bool isBST;
     int maximum;
     int minimum;
};

BSTReturn isBSTMethod(BinaryTree<int>* root)
{
    if(root==NULL)
    {
        BSTReturn output;
        output.isBST=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    
    BSTReturn leftOutput= isBSTMethod(root->left);
    BSTReturn rightOutput= isBSTMethod(root->right);
    
    int minimum=min({root->data, leftOutput.minimum,rightOutput.minimum});
    int maximum=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    
    bool isBST= (root->data>leftOutput.maximum && root->data<=rightOutput.minimum && leftOutput.isBST && rightOutput.isBST);
    
    BSTReturn res;
    res.isBST=isBST;
    res.minimum=minimum;
    res.maximum=maximum;
    
    return res;
}

bool isBST3(BinaryTree<int>* root, int min=INT_MIN, int max=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(root->data>max && root->data<min)
      return false;
    
    bool isLeftOk= isBST3(root->left,min,root->data);
    bool isRightOk= isBST3(root->right,root->data,max);
    
    return isLeftOk && isRightOk;
}

BinaryTree<int>* constructBST(int a[], int si,int ei)
{
    if(si>ei)
      return NULL;
      
    int mid=(si+ei)/2;
    
    BinaryTree<int>* root=new BinaryTree<int>(mid);
    
    root->left=constructBST(a,si,mid-1);
    root->right=constructBST(a,mid+1,ei);
    
    return root;
}

template<typename T>
class Node{
    public:
      T data;
      Node<T>* next;
      
      Node(T data)
      {
          this->data=data;
          next=NULL;
      }
      ~Node()
      {
          delete next;
      }
};

class pairX
{
  public:
  Node<int>* head;
  Node<int>* tail;
  
  pairX()
  {
      head=NULL;
      tail=NULL;
  }
};

pairX LinkListOfBST1(BinaryTree<int>* root)
{
    
    if(root==NULL)
    {
       pairX p;
        p.head=NULL;
        p.tail=NULL;
        return p;
    }
    
    pairX leftList=LinkListOfBST1(root->left);
    pairX rightList=LinkListOfBST1(root->right);
    
    Node<int>* node=new Node<int>(root->data);
    
    if(leftList.head==NULL)
    {
      leftList.head=node;
      leftList.tail=node;
    }
    else{
        leftList.tail->next=node;
        leftList.tail=node;
    }
    node->next=rightList.head;
    if(rightList.head)
        leftList.tail=rightList.tail;
        
   return leftList;        
       
}

pair<Node<int>*,Node<int>*> LinkListOfBST(BinaryTree<int>* root)
{
    
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*> p;
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    
    pair<Node<int>*,Node<int>*> leftList=LinkListOfBST(root->left);
    pair<Node<int>*,Node<int>*> rightList=LinkListOfBST(root->right);
    
    Node<int>* node=new Node<int>(root->data);
    
    if(leftList.first==NULL)
    {
      leftList.first=node;
      leftList.second=node;
    }
    else{
        leftList.second->next=node;
        leftList.second=node;
    }
    node->next=rightList.first;
    if(rightList.first)
        leftList.second=rightList.second;
        
   return leftList;        
       
}

vector<int>* getPathtoNode(BinaryTree<int>* root, int data)
{
    if(root==NULL)
       return NULL;
       
     if(root->data==data)
     {
         vector<int>* v=new vector<int>();
         v->push_back(root->data);
         return v;
     }
     
     vector<int>* leftOutput=getPathtoNode(root->left,data);
     if(leftOutput!=NULL)
     {
         leftOutput->push_back(root->data);
         return leftOutput;
     }
     vector<int>* rightOutput=getPathtoNode(root->right,data);
     if(rightOutput!=NULL)
     {
         rightOutput->push_back(root->data);
         return rightOutput;
     }
     return NULL;
}

int main()
{
    BinaryTree<int>* root=takeInput(); // 20 10 40 5 15 30 50 -1 7 12 18 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // printTree(root);
    // cout<<getHeight(root)<<" ";
    
    // cout<<"search: "<<SearchInBST(root,10);
    // cout<<endl;
    
    // printElementsInRange(root,2,8);
    // 
    // cout<<endl;
    
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    
    BinaryTree<int>* node=constructBST(arr,0,9);
    printTree(node);
    vector<int>* v=getPathtoNode(root,15);
    for(int i=0;i<v->size();i++)
        cout<<v->at(i)<<" ";
    
    // pair<Node<int>*,Node<int>*> p=LinkListOfBST(root);
    //  pairX p=LinkListOfBST1(root);
    // Node<int>* temp=p.head;
    // while(temp!=NULL)
    // {
    // cout<<temp->data<<" ";
    // temp=temp->next;
    // }
    
//   if(isBST3(root))
//      cout<<"true"<<" ";
//   else
//      cout<<"false"<<endl;
    return 0;
}
