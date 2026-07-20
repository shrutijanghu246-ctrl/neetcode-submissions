class Solution {
public:
    void merge(vector<int>& nums, int si, int ei, int mid){
        vector<int> ans;
        int i = si, j = mid+1;

        while(i <= mid && j <= ei){
            if(nums[i] <= nums[j]){
                ans.push_back(nums[i++]);
            }else{
                ans.push_back(nums[j++]);
            }
        }

        while(i <= mid){
            ans.push_back(nums[i++]);
        }

        while(j <= ei){
            ans.push_back(nums[j++]);
        }

        for(int k = si; k <= ei; k++){
            nums[k] = ans[k-si];
        }
    }

    void mergeSort(vector<int>& nums, int si, int ei){
        if(si >= ei)return;

        int mid = si + (ei-si)/2;
        mergeSort(nums, si, mid);
        mergeSort(nums, mid+1, ei);
        merge(nums, si, ei, mid);
    }
   
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1); 
        return nums;
    }
};