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
    start treversing untill t1!=t2


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
   ListNode* collistion(ListNode* t1 , ListNode* t2, int d)
   {
      while(d)
      {
        t2=t2->next;
        d--;
      }

      while(t1!=t2)
      {
        t1=t1->next;
        t2=t2->next;
      }
      return t1;
   }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* t1=headA,*t2=headB;
        int a=0,b=0;
        while(t1!=NULL)
        {
          t1=t1->next;
          a++;
        }
        while(t2!=NULL)
        {
          t2=t2->next;
          b++;
        }

         t1 = headA;
        t2 = headB;

        if(a<b)
        {
            return collistion(t1,t2,b-a);
        }
        else
         return collistion(t2, t1,a-b);
    }
};
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
