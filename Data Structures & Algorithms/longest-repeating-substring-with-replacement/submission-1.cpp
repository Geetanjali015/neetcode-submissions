class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_set<char>charS(s.begin(),s.end());
        for(char c:charS){
            int cnt=0,l=0;
            for(int r=0;r<s.size();r++){
                if(s[r]==c)
                    cnt++;
                // c = character we want to make the entire window
                // cnt = number of c's in the current window
                // (window size - cnt) = characters that need to be replaced
                while ((r - l + 1) - cnt > k) {
                // More than k replacements are needed to make the window all 'c', so shrink it
               
                    if(s[l]==c)
                        cnt--;
                    l++;
                }
                ans=max(ans,r-l+1);
                
            }
            

        }
        return ans;
        
    }
};
