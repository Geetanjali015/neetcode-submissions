class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int l=-1,r=n;
        while(r-l>1){
            int mid=l+(r-l)/2;
            int pred=(nums[mid]>=target);//false=0,true =1
            if(pred==0) 
                l=mid; // m is still in the 0 region move forw
            else 
                r=mid; // m may be the first 1
        }
        int first=r; //the first 1(r) is ans

        if(first==n||nums[first]!=target) return {-1,-1};

        l=-1;r=n;
        while(r-l>1){
            int mid=l+(r-l)/2;
            int pred=(nums[mid]>target);
            if(pred==0) l=mid;
            else r=mid;

        }
        int last=l; //last 0 (l)

        return {first,last};
    }
};