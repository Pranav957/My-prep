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
