
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(n)
        {
            fast=fast->next;
            n--;
        }

        if(fast==NULL)
         {
            ListNode* temp=head->next;
            delete head;
            return  temp;
         }

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete temp;
        return head;

    }
};
