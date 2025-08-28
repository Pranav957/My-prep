class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;

        ListNode* temp=headA;

        while(temp!=NULL)
        {
            st.insert(temp);
            temp=temp->next;
        }

        temp=headB;
        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
              return temp;
            temp=temp->next;  
        }
        return NULL;
    }
};
***********************************************************
Better Approach-> toavoid space complexity 
  count the length of both the linked lists and find d as (n2-n1)
  now travel large list d step so that bot comes to common point
  ***************************************************************
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(!headA || !headB)return NULL;

         ListNode*temp1=headA, *temp2=headB;

         while(temp1!=temp2)// if both heads points to same list
         {
            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2) return temp1;

            if(temp1==NULL)temp1=headB;
            if(temp2==NULL)temp2=headA;
         }
         return temp1;//if both heads points to same list -only one list
    }
