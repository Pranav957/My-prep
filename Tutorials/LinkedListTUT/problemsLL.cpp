
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
