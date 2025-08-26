
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* fast=head;
       ListNode* slow=head;

       while(fast!=NULL && fast->next!=NULL)
       {
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow)
           {
             slow=head;
             while(fast!=slow)
             {
                slow=slow->next;
                fast=fast->next;
             }
             break;
           }
       }
       if(fast==NULL || fast->next==NULL) return NULL;
       return fast;
    }
};
