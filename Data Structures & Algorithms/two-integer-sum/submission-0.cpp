class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(indexMap.find(complement) != indexMap.end()){
                int j = indexMap[complement];

                return {min(i, j), max(i, j)};
            }

            indexMap[nums[i]] = i; 
        }

        return {};
    }
};
