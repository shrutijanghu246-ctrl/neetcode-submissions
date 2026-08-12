class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int one = st.top();
                st.pop();
                int two = st.top();
                st.push(one);
                st.push(one + two);
            } else if(operations[i] == "D"){
                st.push(2 * st.top());
            } else if(operations[i] == "C"){
                st.pop();
            } else {
                st.push(stoi(operations[i]));
            }
        }

        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};