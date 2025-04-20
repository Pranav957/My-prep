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
