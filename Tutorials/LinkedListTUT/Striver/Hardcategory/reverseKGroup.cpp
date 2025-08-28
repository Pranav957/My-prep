class Solution {
public:
     ListNode* reverse(ListNode* head)
    {
      if(head==NULL || head->next==NULL)return head;
      ListNode* newHead=reverse(head->next);
      ListNode* front=head->next;
      front->next=head;
      head->next=NULL;
      return newHead;
    }
    ListNode* getKthNode(ListNode* head,int k)
    {
        int i=1;
        while(head!=NULL)
        {
            if(i==k)
             return head;
            head=head->next;
            i++;
        }
        return NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head, *nextNode=NULL,*prevNode=NULL;
       while(temp!=NULL)
       {
          ListNode* kthNode=getKthNode(temp,k);
          if(kthNode==NULL)
          {
            if(prevNode)prevNode->next=temp;
            break;
          }
          nextNode=kthNode->next;
          kthNode->next=NULL;
          ListNode* newHead=reverse(temp);

          if(temp==head)
             head=kthNode;
          else
           prevNode->next=kthNode;

           prevNode=temp;
           temp=nextNode;     
       }
       return head;
    }
};
