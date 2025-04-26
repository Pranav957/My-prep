#include<bits/stdc++.h>
int countWaysToMakeChange(int denominations[], int numDenominations, int value,int dp[][1001]){
	//Write your code here
	 if(value==0)
		     return 1;

	if(numDenominations==0 )
	  return 0;
   
   if(dp[numDenominations][value]!=-1)
    return dp[numDenominations][value];
	  if(denominations[numDenominations-1]>value)
	     return dp[numDenominations][value]= countWaysToMakeChange(denominations,numDenominations-1,value,dp);

     int a=countWaysToMakeChange(denominations,numDenominations,value-denominations[numDenominations-1],dp);
	 int b=countWaysToMakeChange(denominations,numDenominations-1,value,dp);
	 return dp[numDenominations][value]= a+b;
}

int countWaysToMakeChangeH(int denominations[], int numDenominations, int value){
	int ** dp=new int*[numDenominations+1];
	for(int i=0;i<numDenominations+1;i++)
	  dp[i]=new int[value+1];

	 for(int i=0;i<numDenominations+1;i++)
	 {
		  dp[i][0]=1;
	 } 
	 for(int j=0;j<=value;j++)
	 {
		 dp[0][j]=0;
	 }
	 for(int i=1;i<numDenominations+1;i++)
	 {
		 for(int j=1;j<value+1;j++)
		 {
			  if(denominations[i-1]>j)
			    dp[i][j]=dp[i-1][j];
			  else
			   dp[i][j]=dp[i][j-denominations[i-1]]+dp[i-1][j];	
		 }
	 }
	 return dp[numDenominations][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
	int dp[11][1001];
	memset(dp,-1,sizeof(dp));
   return  countWaysToMakeChange(denominations,numDenominations,value,dp);
}
