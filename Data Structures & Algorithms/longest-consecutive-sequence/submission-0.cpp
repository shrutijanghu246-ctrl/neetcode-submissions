class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(), nums.end());

        int size = 1;
        int maxSize = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i]) continue;
            else if(nums[i] == nums[i - 1] + 1)size++;
            else {
                maxSize = max(maxSize, size);
                size = 1;
            };
        }

        return max(maxSize, size);
    }
};
