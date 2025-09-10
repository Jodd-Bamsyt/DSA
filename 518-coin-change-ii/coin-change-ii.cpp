class Solution {
public:
    int helper(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        int n = coins.size();

        if (amount == 0) {
            return 1;
        }

        if (i >= n) {
            return 0;
        }

        if (dp[i][amount] != 0) {
            return dp[i][amount];
        }

        int notTake = helper(amount, coins, i + 1, dp);
        int Take = 0;
        if (coins[i] <= amount) {
            Take = helper(amount - coins[i], coins, i, dp);
        }
        return dp[i][amount] = (Take + notTake);
    }
    int change(int amount, vector<int>& coins) {
        int i = 0;
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < coins.size(); i++) {
            for (int amt = 1; amt <= amount; amt++) {

                long long notTake = dp[i - 1][amt];
                long long Take = 0;
                if (coins[i] <= amt) {
                    Take = dp[i][amt - coins[i]];
                }
                dp[i][amt] = (Take + notTake);
            }
        }
        // int ans =  helper(amount , coins , 0  , dp);
        return (int)dp[n - 1][amount];
    }
};