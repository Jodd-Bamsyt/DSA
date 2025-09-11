class Solution {
  public:
  
  
    int helper(string& s1, string& s2 , int i , int j , int n , int m , vector<char>&helperarray , vector<vector<int>>&dp){
        
        if(i == m && j == n){
            return 0;
        }
        
        if (i < m && j < n && s1[i] == s2[j]) {
            return helper(s1 , s2 , i + 1 , j + 1 , n , m , helperarray , dp);
        }
        
        if (i >= m) {
            return n - j;  // insert remaining chars
        }
        if (j >= n) {
            return m - i;  // delete remaining chars
        }
        
        if(dp[i][j] != 0){
            return dp[i][j];
        }

        int missing = 0;
        int remmove = 0;
        int replace = 0 ; 
        
        if(s1[i] != s2[j]){
            //missing
            
            missing = 1 + helper(s1 , s2 , i  , j + 1 ,  n , m , helperarray , dp);
            
            
           //remove
            remmove = 1 + helper(s1 , s2 , i + 1 , j , n , m , helperarray , dp);
            
            //replace

            replace = 1 +  helper(s1 , s2 , i + 1 , j + 1 , n , m , helperarray , dp);
            
        }
        
        
        return dp[i][j] =  min({missing, remmove, replace});

        
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        
        int n = s2.size() ; 
        int m = s1.size() ; 
        
        vector<vector<int>>dp(m + 1 , vector<int>(n + 1 ,  0));
        
        vector<char> helperarray;
        
        
        int i = 0 ; 
        int j = 0 ; 
        
        int count = 0;
        
        int ans = helper(s1 , s2 , i , j , n , m , helperarray , dp);
        
        return ans;
        // code here
        
    }
};