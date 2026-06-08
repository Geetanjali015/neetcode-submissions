class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            while (!st.empty() && a < 0 && st.top() > 0) {

                if (abs(a) > st.top()) {
                    st.pop();          // top asteroid destroyed
                }
                else if (abs(a) < st.top()) {
                    a = 0;             // current asteroid destroyed
                }
                else {
                    st.pop();          // both destroyed
                    a = 0;
                }
            }

            if (a != 0) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};