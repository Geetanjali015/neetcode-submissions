class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
   for(int i=0;i<n;i++){
    while(!st.empty() && temperatures[i]>temperatures[st.top()]){
        int prev=st.top();//save top
        st.pop(); //then pop it
        result[prev]=i-prev;//use top
        
    }
    st.push(i);


   }
   return result;
   
}
};
