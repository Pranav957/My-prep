
void printIthNode(Node *head, int i)
{
    //Write your code here
	Node* temp=head;
	int count=0;
	while(count!=i && temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	  cout<<temp->data;
}


int findNode(Node *head, int n){
    // Write your code here.
    int i=0;
   while(head!=NULL)
   {
      if(head->data==n)
        return i;

        head=head->next;
        i++;
   }
   return -1;
}
