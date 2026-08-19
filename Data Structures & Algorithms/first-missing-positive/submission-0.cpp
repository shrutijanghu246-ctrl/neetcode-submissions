class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int smallest = 1;

        for(int num: nums){
            if(num == smallest)smallest++;
        }

        return smallest;
    }
};