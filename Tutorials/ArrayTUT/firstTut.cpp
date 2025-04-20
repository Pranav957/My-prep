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
