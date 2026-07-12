class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string candidate = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < candidate.length() && j < strs[i].length() && candidate[j] == strs[i][j]){
                j++;
            }

            candidate = candidate.substr(0, j);
            if (candidate.empty()) return "";
        }

        return candidate;
    }
};