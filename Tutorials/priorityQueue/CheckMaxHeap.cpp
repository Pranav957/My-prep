bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0; 2*i+1<n;i++)
    {
        int leftChildIndex=2*i+1;
        int rightChildIndex=leftChildIndex+1;

        if(arr[i]<arr[leftChildIndex])
         return false;

         if(arr[i]<arr[rightChildIndex])
           return false;
    }
    return true;
}


bool isMaxHeap(int arr[], int n,int i=0) {
    // Write your code here
    if(i==n)
      return true;
      int lchild=2*i+1;
      int rchild=2*i+2;
      if(lchild<n && arr[i]<arr[lchild])
        return false;
      if(rchild<n && arr[i]<arr[rchild])
        return false;  
        return isMaxHeap(arr,n,++i) ; 
}

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0;i<n;i++)
    {
      // if(2*i >=n)
      //   break;
        int parentIndex=i;
    int leftChildIndex=(2*parentIndex)+1;
    int rightChildIndex=(2*parentIndex)+2;

        if(leftChildIndex < n && arr[parentIndex]<arr[leftChildIndex])
          return false;
        else if(rightChildIndex<n && arr[parentIndex]<arr[rightChildIndex])  
           return false;
    }
   return true;
}
