class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int ast:asteroids){
            while(!st.empty() && ast<0 && st.back()>0){ //left && right
                if(abs(ast)>st.back())
                    st.pop_back();

                else if(st.back()>abs(ast))
                    ast=0; 

                else{//same size both
                    st.pop_back();
                    ast=0;
                }     
            }   
        if(ast!=0){
            st.push_back(ast);
        }
    
        }
    return st;
    }
};
