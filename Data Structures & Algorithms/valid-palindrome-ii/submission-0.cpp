class Solution {
public:
    bool helper(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else i++, j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j && i < s.size() && j > 0){
            if(s[i] != s[j]){
                return helper(s, i+1, j) || helper(s, i, j-1);
            }else{
                i++, j--;
            }
        }

        return true;
    }
};