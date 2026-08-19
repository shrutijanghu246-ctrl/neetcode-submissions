class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0, end = m * n - 1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int val = matrix[mid/m][mid % m];

            if(val == target)return true;
            else if(val < target)start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};
