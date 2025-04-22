<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SWAP ALTERNATE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void swapAlternate (int *arr, int size)
{
  //Write your code here
  int i = 0, j = 1;
  while (j<size)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i = i + 2;
      j = j + 2;
      
    }
  
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<UNIQUE IN ARRAY<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int findUnique(int *arr, int size)
{
    //Write your code here
     for(int i=0;i<size;i++)
     {
         bool a=false;
         for(int j=0;j<size;j++)
         {
             if(i==j)
                 continue;
             else if(arr[i]==arr[j])
                  a=true;
         } 
         if(a==false)
             return arr[i];
     } 
} 
#include<bits/stdc++.h>
int findUnique(int *arr, int n) {  //nlogn
    // Write your code here
    sort(arr,arr+n);
    for(int i=0;i<n;i+=2)
    {
        if(arr[i]!=arr[i+1])
          return arr[i];
    }
}
int findUnique(int *arr, int n) {// O(N)
    // Write your code here
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
    }
  return ans;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DUPLICATES INARRAY<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int duplicateNumber(int *arr, int size)
{
    //Write your code here
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
                continue;
            if(arr[i]==arr[j])
                 return arr[i];
        }   
    }   
}

int findDuplicate(int *arr, int n)
{
    int sum=0;
    //Write your code here
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
    }
    int x=(n-2)*(n-1)/2;
    return sum-x;
}

// int findDuplicate(int *arr, int n)
// {
//     //Write your code here
//     sort(arr,arr+n);
//     for(int i=0;i<n-1;i++)
//     {
//         if(arr[i]==arr[i+1])
//            return arr[i];
//     }
// }

// int findDuplicate(int *arr, int n)
// {
//     //Write your code here
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]==arr[j])
//                return arr[i];
//         }
//     }
// }
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ARRAY INTERSECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(input1[i]==input2[j])
            {
                cout<<input1[i]<<" ";
                input2[j]=0;
                break;
            }    
        }   
    }   
}
//sort small array and for each element in first array perform binary search on second
void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
  int i=0,j=0;
  while(i<n && j<m)
  {
      if(arr1[i]==arr2[j])
      {
          cout<<arr1[i]<<" ";
          i++;
          j++;
          
      }
     else  if(arr1[i]<arr2[j])
         {
             i++;
         }
         else{
             j++;
         }
  }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PAIR SUM<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int pairSum(int *input, int size, int x)
{
	//Write your code here
    int count=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            
            if(input[i]+input[j]==x)
            {
               // cout<<input[i]<<"  "<<input[j]<<endl;
                count++;
            }    
        }  
    }
    return count;
}

int pairSum(int *arr, int n, int num)  //two pointers
{
	//Write your code here
	sort(arr,arr+n);
	int count=0;
	int startIndex=0;
	int endIndex=n-1;
	while(startIndex<endIndex)
	{
		if(arr[startIndex]+arr[endIndex]>num)
		  endIndex--;
		 else if(arr[startIndex]+arr[endIndex]<num)
		    startIndex++;
	    else{
            if(arr[startIndex]==arr[endIndex])
			{
                   int numCount=(endIndex-startIndex)+1;
				   count+=(numCount*(numCount-1)/2);
				    return count;
			}
			else{
				int tempstart=startIndex+1;
				int tempend=endIndex-1;
				while(tempstart<=tempend && arr[tempstart]==arr[startIndex])
				    tempstart++;
				 while(tempend>=tempstart && arr[tempend]==arr[endIndex])
				    tempend--;

			    int leftcount=tempstart-startIndex;
				int rightcount=endIndex- tempend;
				count+=leftcount*rightcount;
				startIndex=tempstart;
				endIndex=tempend;			
				    
			}
		}		 
	}
	return count;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<TRIPLET SUM<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int tripletSum(int *input, int size, int x)
{
	//Write your code here
    int count=0;
    for(int i=0;i<size;i++)    //<=size-3
    {
        for(int j=i+1;j<size;j++)   //<=size-2
        {
            for(int k=j+1;k<size;k++)   //<=size-1
            {
                if(input[i]+input[j]+input[k]==x)
               {
               // cout<<input[i]<<"  "<<input[j]<<endl;
                count++;
              } 
          }
        }  
    }
    return count;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SORT ALL ZEROS AND ONCE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void sortZeroesAndOne(int input[], int size)
{
    //Write your code here
    int placeZeoroHere=0;
    for(int i=0;i<size;i++)
    {
        if(input[i]==0)
        {
            int temp=input[i];
            input[i]=input[placeZeoroHere];
            input[placeZeoroHere]=temp;
            placeZeoroHere++;
        }
    }
}  Approach2: keep count of zeros and then fill those many zeros and rest 1
  void sortZeroesAndOne(int *input, int size)
{
    //Write your code here
    int i=0,k=0;
    while(i<size)
    {
        if(input[i]==0 && k<i)
        {
            int temp=input[i];
            input[i]=input[k];
            input[k]=temp;
            i++;
            k++;
        }
        else if(input[i]!=0)
            i++;
        else
        {
            i++;
            k++;
        }
    }
}
