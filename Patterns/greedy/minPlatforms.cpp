  public:
    Function to find the minimum number of platforms required at the
    railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0,j=0;
        int platForm=0,mx=1;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])
            {
                platForm++;
                i++;
            }
            else
             {
                 platForm--;
                 j++;
             }
             mx=max(mx,platForm);
        }
        return mx;
        
    }
    int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    int maxPlatforms = 0;

    for (int i = 0; i < n; i++) {
        int currTime = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] <= currTime && dep[j] >= currTime) {
                count++;
            }
        }
        maxPlatforms = max(maxPlatforms, count);
    }
    return maxPlatforms;
}
