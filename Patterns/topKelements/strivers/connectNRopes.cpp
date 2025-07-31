int minCost(int arr[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)
	 pq.push(arr[i]);

	int cost=0;
	while(pq.size()>1)
	{
		int a,b;
            a=pq.top();
		   pq.pop();
		    b=pq.top();
		   pq.pop();
		cost+=(a+b);
		pq.push(a+b);

	}
	return cost; 
}
