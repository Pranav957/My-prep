void sort(int arr[],n) // only for continues elements , which begin with 1(natural numbers)
{
    int i=0;
    while(i!=n)
    {
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct])
        {
            swap(arr,i,correct)
        }
        else
         i++
    }
}
