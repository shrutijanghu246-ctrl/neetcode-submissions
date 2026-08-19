class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> result;

        for(int num: nums){
            freq[num]++;
        }

        for(auto& p: freq){
            if(p.second > n/3)result.push_back(p.first);
        }

        return result;
    }
};