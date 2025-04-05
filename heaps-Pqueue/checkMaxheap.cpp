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