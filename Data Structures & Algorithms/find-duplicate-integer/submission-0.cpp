class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int num: nums){
            freq[num]++;
        }

        int dup;
        for(auto& p: freq){
            if(p.second > 1)dup = p.first;
        }

        return dup;
    }
};
