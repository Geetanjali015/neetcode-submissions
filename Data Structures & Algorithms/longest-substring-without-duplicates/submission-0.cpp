class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>charS;
        int l=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            while(charS.find(s[r])!=charS.end()){
                charS.erase(s[l]);
                l++;
            }
            charS.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;

        
    }
};
