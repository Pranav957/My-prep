
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
	if(head==NULL)
	  return head;

	  if(pos==0)
	  {
		  Node * nextNode=head->next;
		  delete head;
		  return nextNode;
	  }

	  head->next=deleteNodeRec(head->next, pos-1);
	  return head;
}
