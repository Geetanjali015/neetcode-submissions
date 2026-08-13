class Solution { //the highest frequency we have seen in the window as it grows (maxf), does not loop throughh every character c {A,B}, only the max one (A)
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int>mp;
       int ans=0;
       int l=0,mf=0;
       for(int r=0;r<s.size();r++){
        mp[s[r]]++;
        mf=max(mf,mp[s[r]]);
        while((r-l+1)-mf>k){
            mp[s[l]]--;
            l++;
        }
        ans=max(ans,r-l+1);
       }
       return ans;

        
    }
};
