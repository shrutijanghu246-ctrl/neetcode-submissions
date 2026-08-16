class Solution {
public:
    vector<int> mergeArrays(vector<int>&nums1, vector<int>&nums2){
        int n = nums1.size(), m = nums2.size();
        nums1.resize(n+m);
        int i = n-1, j = m-1, k = n+m-1;
        
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
               nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }

        while(i >= 0){
            nums1[k--] = nums1[i--];
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }

        return nums1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = mergeArrays(nums1, nums2);
        int s = merged.size();
        
        double median;
        if(s%2 == 0){
            median = (merged[s/2] + merged[s/2 - 1])/2.0;
        }else{
            median = merged[s/2];
        }

        return median;
    }
};
