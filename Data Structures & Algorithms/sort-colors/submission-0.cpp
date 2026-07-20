class Solution {
public:
    void merge(vector<int>&nums, int si, int ei, int mid){
        vector<int> ans;
        int i = si;
        int j = mid+1;

        while(i<=mid && j <= ei){
            if(nums[i] < nums[j]){
                ans.push_back(nums[i++]);
            }else {
                ans.push_back(nums[j++]);
            }
        }

        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }

        while(j <= ei){
            ans.push_back(nums[j]);
            j++;
        }

        for(int i =0; i<ans.size(); i++){
            nums[si + i] = ans[i];
        }
    }
   
    void mergeSort(vector<int>&nums, int si, int ei){
        if(si >= ei)return;

        int mid = si + (ei-si)/2;

        mergeSort(nums, si, mid);
        mergeSort(nums, mid+1, ei);

        merge(nums, si, ei, mid);
    }
    void sortColors(vector<int>& nums) {
        int si = 0;
        int ei = nums.size()-1;
        
        mergeSort(nums, 0, nums.size()-1);
    }
};