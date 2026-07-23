class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";
        for(char c: s){
            if(isalnum(c))word += tolower(c);
        }

        int i = 0; 
        int j = word.size() - 1;

        while(i < j){
            if(word[i] != word[j])return false;
            i++, j--;
        }

        return true;
    }
};
