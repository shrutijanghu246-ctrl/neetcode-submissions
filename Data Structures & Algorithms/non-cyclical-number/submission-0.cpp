class Solution {
public:
    int getSumOfSquares(int n){
        int sum = 0;

        while(n > 0){
            int lastDig = n%10;
            n = n/10;

            sum += lastDig*lastDig;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!= 1 && !seen.count(n)){
            seen.insert(n);
            n = getSumOfSquares(n);
        }

        return n == 1;
        
    }
};
