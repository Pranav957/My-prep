//Select a pivot element and make it go its right position , find count of lements smaller than pivot and put pivot at si+count;
//do the partition to put all the elements smaller than pivot at its left and greater at right, now array will be devided in two parts
void swap(int input[],int x,int y)
{
	int temp=input[x];
	input[x]=input[y];
	input[y]=temp;
}

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int count=0;
	for(int i=start+1;i<=end;i++)
	{
		if(input[i]<input[start])
		 count++;
	}
    int x=start+count;
	swap(input,start,start+count);
	int i=start,j=end;

	while(i<x && j>x)
	{
		while(input[i]<input[x])
		 i++;

		 while(input[j]>input[x])
		   j--;

		   swap(input,i,j);

	}
	return x;
}

void quickSort(int input[], int start, int end) {
	if(start>=end)
	  return;

	  int k=partitionArray(input,start,end);
	  quickSort(input,start,k-1);
	  quickSort(input,k+1,end);
}
