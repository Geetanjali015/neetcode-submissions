class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        int pos=0; //point to next even ind
        int neg=1; //odd index

        for(int x:nums){
            if(x>0){
                ans[pos]=x;
                pos+=2;

            }
            else{
                ans[neg]=x;
                neg+=2;
            }

        }
        return ans;
    }
};