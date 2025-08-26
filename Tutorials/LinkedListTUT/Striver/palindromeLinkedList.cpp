/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      stack<int> st;
      ListNode* temp=head;
      while(temp!=NULL)
      {
        st.push(temp->val);
        temp=temp->next;
      }
      temp=head;
      while(temp!=NULL)
      {
        if(temp->val!=st.top())
         return false;
         st.pop();
         temp=temp->next;
      }
      return true;
    }
};
*****************************************************************************************************************************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head)
    {
      if(head==NULL || head->next==NULL)return head;
      ListNode* newHead=reverse(head->next);
      ListNode* front=head->next;
      front->next=head;
      head->next=NULL;
      return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
      if(head==NULL || head->next==NULL) return true;
      ListNode* fast=head; ListNode* slow=head;

      while(fast->next!=NULL && fast->next->next!=NULL)
      {
         fast=fast->next->next;
         slow=slow->next;
      }
      ListNode* newHead=reverse(slow->next);

      ListNode* first=head,*second=newHead;

      while(second!=NULL)
      {
         if(first->val!=second->val)
         {
            reverse(newHead);
            return false;
         }
         second=second->next;
         first=first->next;
      }

      reverse(newHead);
      return true;
    }
};
