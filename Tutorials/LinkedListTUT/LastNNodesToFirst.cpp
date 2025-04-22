Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
	if(head==NULL || n==0)
	  return head;
	Node * slow=head;
	Node* fast= head;
	Node* PrevHead=head;
	for(int i=0;i<n;i++)
	{
		fast=fast->next;
	}
	while(fast->next!=NULL)
	 {
		  fast=fast->next;
		  slow=slow->next;
	 }
	 PrevHead=slow->next;
	 slow->next=NULL;
	 fast->next=head;
   return  PrevHead;
}
