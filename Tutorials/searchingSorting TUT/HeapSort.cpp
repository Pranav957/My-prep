void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<n;i++)
    {
        int childIndex=i;

        while(childIndex > 0)
        {
             int parentIndex=(childIndex-1)/2;
             if(arr[parentIndex]>arr[childIndex])
             {
                 int temp=arr[parentIndex];
                 arr[parentIndex]=arr[childIndex];
                 arr[childIndex]=temp;
             }
             else
               break;
            childIndex=parentIndex; 
        }
    }
   int x=n;
  for(int i=0;i<n-1;i++)
  {
      int temp=arr[x-1];
      arr[x-1]=arr[0];
      arr[0]=temp;
          x=x-1;
      int parentIndex=0;
      int LCindex=(parentIndex*2)+1;
      int RCindex=(parentIndex*2)+2;
      int minIndex=0;
     
      while (LCindex < x) {
            int minIndex = parentIndex;
            if (arr[LCindex] < arr[minIndex])
               minIndex = LCindex;
            if (RCindex < x && arr[RCindex] < arr[minIndex])
               minIndex = RCindex;

            if (parentIndex == minIndex)
               break;
            int temp = arr[parentIndex];
            arr[parentIndex] = arr[minIndex];
            arr[minIndex] = temp;

            parentIndex = minIndex;
            LCindex = (parentIndex * 2) + 1;
            RCindex = (parentIndex * 2) + 2;
      }
  }

}
