int countPairs(vector<pair<int,int>> a){
    int count=0;
    for(auto i=a.begin();i!=a.end();i++)
    {
        if((*i).first>(*i).second)
            count++;
    }
    return count;
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	#include <bits/stdc++.h> 
vector<vector<int>> transpose(int m, int n, vector<vector<int>> &mat){
    // Write your code here.
    vector<vector<int>> tm(n,vector<int>(m));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           tm[j][i]= mat[i][j];
        }
    }
    return tm;
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int> v;
	v.push_back(arr[k-1]);
	v.push_back(arr[n-k]);
	return v;
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void reverseArray(vector<int> &arr , int m) {
    // Write your code here
      	reverse(arr.begin()+m+1,arr.end());
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int sumOfMaxMin(vector<int> arr, int n){
	//  auto a=max_element(arr.begin(),arr.end());
    //  auto b=min_element(arr.begin(),arr.end());
    //  return *a+*b;
    int max_element=INT_MIN;
    int min_element=INT_MAX;

    for(int i=0;i<n;i++)
    {
        max_element=max(arr[i],max_element);
        min_element=min(arr[i],min_element);
    }
    return max_element+min_element;

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
//Assume 'arr[-1]' and 'arr[n]' as negative infinity.
  
  int findPeakElement(vector<int> &arr) {
    // Write your code here
       int n=arr.size();
        if(arr[0]>arr[1])
        {
               return 0;
          }
         if(arr[n-1]>arr[n-2])
         {
             
               return n-1;  
         }
          
    for(int i=1;i<arr.size()-1;i++)
    {

        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
              return i;
        }
          
    }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <bits/stdc++.h> 
vector < int > sqsorted(vector < int > & arr) {
    // Write your code here.
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=arr[i]*arr[i];
    }
     sort(arr.begin(),arr.end());
    return arr;

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //TOTAL SUM OF BOUNDRIES AND DIAGONALS
int totalSum(vector<vector<int>> input, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=input[0][i];
       sum+=input[n-1][i];
    }
    for(int i=1;i<n-1;i++)
    {
      sum+=input[i][0];
      sum+=input[i][n-1];
    }

    for(int i=1;i<n-1;i++)
    {
        sum+=input[i][i];
        sum+=input[i][n-1-i];
    }
    if(n%2!=0)
      sum-=input[n/2][n/2];
    return sum;  
}
