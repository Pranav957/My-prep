void arrange(int *arr, int n)
{
    //Write your code here
    int k=0;
    for(int i=1;i<=n;i+=2)
    {
        arr[k]=i;
        k++;
    }
    int m;
    if(n%2==0)
        m=n;
    else
        m=n-1;
        
    for(int i=m;i>=2;i-=2)
    {
        arr[k]=i;
        k++;
    } 
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<USING TWO POINTERS APPROACH<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void arrange(int *arr, int n)
{
    //Write your code here
    int start=0;
    int end=n-1;
    int element=1;

    while(start<end)
    {
        arr[start]=element;
        start++;
        element++;
        arr[end]=element;
        end--;
        element++;
    }
    if(n%2!=0)
    arr[start]=element;

}
