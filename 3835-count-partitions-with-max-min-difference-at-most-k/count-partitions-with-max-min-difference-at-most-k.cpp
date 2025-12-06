class Solution {
public:
    static const int MOD = 1'000'000'007;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1), pref(n + 1);
        dp[0] = pref[0] = 1;

        deque<int> maxD, minD;
        int left = 0;

        for (int i = 0; i < n; i++) {
            // Maintain maxD
            while (!maxD.empty() && nums[maxD.back()] <= nums[i]) {
                maxD.pop_back();
            }
            maxD.push_back(i);

            // Maintain minD
            while (!minD.empty() && nums[minD.back()] >= nums[i]) {
                minD.pop_back();
            }
            minD.push_back(i);

            // Shrink window until valid
            while (!maxD.empty() && !minD.empty() &&
                   nums[maxD.front()] - nums[minD.front()] > k) {
                if (maxD.front() == left) {
                    maxD.pop_front();
                }
                if (minD.front() == left) {
                    minD.pop_front();
                }
                left++;
            }

            // dp[i+1] = sum(dp[left] .. dp[i])
            long long sumRange = pref[i] - (left > 0 ? pref[left - 1] : 0);
            if (sumRange < 0) {
                sumRange += MOD;
            }

            dp[i + 1] = sumRange % MOD;
            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};