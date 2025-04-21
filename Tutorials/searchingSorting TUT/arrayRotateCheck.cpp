int arrayRotateCheck(int *arr, int n)
{
    //Write your code here
    for( i=0;i<n-1;i++)
   {
       if(arr[i]>arr[i+1])
          {
              return i+1;
          }
            
   }
    return 0;
}




int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    int i;
    for( i=1;i<size;i++)
    {
        if(input[i]<input[i-1])
        {
            return i;
        }  
    } 
    
    if(i==size || size==0)
        return 0;
}
int arrayRotateCheck(int *input, int size)

   {
   int i;
    for( i=0;i<size-1;i++)
    {
        if(input[i+1]<input[i])
        {
            return i+1;
        }  
    } 
    if(i==size-1||size==0)
        return 0;
        }
