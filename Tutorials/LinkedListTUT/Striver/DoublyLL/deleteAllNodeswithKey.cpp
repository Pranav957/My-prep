class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp=*head_ref;
        
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                if(temp==*head_ref)
                {
                    *head_ref=temp->next;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                
                if(nextNode)nextNode->prev=prevNode;
                if(prevNode)prevNode->next=nextNode;
                delete temp;
                temp=nextNode;
            }
            else
             temp=temp->next;
        }
    }
};
***************************************************8
  class Solution {
  public:
    void deleteAllOccurOfX( Node* head, int x) {
        // Write your code here
        Node* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                if(temp==head)
                {
                    head=head->next;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                
                if(nextNode)nextNode->prev=prevNode;
                if(prevNode)prevNode->next=nextNode;
                delete temp;
                temp=nextNode;
            }
            else
             temp=temp->next;
        }
  return head;
    }
};
