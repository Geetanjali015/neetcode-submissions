//Minimize the maximum subarray sum when partitioning into at most days contiguous parts
class Solution {
public:

    int pred(vector<int>& weights,int days,int capacity){
        int daysU=1;
        int curr=0;
        for(int w:weights){
            if(curr+w>capacity){
                daysU++;
                curr=0;
            }
            curr+=w;

        }
        return daysU<=days; //1 if ture 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end())-1;
        int r=accumulate(weights.begin(),weights.end(),0);
        while(r-l>1){
            int m=l+(r-l)/2; //m->capacity
            if(pred(weights,days,m)==0)
                l=m;
            else
                r=m;

        }
        return r;

    }
};