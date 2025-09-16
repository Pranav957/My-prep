#include<climits>
int findSecondLargest(int arr[], int n)
{
    //Write your code here
    int largetst=INT_MIN;
    int secondLarge;
    for(int i=0;i<n;i++)
    {
       if(arr[i]>largetst)
          {
              secondLarge=largetst;
              largetst=arr[i];
          }
         else if(arr[i]>secondLarge) //and arr[i]!=largest
           secondLarge=arr[i]; 
    }
    return secondLarge;
}
