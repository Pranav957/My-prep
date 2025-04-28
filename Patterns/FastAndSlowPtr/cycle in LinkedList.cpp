 bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mp;

        while(head!=NULL)
        {
            if(mp.find(head)!=NULL)
              return true;

             mp.insert(head);
             head=head->next; 
        }
        return false;
    }
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 bool hasCycle(ListNode *head) {
       ListNode* fast=head;
       ListNode* slow=head;

       while(fast!=NULL && fast->next!=NULL)
       {
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow)
           return true;
       }
       return false;
    }
