class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        vector<int> v;
        ListNode* temp=head;

        while(temp!=NULL && temp->next!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)v.push_back(temp->val);

        temp=head->next;
        while(temp!=NULL && temp->next!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next->next;
        }
         if(temp)v.push_back(temp->val);

        int i=0;temp=head;
        while(temp!=NULL)
        {
            temp->val=v[i];
            i++;
            temp=temp->next;
        }

        return head;
        
    }
};
*************************************************************************************

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
    ListNode* odd=head;ListNode* even=head->next;
    ListNode* evenH=head->next;

    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenH;
    return head;
        
    }
};
