class Solution {
public:
    int findMin(vector<int> &nums) {
        int si = 0, ei = nums.size() - 1;

        while(si < ei){
            int mid = si + (ei - si)/2;

            if(nums[mid] > nums[ei]){
                si = mid + 1;
            }else{
                ei = mid;
            }
        }

        return nums[si];
    }
};
