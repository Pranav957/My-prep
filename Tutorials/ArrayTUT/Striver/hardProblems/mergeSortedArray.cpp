class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int left=m-1;
       int right= 0;

       while(left>=0 && right<n)
       {
          if(nums1[left]>nums2[right])
           {
             int temp=nums1[left];
             nums1[left]=nums2[right];
             nums2[right]=temp;
             left--;
             right++;
           } 
           else
            break;
       }  
       sort(nums1.begin(),nums1.begin()+m);
       sort(nums2.begin(),nums2.end());
       for(int i=0;i<nums2.size();i++)
       {
         nums1[m]=nums2[i];
         m++; 
       }
    }
};
*********************************************************************************
void merge(long long arr1[], long long arr2[], int n, int m) {

    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}
