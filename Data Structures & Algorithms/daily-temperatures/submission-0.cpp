class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {//if warmer temp
            int prev = st.top();
            st.pop(); //pop lesser temp
            result[prev] = i - prev; //no.of days waited
        }
        st.push(i);
    }

    return result;
}
};
