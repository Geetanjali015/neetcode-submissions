//1D
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0]=0;
        for(int coin:coins){
            for(int j=coin;j<=amount;j++){
                int take=1+dp[j-coin];
                int notTake=dp[j];
                dp[j]=min(take,notTake);
            }
        }
        if(dp[amount]==1e9)
            return -1;

        return dp[amount];
    }
};