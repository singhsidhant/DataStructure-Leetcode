class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> suffix;
        unordered_map<int, int> prefix;
        for(auto x : nums) suffix[x] += 1;
        long long ans = 0;
        for(auto x : nums){
            suffix[x] -= 1;
            long long target = (long long)x * 2;
            if(target <= 2000000000) {
                ans = (ans + (long long)prefix[target] * suffix[target]) % mod;
            }
            prefix[x] += 1;
        }
        return (int)ans;
    }
};