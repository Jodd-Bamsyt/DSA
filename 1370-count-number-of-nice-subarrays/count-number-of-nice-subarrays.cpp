class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 

        int start = 0, end = 0;
        int count = 0, oddCount = 0;
        int n = nums.size();

        while (end < n) {
            if (nums[end] % 2 == 1) oddCount++;

            while (oddCount > goal) {
                if (nums[start] % 2 == 1) oddCount--;
                start++;
            }

            count += (end - start + 1);

            end++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
