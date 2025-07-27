// User function template for C++

class Solution {
  public:
   int find(int num, int arr[],int i,int j)
   {
       if(i>j)
        return -1;
     
     int mid=(i+j)/2;
     if(arr[mid]==num)
      return mid;
     
     if(num<arr[mid])
       return find(num,arr,i,mid-1);
     else
       return find(num,arr,mid+1,j);
      
   }
    string isKSortedArray(int arr[], int n, int k) {
      int sortedArr[n];
      for(int i=0;i<n;i++)
       sortedArr[i]=arr[i];
       
       sort(sortedArr,sortedArr+n);
       
       for(int i=0;i<n;i++)
       {
           int j=find(arr[i],sortedArr,0,n-1);
           if(abs(i-j)>k)
            return "No";
       }
       return "Yes";
    }
};
