class NumArray {
    vector<int> v;
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        v=nums;
        prefixSum.resize(nums.size());

          prefixSum[0]=v[0];

        for(int i=1;i<prefixSum.size();i++)
            prefixSum[i]=prefixSum[i-1]+v[i];  
    }
    
    void update(int index, int val) {

        int diff=val-v[index];
     
        if(index<v.size())
         v[index]=val;

         for(int i=index;i<prefixSum.size();i++)
            prefixSum[i]=prefixSum[i]+=diff;   
    }
    
    int sumRange(int left, int right) {
        if(left==0)
          return prefixSum[right];
        return prefixSum[right]-prefixSum[left-1];
    }
};
