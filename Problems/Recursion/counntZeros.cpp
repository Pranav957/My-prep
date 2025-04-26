
int countZeros(int n) {
    // Write your code here
    static int s=n;
    if(n==0)
        return 0;
       int ans=countZeros(n/10);
    if(n%10==0)
        ans+=1;
    return ans;
    

}
/*int countZeros(int n) {
    // Write your code here
    static int s=n;
    if(n==0)
        return 1;
       int ans=countZeros(n/10);
    if(n%10==0)
        ans+=1;
    if(n==s)
        ans-=1;
    return ans;
    

}

int countZeros(int n) {
    // Write your code here
    static int count=0;
    if(n==0)
        return count;
    if(n%10==0)
        count++;
    return countZeros(n/10);

}
*/

