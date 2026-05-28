//2D
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,1e9));

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int coin=coins[i-1];

                if(coin<=j){
                    int take=1+dp[i][j-coin]; //+1->current coin, j-coin->remaining ammout(11-5)

                    int notTake=dp[i-1][j]; //move prev row

                    dp[i][j]=min(take,notTake);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
        }
     if (dp[n][amount] >= 1e9) return -1;
    return dp[n][amount];

    }
};