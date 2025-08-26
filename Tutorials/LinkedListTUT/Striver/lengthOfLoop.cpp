class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // Code here
        unordered_map<Node*, int> mp; Node* temp; int timer=1;
        temp=head;
        while(temp!=NULL)
        {
            if(mp.find(temp)!=mp.end())
            {
                return timer-mp[temp];
            }
            mp[temp]=timer;
             timer++;
           temp=temp->next;     
        }
        return 0;
    }
};
******************************************************************************
class Solution {
  public:
    int findLength(Node* fast, Node* slow)
    {
        fast=fast->next;
        int cnt=1;
        
        while(slow!=fast)
        {
            fast=fast->next;
            cnt++;
        }
        return cnt;
    }
    int lengthOfLoop(Node *head) {
        // Code here
        Node* fast=head;
       Node* slow=head;

       while(fast!=NULL && fast->next!=NULL)
       {
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow)
           return findLength(slow,fast);
       }
       return 0;
    }
};
