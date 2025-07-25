class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n=cardPoints.size();
       int i=0;int j=n-1,sum=0,mx=0 ;
     
       for(int i=0;i<=k-1;i++)
       {
         sum+=cardPoints[i];
       }
       mx=max(mx,sum);

       for(int i=k-1;i>=0;i--)
       {
        sum-=cardPoints[i];
        sum+=cardPoints[j];
        mx=max(sum,mx);
        j--;
       }
       return mx;

    }
};
