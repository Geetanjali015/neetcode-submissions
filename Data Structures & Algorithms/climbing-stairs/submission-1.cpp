class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

    /*int climbStairs(int n) {//recurssion
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i == n) return 1;
        if (i > n) return 0;

        return dfs(n, i + 1) + dfs(n, i + 2);
    }*/
