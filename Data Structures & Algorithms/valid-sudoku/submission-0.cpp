class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> seen;
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    if(seen.count(c))return false;
                    seen.insert(c);
                }
            }
        }

        for(int j = 0; j < 9; j++){
            unordered_set<char> seen;
            for(int i = 0; i < 9; i++){
                char c = board[i][j];
                if(c != '.'){
                    if(seen.count(c))return false;
                    seen.insert(c);
                }
            }
        }

        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[row * 3 + i][col * 3 + j];
                        if (c != '.') {
                            if (seen.count(c)) return false;
                            seen.insert(c);
                        }
                    }
                }
            }
        }

        return true;
    }
};
