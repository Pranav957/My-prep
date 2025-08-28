

class Solution {
  public:
    Node* reverse(Node* head)
    {
      if(head==NULL || head->next==NULL)return head;
      Node* newHead=reverse(head->next);
      Node* front=head->next;
      front->next=head;
      head->next=NULL;
      return newHead;
    }
    Node* addOne(Node* head) {
        // Your Code here
        
         head=reverse(head);
        Node* temp=head; int carry=1;
        
        while(temp!=NULL)
        {
            temp->data=temp->data+carry;
            
            if(temp->data<10)
            {
                carry=0;
                break;
            }
            else
             {
                 temp->data=0;
                 carry=1;
             }
             temp=temp->next;
        }
        
        head=reverse(head);
        if(carry==1)
        {
            Node* newNode=new Node(1);
            newNode->next=head;
            return newNode;
        }
        return head;
    }
};
*********************************************************************
class Solution {
  public:
    int helper(Node* head)
    {
        if(head==NULL)
         return 1;
         
        int res= helper(head->next);
        
        if(res==1)
        {
            head->data=head->data+1;
            if(head->data==10)
            {
                 head->data=0;
                 return 1;
            }
        }
        return 0;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int res=helper(head);
        
        if(res==1)
         {
             Node* temp=new Node(1);
             temp->next=head;
             head=temp;
         }
         return head;
        // return head of list after adding one
    }
};
