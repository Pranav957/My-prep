int findNodeRec(Node *head, int n,int i=0)
{
	//Write your code here
	if(head==NULL)
	   return -1;
	if(head->data==n)
	    return i;

		findNodeRec(head->next,  n,++i);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Even After ODD<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  /****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL)
	   return head;
	Node* oddH=NULL, *evenH=NULL, *oddT=NULL, *evenT=NULL;
	while(head!=NULL)
	{
		if(head->data%2==0)
		{
           if(evenH==NULL)
		   {
			   evenH=head;
			   evenT=head;
		   }
		  else {
			   evenT->next=head;
		   evenT=evenT->next;
		  }
		}
		else{
			 if(oddH==NULL)
			 {
				 oddH=head;
				 oddT=head;
                 } else {
                                 oddT->next = head;
                                 oddT = oddT->next;
                         }
                }
        head=head->next;
	}
	if(evenT!=NULL)
	  evenT->next=NULL;
	  if(oddH==NULL)
	     return evenH;
		 	
	oddT->next=evenH;
	return oddH;

}
	
	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,DeleteEveryKNodes<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(M==0)
	  return NULL;
	 if(N==0) 
	   return head;

	 Node* temp=head;
	 Node* prev=NULL;

	 while(temp!=NULL)
	 {
		 int x=M,y=N;
		 while(x-- && temp!=NULL)
		   {
			   prev=temp;
			   temp=temp->next;
		   }

		   while(y-- && temp!=NULL)
		   {
			   Node* del=temp;
			   temp=temp->next;
			   delete del;
		   }
		   if(prev!=NULL)
		     prev->next=temp;
	 } 
	 return head;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<swap two nodes ofLL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  /****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
	if(i==j)
	   return head;
	Node* prev1=NULL;
    Node* temp1=head;
	while(i-- && temp1!=NULL)
	{
		prev1=temp1;
		temp1=temp1->next;
	}
	Node* prev2=NULL;
	Node* temp2=head;
	while(j-- && temp2!=NULL)
	{
		prev2=temp2;
		temp2=temp2->next;
	}
	//cout<<"temp1: "<<temp1->data<<" "<<"temp2->data:"<<temp2->data<<endl;
	
       if(temp1->next==temp2)
       {
        temp1->next=temp2->next;
        temp2->next=temp1;
           if(prev1!=NULL)
	     prev1->next=temp2;
	      else 
		  head=temp2;
       }
       else{
        Node* x=temp1->next;
        temp1->next=temp2->next;
        temp2->next=x;
        if(prev1!=NULL)
	   prev1->next=temp2;
	   else 
	    head=temp2;
	if(prev2!=NULL)
	   prev2->next=temp1;  
	 else
	   head=temp1;  
       }
	
   return head;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<KReverse<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  Node* reverse(Node* head, Node* prev,int i,int k)
{
	if(i==k)
	{
		head->next=prev;
		return head;
	}

	Node* x=reverse(head->next, head,  ++i, k);
	head->next=prev;
	return x;
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
	if(k==0)
	  return head;

	  Node* fHead=NULL;
	    Node* temp=head;
	  fHead=reverse(head, NULL, 1,  k);
	  while(head!=NULL)
	  { 
		
		    int i=1;
          while(i<k)
		  {
			  head=head->next;
			  i++;
		  }
		   Node*y=reverse(head, NULL, 1,  k);
		   temp->next=y;
		   temp=y;
	  }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<BUBUBBLE SORT<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  nt length(Node*head)
{
	int count=0;
	while(head!=NULL)
	{
     head=head->next;
	 count++;
	}
	return count;
}
Node *bubbleSort(Node *head)
{
	// Write your code here
	if(head==NULL)
	   return head;
	int x=length(head);
	//int i=0;
	Node* newhead=head,*temp=NULL;
	Node* prev=NULL;
	while(x>1)
	{
		
		int i=0;
       while(head->next!=NULL && i!=x-1)
	   {
		   bool ischange=false;
		  temp=head->next;
		   if(head->data>temp->data)
		   {
			   head->next=temp->next;
			   temp->next=head;
			   if(prev!=NULL)
			       prev->next=temp;
				else
				   newhead=temp;
			 ischange=true;   
		   }
		   if(ischange)
		      prev=temp;
		 else	  
		  {
			   prev=head;
		   head=head->next;
		  }
		    i++;
	   }
	   prev=NULL;
	   head=newhead;
	  x=x-1;
	}
	return newhead;
}
