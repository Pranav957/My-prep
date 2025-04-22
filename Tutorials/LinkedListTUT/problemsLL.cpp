
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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EliminateDuplicates<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Node *removeDuplicates(Node *head)
{
   if(head==NULL)
	   return head;
	Node* temp=head;
	while(head->next!=NULL)
	{
		if(head->data==head->next->data)
		{
			Node * deleteNode=head->next;
			head->next=head->next->next;
			delete deleteNode;
		}
		else{
			head=head->next;
		}
	}
	return temp;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PrintReversedLL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void printReverse(Node *head)
{
    //Write your code here
	if(head==NULL)
	  return;
	 printReverse(head->next);
	 cout<<head->data<<" "; 
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CheckIfPalindrome<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool isPalindrome(Node *head,int a[],int i) 
{
	static int j=0;
    if(head==NULL)
	     return true;
	a[i]=head->data;
	bool k=isPalindrome(head->next,a,++i);
	if(k==false)
	   return k;
	else if(head->data==a[j])
	       {
          j++;
          return true; 
      }
	else 
	   return false;		   


}
bool isPalindrome(Node *head) {
  // Write your code here
  int *a=new int[100000];
  return isPalindrome(head,a,0);
}
