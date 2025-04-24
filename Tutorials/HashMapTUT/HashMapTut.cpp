/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int*a, int size)
{
    vector<int> output;
    unordered_map<int,bool> seen;
    
    for(int i=0;i<size;i++)
    {
        if(seen[a[i]]>0)
          continue;
        
        seen[a[i]]=true;
        output.push_back(a[i]);
          
    }
    return output;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int findHighFrequency(int* arr, int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    int max=INT_MIN, value=0;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]>max)
         {
             max=mp[arr[i]];
             value=arr[i];
         }
    }
    return value;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void printIntersection(int* arr1, int* arr2, int m, int n)
{
    unordered_map<int,int> mp;
    
    for(int i=0;i<m;i++)
      mp[arr1[i]]++;
      
      for(int i=0;i<n;i++)
      {
          if(mp[arr2[i]]>0)
          {
              cout<<arr2[i]<<" ";
              mp[arr2[i]]--;
          }
      }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int pairSum(int* arr, int n)
{
    unordered_map<int,int> mp;
     int sum=0;
     
    for(int i=0;i<n;i++)
    {
        int x=0-arr[i];
        
        if(mp.find(x)!=mp.end())
        {
            sum+=mp[x];
//             int count=mp[x];
//             while(count)
// 			{
// 				cout<<x<<" "<<arr[i]<<endl;
// 				count--;
// 			}
        }
        mp[arr[i]]++;
    }
    return sum;
}

int pairSum1(int* arr, int n)
{
    unordered_map<int,int> mp;
    
    int sum=0;
    for(int i=0;i<n;i++)
     mp[arr[i]]++;
     
     for(int i=0;i<n;i++)
     {
         int x=0-arr[i];
         
         if(mp.find(x)!=mp.end())
         {
             sum+= mp[x]*mp[arr[i]];
             mp[arr[i]]=0;
             mp[x]=0;
         }
     }
     return sum;
}

#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int,int> mp;
	int count=0;
	for(int i=0;i<n;i++)
	{
		int x=0-arr[i];
        count+=mp[x];
        mp[arr[i]]++;

	}
	
	return count;
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string uniqueChar(string str)
{
    string output="";
    unordered_set<char> mp;
    
    for(int i=0;i<str.length();i++)
    {
        if(mp.find(str[i])!=mp.end())
          continue;
          
          mp.insert(str[i]);
          output+=str[i];
    }
    return output;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> mp;
    vector<int> v;
    int start, end, maxlength=0;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]==false)
           continue;
        int x=arr[i];
        int length=0;
      while(mp.find(x)!=mp.end())
      {
          length+=1;
          mp[x]=false;
          end=x;
          ++x;

      }
      x=arr[i]-1;
      start=arr[i];
      while(mp.find(x)!=mp.end())
      {
          length+=1;
          mp[x]=false;
           start=x;
          --x;
      }
      if(length>maxlength)
       {
           maxlength=length;
           while(!v.empty())
           {
               v.pop_back();
           } 
           v.push_back(start);
           v.push_back(end);
       } 

    }
    return v;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{
     int arr[]={1,3,5,2,7,8,4,3,7,9,10};
      vector<int> output=removeDuplicates(arr,10);
      
      for(int i=0;i<output.size();i++)
        cout<<output[i]<<" ";
        
        cout<<endl;
        
        cout<<findHighFrequency(arr,10)<<" ";
        cout<<endl;
        int arr2[]={3,4,5,7,6,9,10,3};
        printIntersection(arr,arr2,10,8);
        
        int arr1[]={2,-2,6,2,-2,-6,5};
        cout<<"pairsum: "<<pairSum(arr1,7);
        cout<<endl;
        
        cout<< uniqueChar("aabbccd")<<" "<<endl;
   

    return 0;
}
