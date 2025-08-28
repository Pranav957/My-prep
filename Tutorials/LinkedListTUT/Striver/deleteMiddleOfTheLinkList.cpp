class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return head->next;
        
      ListNode* fast=head;
      ListNode* slow=head;

      while(fast->next->next!=NULL && fast->next->next->next!=NULL) 
      {
        fast=fast->next->next;
        slow=slow->next;
      } 

      ListNode* temp=slow->next;
      slow->next=temp->next;
      delete temp;
      return head;
    }
};
********************************************
 ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return head->next;
        
      ListNode* fast=head;
      ListNode* tempNode=new ListNode(0,head);
      ListNode* slow=tempNode;

      while(fast!=NULL && fast->next!=NULL) 
      {
        fast=fast->next->next;
        slow=slow->next;
      } 

      ListNode* temp=slow->next;
      slow->next=temp->next;
      delete temp;
      delete tempNode;
      return head;
    }
