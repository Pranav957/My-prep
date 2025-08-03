class Solution {
public:
  double myPow(double x,long long nn)
  {
     if(nn==0)
      return 1;

     if(nn%2==0)
      return myPow(x*x,nn/2);
     else
      return x*myPow(x,nn-1);  


  }
    double myPow(double x, int n) {
        double ans;
        long long nn= n;
        if(nn<0) nn=nn*(-1);
        ans= myPow(x,nn);
       if(n<0)
        return 1/ans;
        return ans;
    }
};
****************************************************************************
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn= n;
        if(nn<0) nn=nn*(-1);

        while(nn>0)
        {
            if(nn%2==1)
            {
                ans=ans*x;
                nn=nn-1;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) 
         return 1/ans;
         return ans;

    }
};
