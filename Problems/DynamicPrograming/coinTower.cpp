/*int findWinners(int n, int x, int y,int arr[])
{
	// Write your code here 
	if(n==0)
	   return 0;
if(n==1 || n==x || n==y)
    return 1;
	
	int b,c;
         int a= findWinners(n - 1, x, y,arr)^1;
		 if(n>=x)
         b= findWinners(n - x, x, y,arr)^1;
		 if(n>=y)  
           c = findWinners(n - y, x, y,arr)^1;
	//	if(a+b+c>=2)
		 //   arr[n]= 1;
	 // else
	    // arr[n]= 0;
		if(a==0||b==0||c==0)
		   arr[n]=1;
		  else
		    arr[n]=0; 
	//	arr[n]=max(a,max(b,c));
		 return arr[n];		
		
}*/
int winner(int n, int x, int y,int arr[]) {
    if (n == 0) {
        // If there are no coins left, the previous player wins
        return 2; // return 2 because the previous player is player 1
    }
    if (n == 1 || n == x || n == y) {
        // If there is only one coin left or the current player can remove all the coins, the current player wins
        return 1;
    }
	if(arr[n]!=-1)
	  return arr[n];
    // Check all possible moves and choose the one that results in the other player losing
    if (winner(n-1, x, y,arr) == 2 || (n > x && winner(n-x, x, y,arr) == 2) || (n > y && winner(n-y, x, y,arr) == 2)) {
        return  arr[n]=1;
    }
    else {
        return arr[n]= 2;
    }
}



string findWinner(int n, int x, int y)
{
	int* arr=new int[n+1];
	for(int i=0;i<=n;i++)
	  arr[i]=-1;
//	int ans=winner(n,x,y,arr);
	if (winner(n, x, y,arr) == 1) {
       return "Beerus";  
    }
    else {
        return "Whis";   
    }    
}