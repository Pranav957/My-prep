int binarySearch(int * input, int element,int i,int j)
{
    while(i<=j)
    {
      int mid=(i+j)/2;
        if(element==input[mid])
         return mid;
         if(element<input[mid])
          {
            j=mid-1;
          }  
          else
           i=mid+1;
    }
    return -1;
}

int binarySearch(int * input, int element,int i,int j)
{
    if(i>j)
      return -1;

      int mid=(i+j)/2;

      if(element==input[mid])
       return mid;

       if(element<input[mid])
         return binarySearch(input,element,i,mid-1);
        else
        return  binarySearch(input,element,mid+1,j); 
}
int binarySearch(int input[], int size, int element) {
    return binarySearch(input,element,0,size-1);
}
