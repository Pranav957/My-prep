void sort012(int *arr, int n)  //sort 0 an2 only in O(n)
{
    //Write your code here
    int nz=0,nt=n-1, i=0;
    while(i<=nt)
    {
      if(arr[i]==0)
      {
          int temp=arr[i];
          arr[i]=arr[nz];
          arr[nz]=temp;
          i++;
          nz++;
      } 
      else if(arr[i]==2)
      {
          int temp=arr[i];
          arr[i]=arr[nt];
          arr[nt]=temp;
          nt--;
      }
        else
            i++;
     
    }
}
