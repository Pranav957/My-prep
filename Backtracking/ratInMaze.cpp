/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
int arr[19][19];
int output[19][19];
void Rat_in_maze(int N,int r, int c)
{
	
	if(r==N-1 && c==N-1)
	{
		output[r][c]=1;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			  cout<<output[i][j]<<" ";
		}
		output[r][c]=0;
		cout<<endl;
		return;
	}
	if(output[r][c]==1)
	  return;
	 else if(arr[r][c]==0)
	    return;
     if(output[r][c]==0)
	   output[r][c]=1;		
	   
	if(r-1>=0)
	 	 Rat_in_maze(N,r-1,c);
	if(r+1<N)
	    Rat_in_maze(N,r+1,c);
	if(c-1>=0)
	    Rat_in_maze(N,r,c-1);
    if(c+1<N)
	   Rat_in_maze(N,r,c+1);	
	   output[r][c]=0;			  
	  
}
int main() {

	// Write your code here
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		  cin >> arr[i][j];
	}
	//memset(output,0,19*19*size_of(int));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		  output[i][j]=0;
	}
	Rat_in_maze(N,0,0);
   
	return 0;
}
