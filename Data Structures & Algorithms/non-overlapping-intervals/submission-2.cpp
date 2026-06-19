class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int remove = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Overlap
            if (start < lastEnd) {
                remove++;
            }
            // No overlap -> keep current interval
            else {
                lastEnd = end;
            }
        }

        return remove;
    }
};