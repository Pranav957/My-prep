class Solution {
public:
void swap(vector<int>& nums,int x,int y)
{
    int temp=nums[x];
    nums[x]=nums[y];
    nums[y]=temp;
}
    void sortColors(vector<int>& nums) {
       int zx=0,tw=nums.size()-1;
       int i=0;
       while(i<=tw)
       {
        if(nums[i]==0)
         {
            swap(nums,i,zx);
            zx++;
         }
         if(nums[i]==2)
          {
            swap(nums,i,tw);
            tw--;
          }
          else
           i++;
           
       }
    }
};
********************************************************************
void sortArray(vector<int>& arr, int n) {

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

}
**********************************************************
void sortArray(vector<int>& arr, int n) {    // 0 to low-1 0
                                             // low to mid-1; 1
    int low = 0, mid = 0, high = n - 1;      // high+1 to n-1: 2
                
    while (mid <= high) {                   // mid to high 0/1/2
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

