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
