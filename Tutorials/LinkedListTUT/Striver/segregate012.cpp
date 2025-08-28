bruteForce :-> count number of 1s 2s 0s and then replace values , two passes will  be required
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head || head->next==NULL) return head;
        
        Node* zeroH=new Node(-1);
        Node* oneH=new Node(-1);
        Node* twoH=new Node(-1);
        
        Node* zero=zeroH, * one=oneH,*two=twoH;
        
        Node* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1)
            {
                one->next=temp;
                one=one->next;
            }
            else
             {
                 two->next=temp;
                 two=two->next;
             }
           temp=temp->next;  
        }
        zero->next= oneH->next? oneH->next:twoH->next;
        one->next=twoH->next;
        two->next=NULL;
        
        Node* newHead=zeroH->next;
        
        delete zeroH;
        delete oneH;
        delete twoH;
        
        return newHead;
    }
};
