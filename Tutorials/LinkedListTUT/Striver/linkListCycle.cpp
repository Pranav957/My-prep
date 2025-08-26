bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;

        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(mp.find(temp)!=mp.end())
              return true;

            mp[temp]=1;
            temp=temp->next;  
        }
        return false;
    }
***********************************************************************************************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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
};
