class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
          int n = nums2.size();
        int total = m + n;
    
        vector<int> temp(total);
        int i = 0, j = 0, index = 0;

        while (i < m && j < n) {
           if (nums1[i] < nums2[j])
               temp[index++] = nums1[i++];
           else
             temp[index++] = nums2[j++];
        }

        while (i < m) temp[index++] = nums1[i++];
        while (j < n) temp[index++] = nums2[j++];

        if (total % 2 == 1)
            return temp[total / 2];  
        else
            return (temp[total / 2 - 1] + temp[total / 2]) / 2.0;  
    }
};