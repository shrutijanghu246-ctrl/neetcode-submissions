class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int n: nums){
            freq[n]++;
        }

        int majority = nums[0];
        int maxFreq = 0;

        for(auto& p: freq){
            if(p.second > maxFreq){
                maxFreq = p.second;
                majority = p.first;
            }
        }

        return majority;
    }
};