void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here
    stack<int> s;

    spans[0]=1;
    s.push(0);
    for(int i=1;i<n;i++)
    {

        while(!s.empty() && prices[s.top()]<prices[i])
           s.pop();
       
           if(s.empty())
            spans[i]=i+1;
           else
             spans[i]=i-s.top();

        s.push(i);

    }

}
// #include<stack>
// int* calculateSpan(int *price, int size,int op[])  {
// 	// Write your code here
// 	stack<int> st;
// 	// int *op=new int[size];
// 	op[0]=1;
// 	st.push(0);
// 	for(int i=1;i<size;i++)
// 	{
//        op[i]=1;
// 	   while(!st.empty())
// 	   {
// 		   int x=st.top();
// 		   if(price[x]<price[i])
// 		   {
// 			   op[i]=op[i]+op[x];
// 			   st.pop();
// 		   }
// 		else
// 		    {
// 				break;
// 			}  
// 	   }
// 	   st.push(i);
// 	}
// 	return op;
// }
