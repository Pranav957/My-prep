int countWaysToMakeChange(int denominations[], int numDenominations, int value,int** arr){
	//Write your code here
	if(value==0)
	    return 1;
    if(value<0)
	   return 0;
	   if(arr[value][numDenominations]!=-1)
	        return arr[value][numDenominations];
	 if(numDenominations<=0)
	    return 0;  		 
	arr[value][numDenominations]= countWaysToMakeChange(denominations,numDenominations-1,value,arr) + countWaysToMakeChange(denominations,numDenominations,value-denominations[numDenominations-1],arr);
	 return arr[value][numDenominations];
}
int countWaysToMakeChangeS(int denominations[],int numDenominations,int value)
{
	int ** arr=new int*[value+1];
	for(int i=0;i<=value;i++)
	{
		arr[i]=new int[numDenominations+1];
		for(int j=0;j<=numDenominations;j++)
		   arr[i][j]=-1;
	}
  return  countWaysToMakeChange( denominations,  numDenominations, value,arr);
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
  int **arr = new int *[value + 1];
  for (int i = 0; i <= value; i++) {
    arr[i] = new int[numDenominations ];
    for (int j = 0; j < numDenominations; j++)
      arr[i][j] = -1;
  }
  for(int j=0;j<numDenominations;j++)
      arr[0][j]=1;
for(int i=1;i<=value;i++)
{
	for(int j=0;j<numDenominations;j++)
	{
		int x=(i-denominations[j]>=0)? arr[i-denominations[j]][j]:0;
		int y=(j>=1)?arr[i][j-1]:0;
		arr[i][j]=x+y;
	}
}

return arr[value][numDenominations-1];
  
}