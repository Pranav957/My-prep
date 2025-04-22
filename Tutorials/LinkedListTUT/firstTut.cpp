/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void printList(Node* head)
{
    if(head==NULL)
      return;
      
    cout<<head->data<<" ";     
      printList(head->next);
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int lengthOfLL(Node* head)
{
    if(head==NULL)
      return 0;
      
     return 1+lengthOfLL(head->next); 
}

Node* insertAtI(Node* head,int i, int data)
{
    Node* temp=head;
    Node* newNode=new Node(data);
    int count=1;
    
    if(i==0)
    {
      newNode->next=temp;
      return newNode;
    }
    
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

Node* deleteAtI(Node* head, int i)
{
    if(head==NULL)
      return NULL;
    Node* temp=head;
    int count=1;
    
    if(i==0)
    {
        head=head->next;
        delete temp;
        return head;
    }
    
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL && temp->next!=NULL)
    {
        Node* x=temp->next;
        temp->next=temp->next->next;
        delete x;
    }
    return head;
}

Node* midOfLinkList(Node* head)
{
    if(head==NULL)
     return NULL;
    Node* fast=head->next;
    Node* slow=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverseLL(Node* head)
{
    Node* prev=NULL;
    while(head!=NULL)
    {
        Node* next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

node* reverseRec(Node* head, Node* prev=NULL)
{
    if(head->next==NULL)
    {
        head->next=prev;
        return head;
    }
    Node * temp=reverseRec(head->next,head);
    head->next=prev;
    return temp;
}



Node* mergeTwoSortedLL(Node* list1, Node* list2)  
{
    if(list1==NULL)
      return list2;
   if(list2==NULL) 
      return list1;
      
      Node* fhead=NULL;
      Node* fTail=NULL;
      
      while(list1!=NULL && list2!=NULL)
      {
          if(list1->data<list2->data)
          {
              if(fhead==NULL)
              {
                  fhead=list1;
                  fTail=list1;
              }
              else
              {
                  fTail->next=list1;
                  fTail=fTail->next;
              }
              list1=list1->next;
          }
          else
          {
              if(fhead==NULL)
              {
                  fhead=list2;
                  fTail=list2;
              }
              else
              {
                  fTail->next=list2;
                  fTail=fTail->next;
              }
              list2=list2->next;
          }
      }
      if(list1!=NULL)
       fTail->next=list1;
      else if(list2!=NULL)
        fTail->next=list2;
  return fhead;        
      
}
Node* mergeSort(Node* head)
{
    if(head==NULL)
      return head;
      
      if(head->next==NULL)
       return head;
       
     Node* mid= midOfLinkList(head);
     Node* temp=mid->next;
     mid->next=NULL;
     Node * list1=mergeSort(head);
     Node* list2=mergeSort(temp);
     Node* list3=mergeTwoSortedLL(list1,list2);
     return list3;
}

Node* takeInput()
{
    int data;
    cin >> data;
    
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1)
    {
        Node* newNode=new Node(data);
        if(head==NULL)
         {
             head=newNode;
             tail=newNode;
         }
        else{
        //      Node* temp=head;
        //  while(temp->next!=NULL)
        //     temp=temp->next;
        
        tail->next=newNode; 
        tail=newNode;
        }       
        cin >>data;
    }
    return head;
}
Node* insertNode(Node* head, int i,int data)
{
    if(head==NULL)
      return head;
      
      if(i==0)
      {
          Node* newNode=new Node(data);
          newNode->next=head;
          head=newNode;
          return head;
      }
      head->next=insertNode(head->next,i-1,data);
      return head;
}

Node* deleteNode(Node* head, int pos)
{
    if(head==NULL)
      return head;
      
      if(pos==0)
      {
          Node* temp=head;
          head=head->next;
          delete temp;
          return head;
      }
      head->next=deleteNode(head->next,i-1,data);
      return head;
}


int main()
{
    Node* head=takeInput();
    // Node* temp=mergeSort(head);
    // printList(temp);
    // cout<<endl;
    Node* temp=reverseLL(head);
    printList(temp);
    
    
    
    

    return 0;
}
