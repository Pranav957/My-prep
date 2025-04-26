double geometricSum(int k) {
    // Write your code here
    static double sum=0,i=1;
   if(k<0)
       return sum;
    sum=sum+(1/i);
    i=i*2;
    return geometricSum(k-1);
}

using namespace std;
double geometricSum(int k) {
    // Write your code here
    if(k==0)
       return 1;
       int ans=1;
       for(int i=0;i<k;i++)
           ans=ans*2;
      return  1.0/ans+geometricSum(k-1);

}



