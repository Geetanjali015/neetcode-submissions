class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS=nums[0];
        int curS=nums[0];

        for(int i=1;i<nums.size();i++){
        curS=max(nums[i],nums[i]+curS);
        maxS=max(maxS,curS);
    }
    return maxS;
    }
};
