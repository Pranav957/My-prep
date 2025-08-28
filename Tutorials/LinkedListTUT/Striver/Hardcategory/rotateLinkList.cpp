  ListNode* getNewLast(ListNode* temp,int k)
  {
    int cnt=1;
    while(temp!=NULL)
     {
        if(cnt==k) return temp;
        temp=temp->next;
        cnt++;
     }
     return temp;
  }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL) return head;
        ListNode* tail=head;
        int cnt=1;
        while(tail->next!=NULL)
        {
            cnt++;
            tail=tail->next;
        }

       if(k%cnt==0) return head;

        k=k%cnt;

        tail->next=head;

        ListNode* newLast=getNewLast(head,cnt-k);
         head=newLast->next;
        newLast->next=NULL;

        return head;
    }
