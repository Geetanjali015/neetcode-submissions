class Solution {// intervals are sorted by start time
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int count=0;
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++){
            int currStart=intervals[i][0];
            if(currStart<prevEnd){//overlap
                count++;
                prevEnd=min(prevEnd,intervals[i][1]); //keep the one which ends earlier
            }
            else{
                prevEnd=intervals[i][1];
            }

        }
        return count;




        
    }
};