class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {//sliding window
    int l=0,total=0;
    int res=INT_MAX;
    for(int r=0;r<nums.size();r++){
        total+=nums[r];
        while(total>=target){
            res=min(r-l+1,res);
            total-=nums[l];
            l++;
        }
    }
    
    return res==INT_MAX?0:res;
        
    }
};