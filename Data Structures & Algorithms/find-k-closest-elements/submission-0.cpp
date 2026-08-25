class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int si = 0;
        int ei = arr.size() - 1;

        while(ei - si + 1 > k){
            if(abs(arr[si] - x) > abs(arr[ei] - x)){
                si++;
            }else{
                ei--;
            }
        }

        return vector<int>(arr.begin() + si, arr.begin() + ei + 1);
    }
};