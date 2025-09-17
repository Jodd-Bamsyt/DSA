class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int i = 0;
        int j = 0;
        int curr = 0;
        int maxi = 0;
        int n = s.size();

        while (j < n) {
            if (mpp.find(s[j]) == mpp.end()) {
                mpp[s[j]] = 1;
                curr++;
                maxi = max(maxi, curr);
                j++;
            } else {
                while (s[i] != s[j]) {
                    mpp.erase(s[i]);
                    i++;
                    curr--;
                }
                mpp.erase(s[i]);
                i++;
                curr--;

            }
        }
        return maxi;
    }
};