int multiplyNumbers(int m, int n) {
    // Write your code here 
    if(n==0 || m==0)
        return 0;
 int a=m+multiplyNumbers(m,n-1);
  return a;
}
/*int multiplyNumbers(int m, int n) {
    // Write your code here
    static int sum=0;
    if(n==0)
    {
        return sum;
    }
    sum=sum+m;
    return multiplyNumbers(m,n-1);
}
*/

