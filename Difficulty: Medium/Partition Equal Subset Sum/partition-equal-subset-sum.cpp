class Solution {
  public:
    bool helper(vector<int>& arr, int i, int sum, vector<vector<int>>& dp) {
        int n = arr.size(); 
        if (sum == 0) return true;
        if (i == n) return false;

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool notTake = helper(arr, i + 1, sum, dp);

        bool take = false;
        if (arr[i] <= sum) {
            take = helper(arr, i + 1, sum - arr[i], dp);
        }

        return dp[i][sum] = take || notTake;
    }

    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(arr, 0, target, dp);
    }
};
